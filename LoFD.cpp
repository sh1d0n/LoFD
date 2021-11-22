#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <thread>
#include "GenericCharacter.h"
#include "GenericPlayer.h"


using namespace std::chrono_literals;

void mainMenu();
void soon();


class Game
{
    public:
        void Play();
        void ChoiceFirstPlayer();
        void ChoiceSecondPlayer();
        void CharactersInfo(GenericPlayer* aPlayer);
        void ChoiceCharacter(GenericPlayer* aPlayer);
        void KnightToPlayer(GenericPlayer* aPlayer);
        void WithardToPlayer(GenericPlayer* aPlayer);
        void AssasinToPlayer(GenericPlayer* aPlayer);
        void UpSkillsLevel(GenericPlayer* aPlayer);
        void Match(GenericPlayer* p1, GenericPlayer* p2);
        void GameInfo(GenericPlayer* p1, GenericPlayer* p2);
        void PlayerMove(GenericPlayer* aCurrentPlayer, GenericPlayer* aOtherPlayer);
    protected:
        GenericPlayer* m_FirstPlayer;
        GenericPlayer* m_SecondPlayer;
};

void Game::CharactersInfo(GenericPlayer* aPlayer)
{
    system("cls");

    std::wcout << L"\t\t\tРыцарь\n\nHP - 250, можно увеличивать без ограничений, с каждым уровнем прибвляется 20 очков\nPDP(Physical Defend Points) - 100(50% физического урона будут проходить по броне, а остальные 50% по HP)\n";
    std::wcout << L"У рыцаря есть 10% шанс нанести крит урон\n-Первый навык - слабый удар мечем, 15DMG, зависит от уровня навыка, \nна максимальном уровне наносит 75DMG\n";
    std::wcout << L"-Второй навык - блокирование щитом, щит поглащает 75% физического урона и 50% магического урона, \nна максимальном уровне поглощает 100% физического урона и 75% магичкеского\n";
    std::wcout << L"-Третий навык - контр удар, наносит 25DMG, на максимальном уровне наносит 100DMG,\nрыцарь может использовать этот навык только после 3-х блокирующих способностей\n\n\n";

    std::wcout << L"\t\t\tМаг\n\nHP - 175, можно увеличивать без ограничений, с каждым уровнем прибвляется 20 очков\nMDP(Magical Defend Points) - 100(у мага есть барьер, который получает 75% магического урона и 50% физического, \nостальной дамаг проходит по магу)\n";
    std::wcout << L"У мага есть есть шанс 30% нанести следующей атакой на 50% больше урона\n-Первый навык - огненный шар, наносит 10DMG, на максимальном уровне наносит 50 DMG\n";
    std::wcout << L"-Второй навык - восстановление, восстанавливает магу 20% HP,\nможно использовать только тогда, когда у мага меньше 50% HP, \nна максимальном уровне восстанавливает 40% HP\n";
    std::wcout << L"-Третий навык - дыхание огня, наносит 20DMG,\nиспользовав 3 раза огненный шар, магическая сила мага пропиталась волей духа огня,\nпоэтому маг высвобождает ее более сильной атакой, дыханием огня, \nна максимальном уровне наносит 80DMG\n\n\n";

    std::wcout << L"\t\t\tУбийца\n\nHP - 210, можно увеличивать без ограничений, с каждым уровнем прибвляется 20 очков\nУбийца имеет шанс 10% уклониться от следующей атаки, \nшанс уклониться зависит от уровня третьего навыка\n";
    std::wcout << L"Если убийца выиграл матч, то он получает на 2 очка навыков больше\n-Первый навык - удар кинжалом, наносит 5DMG, если была использована после уклонения,\nто убийца нанесет 15DMG, \nна максимальном уровне наносит 25DMG или 75DMG\n";
    std::wcout << L"-Второй навык - исчезновение, на 20% увеличивает шанс уклониться от следующей атаки, \nпри улучшении увеличивает пассивный навык уклонения\n";
    std::wcout << L"-Третий навык - отравленный клинок, после трех уклонений подряд, может отравить оппонента,\nяд наносит 5DMG в начале каждого хода, на максимальном уровне наносит 20DMG\n\n\n";

    std::wcout << L"1. Назад";
    int choice = 0;

    while (choice != 1)
    {
        std::wcout << L"\n\nВвод: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                ChoiceCharacter(aPlayer);
                break;
            default:
                std::wcout << L"\n\nТакого варианта нет!";
        }
    }
}

void Game::GameInfo(GenericPlayer* p1, GenericPlayer* p2)
{
    int percentFirstPlayerHP = (p1->GetHealthPoints() * 100) / p1->GetFullHP();
    int percentSecondPlayerHP = (p2->GetHealthPoints() * 100) / p2->GetFullHP();

    system("cls");
    std::wcout << std::left << std::setw(14) << L"Первый игрок: " << std::left << std::setw(6) << p1->GetCharacterName() << std::left << std::setw(3) << L" - " << std::left << std::setw(37) << p1->GetName() << L"Второй игрок: " << p2->GetCharacterName() << L" - " << p2->GetName() << std::endl;
    std::wcout << std::left << std::setw(4) << L"HP: " << std::left << std::setw(3) << p1->GetHealthPoints() << std::left << std::setw(2) << L" (" << std::left << std::setw(3) << percentFirstPlayerHP << std::left << std::setw(3) << L"%) " << std::left << std::setw(5) << L" DP: " << std::left << std::setw(40) << p1->GetDefendPoints() << L"HP: " << p2->GetHealthPoints() << L" (" << std::left << std::setw(3) << percentSecondPlayerHP << L"%) " << L" DP: " << p2->GetDefendPoints() << std::endl;
    std::wcout << std::left << std::setw(3) << L"1. " << std::left << std::setw(57) << p1->GetFirstSkillName() << L"1. " << p2->GetFirstSkillName() << std::endl;
    std::wcout << std::left << std::setw(3) << L"2. " << std::left << std::setw(57) << p1->GetSecondSkillName() << L"2. " << p2->GetSecondSkillName() << std::endl;
    std::wcout << std::left << std::setw(3) << L"3. " << std::left << std::setw(18) << p1->GetThirdSkillName() << std::left << std::setw(2) << L" (" << std::left << std::setw(1) << p1->GetThirdSkillReady() << std::left << std::setw(36) << L"/3)" << L"3. " << std::left << std::setw(18) << p2->GetThirdSkillName() << L" (" << p2->GetThirdSkillReady() << L"/3)" << std::endl;

}

void Game::PlayerMove(GenericPlayer* aCurrentPlayer, GenericPlayer* aOtherPlayer)
{
    int pastHP = aOtherPlayer->GetHealthPoints();
    std::wcout << L"\n\n\t\t\t\t\tХодит " << aCurrentPlayer->GetName() << L"\n";
    int choice = 0;
    while (choice != 1 && choice != 2 && choice != 3)
    {
        std::wcout << L"\t\t\t\t\tВвод: ";

        if (aCurrentPlayer->GetPlayer() == L"Player")
        {
            std::cin >> choice;
        }
        else
        {
            choice = (rand() % 3) + 1;
            std::cout << choice;
        }

        switch (choice)
        {
        case 1:
            aCurrentPlayer->FirstSkill();
            std::wcout << "\n\t\t\t\t" << aCurrentPlayer->GetName() << L" выбрал " << aCurrentPlayer->GetFirstSkillName();
            break;
        case 2:
            if (aCurrentPlayer->GetCharacterName() == L"Маг")
            {
                int needHP = aCurrentPlayer->GetFullHP() / 2;

                if (needHP >= aCurrentPlayer->GetHealthPoints())
                {
                    aCurrentPlayer->SecondSkill();
                    std::wcout << "\n\t\t\t\t" << aCurrentPlayer->GetName() << L" выбрал " << aCurrentPlayer->GetSecondSkillName();
                }
                else
                {
                    std::wcout << L"\n\t\t\tУ вас должно быть меньше половины хп\n\n";
                    choice = 0;
                }
            }
            else
            {
                aCurrentPlayer->SecondSkill();
                std::wcout << "\n\t\t\t\t" << aCurrentPlayer->GetName() << L" выбрал " << aCurrentPlayer->GetSecondSkillName();
            }
            break;
        case 3:
            if (aCurrentPlayer->GetThirdSkillReady() >= 3)
            {
                aCurrentPlayer->ThirdSkill();
                std::wcout << "\n\t\t\t\t" << aCurrentPlayer->GetName() << L" выбрал " << aCurrentPlayer->GetThirdSkillName();
            }
            else
            {
                std::wcout << L"\n\n\t\t\t\tНавык еще не готов!\n\n";
                choice = 0;
            }
            break;
        default:
            std::wcout << L"\n\n\t\t\t\tТакого варианта нет!\n\n";
            break;
        }
    }
    aOtherPlayer->TakeDamage(aCurrentPlayer->GetPhysicalDamage(), aCurrentPlayer->GetMagicalDamage());

    int currentHP = aOtherPlayer->GetHealthPoints();
    int damage = pastHP - currentHP;
    std::wcout << L"\n\t\t\t\t  Нанесено " << damage << L" урона";

    std::this_thread::sleep_for(2000ms);
}

void Game::KnightToPlayer(GenericPlayer* aPlayer)
{
    GenericCharacter* m_Knight = new Knight;
    aPlayer->SetCharacter(m_Knight);
}

void Game::WithardToPlayer(GenericPlayer* aPlayer)
{
    GenericCharacter* m_Withard = new Withard;
    aPlayer->SetCharacter(m_Withard);
}

void Game::AssasinToPlayer(GenericPlayer* aPlayer)
{
    GenericCharacter* m_Assasin = new Assasin;
    aPlayer->SetCharacter(m_Assasin);
}

void Game::ChoiceCharacter(GenericPlayer* aPlayer)
{
    system("cls");

    if (aPlayer->GetPlayer() == L"Player")
    {
        std::wcout << aPlayer->GetName() << L" выбирает персонажа!!\n\n";
        std::wcout << L"1. Рыцарь\n2. Маг\n3. Убийца\n4. Информация о персонажах\n5. Меню\n";

        int choice = 0;

        while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
        {
            std::wcout << L"\nВвод: ";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                KnightToPlayer(aPlayer);
                break;
            case 2:
                WithardToPlayer(aPlayer);
                break;
            case 3:
                AssasinToPlayer(aPlayer);
                break;
            case 4:
                CharactersInfo(aPlayer);
                break;
            case 5:
                mainMenu();
                break;
            default:
                std::wcout << L"\n\nТакого варианта нет!\n";
            }
        }
    }
    else
    {
        int randomChoice = (rand() % 3) + 1;

        switch (randomChoice)
        {
            case 1:
                KnightToPlayer(aPlayer);
                break;
            case 2:
                WithardToPlayer(aPlayer);
                break;
            case 3:
                AssasinToPlayer(aPlayer);
                break;
            default:
                std::wcout << L"\n\nТакого варианта нет!\n\n";
        }
    }
}

void Game::UpSkillsLevel(GenericPlayer* aPlayer)
{
    if (aPlayer->GetPlayer() == L"Player")
    {

        while (aPlayer->GetExpNum() != 0)
        {
            system("cls");

            std::wcout << aPlayer->GetName() << L" играет за '" << aPlayer->GetCharacterName() << L"'\n\n";
            std::wcout << L"Выберите что вы хотите прокачать: \t\t\t\tВаши очки навыков: " << aPlayer->GetExpNum() << std::endl;
            std::wcout << L"1. HP - " << aPlayer->GetHealthPointsLevel() << L"  (увеличивает HP на 20 за каждое улучшение)" << std::endl;
            if (aPlayer->GetFirstSkillLevel() == 5)
            {
                std::wcout << L"2. Первый навык - " << aPlayer->GetFirstSkillLevel() << L"\tMAX" << std::endl;
            }
            else
            {
                std::wcout << L"2. Первый навык - " << aPlayer->GetFirstSkillLevel() << L"  (умножает DMG на уровень навыка)" << std::endl;
            }
            if (aPlayer->GetSecondSkillLevel() == 2)
            {
                std::wcout << L"3. Второй навык - " << aPlayer->GetSecondSkillLevel() << L"\tMAX" << std::endl;
            }
            else
            {
                std::wcout << L"3. Второй навык - " << aPlayer->GetSecondSkillLevel() << std::endl;
            }
            if (aPlayer->GetThirdSkillLevel() == 4)
            {
                std::wcout << L"4. Третий навык - " << aPlayer->GetThirdSkillLevel() << L"\tMAX";
            }
            else
            {
                std::wcout << L"4. Третий навык - " << aPlayer->GetThirdSkillLevel() << L"  (умножает DMG на уровень навыка)";
            }
            int choice = 0;

            while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
            {
                std::wcout << L"\n\nВвод: ";
                std::cin >> choice;
                switch (choice)
                {
                case 1:
                    aPlayer->HpUp();
                    aPlayer->MinusExpNum();
                    break;
                case 2:
                    if (aPlayer->GetFirstSkillLevel() == 5)
                    {
                        std::wcout << L"\nДанный навык достиг максимального уровня!!!\n";
                    }
                    else
                    {
                        aPlayer->FslUp();
                        aPlayer->MinusExpNum();
                    }
                    break;
                case 3:
                    if (aPlayer->GetSecondSkillLevel() == 2)
                    {
                        std::wcout << L"\nДанный навык достиг максимального уровня!!!\n";
                    }
                    else
                    {
                        aPlayer->SslUp();
                        aPlayer->MinusExpNum();
                    }
                    break;
                case 4:
                    if (aPlayer->GetThirdSkillLevel() == 4)
                    {
                        std::wcout << L"\nДанный навык достиг максимального уровня!!!\n";
                    }
                    else
                    {
                        aPlayer->TslUp();
                        aPlayer->MinusExpNum();
                    }
                    break;
                default:
                    std::wcout << L"\nТакого варианта нет!\n";
                    break;
                }
            }
        }
    }
    else
    {
        system("cls");

        while (aPlayer->GetExpNum() != 0)
        {
            int randomChoice = (rand() % 4) + 1;
            switch (randomChoice)
            {
                case 1:
                    aPlayer->HpUp();
                    aPlayer->MinusExpNum();
                    break;
                case 2:
                    if (aPlayer->GetFirstSkillLevel() == 5)
                    {

                    }
                    else
                    {
                        aPlayer->FslUp();
                        aPlayer->MinusExpNum();
                    }
                    break;
                case 3:
                    if (aPlayer->GetSecondSkillLevel() == 2)
                    {

                    }
                    else
                    {
                        aPlayer->SslUp();
                        aPlayer->MinusExpNum();
                    }
                    break;
                case 4:
                    if (aPlayer->GetThirdSkillLevel() == 4)
                    {

                    }
                    else
                    {
                        aPlayer->TslUp();
                        aPlayer->MinusExpNum();
                    }
                    break;
                default:
                    break;
            }
        }
    }

    system("cls");

    std::wcout << aPlayer->GetName() << L" играет за '" << aPlayer->GetCharacterName() << L"'\n\n";
    std::wcout << L"Выберите что вы хотите прокачать: \t\t\t\tВаши очки навыков: " << aPlayer->GetExpNum() << std::endl;
    std::wcout << L"1. HP - " << aPlayer->GetHealthPointsLevel() << L"  (увеличивает HP на 20 за каждое улучшение)" << std::endl;
    if (aPlayer->GetFirstSkillLevel() == 5)
    {
        std::wcout << L"2. Первый навык - " << aPlayer->GetFirstSkillLevel() << L"\tMAX" << std::endl;
    }
    else
    {
        std::wcout << L"2. Первый навык - " << aPlayer->GetFirstSkillLevel() << L"  (умножает DMG на уровень навыка)" << std::endl;
    }
    if (aPlayer->GetSecondSkillLevel() == 2)
    {
        std::wcout << L"3. Второй навык - " << aPlayer->GetSecondSkillLevel() << L"\tMAX" << std::endl;
    }
    else
    {
        std::wcout << L"3. Второй навык - " << aPlayer->GetSecondSkillLevel() << std::endl;
    }
    if (aPlayer->GetThirdSkillLevel() == 4)
    {
        std::wcout << L"4. Третий навык - " << aPlayer->GetThirdSkillLevel() << L"\tMAX";
    }
    else
    {
        std::wcout << L"4. Третий навык - " << aPlayer->GetThirdSkillLevel() << L"  (умножает DMG на уровень навыка)";
    }

    std::this_thread::sleep_for(5000ms);
}

void Game::ChoiceFirstPlayer()
{
    system("cls");

    std::wcout << L"Выберите первого игрока:\n\n";
    std::wcout << L"1. Игрок\n2. Компьютер";

    std::wstring name;

    int choice = 0;
    while (choice != 1 && choice != 2)
    {
        std::wcout << L"\n\nВвод: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            std::wcout << L"Придумайте имя игроку: ";
            std::wcin >> name;
            m_FirstPlayer = new Player(name);
            break;
        case 2:
            system("cls");
            std::wcout << L"Придумайте имя компьютеру: ";
            std::wcin >> name;
            m_FirstPlayer = new Computer(name);
            break;
        default:
            std::wcout << L"\n\nТакого варианта нет!";
            break;
        }
    }
}

void Game::ChoiceSecondPlayer()
{
    system("cls");

    std::wcout << L"Выберите второго игрока:\n\n";
    std::wcout << L"1. Игрок\n2. Компьютер";

    std::wstring name;

    int choice = 0;
    while (choice != 1 && choice != 2)
    {
        std::wcout << L"\n\nВвод: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            std::wcout << L"Придумайте имя игроку: ";
            std::wcin >> name;
            m_SecondPlayer = new Player(name);
            break;
        case 2:
            system("cls");
            std::wcout << L"Придумайте имя компьютеру: ";
            std::wcin >> name;
            m_SecondPlayer = new Computer(name);
            break;
        default:
            std::wcout << L"\n\nТакого варианта нет!";
            break;
        }
    }
}

void Game::Match(GenericPlayer* p1, GenericPlayer* p2)
{
    bool matchEnded = false;

    GameInfo(p1, p2);

    while (!matchEnded)
    {
        PlayerMove(p1, p2);

        GameInfo(p1, p2);
        
        if (p2->Dead())
        {
            matchEnded = true;
            std::wcout << "\n\n\t\t\t\t\t" << p1->GetName() << L" выиграл(-a) рануд\n";
        }
        else
        {
            PlayerMove(p2, p1);

            GameInfo(p1, p2);

            if (p1->Dead())
            {
                matchEnded = true;
                std::wcout << "\n\n\t\t\t\t\t" << p2->GetName() << L" выиграл(-a) рануд\n";
            }
        }
    }
    std::this_thread::sleep_for(2000ms);
}

void Game::Play()
{
    ChoiceFirstPlayer();

    ChoiceCharacter(m_FirstPlayer);
    
    UpSkillsLevel(m_FirstPlayer);
    
    ChoiceSecondPlayer();

    ChoiceCharacter(m_SecondPlayer);

    UpSkillsLevel(m_SecondPlayer);

    system("cls");
    std::wcout << L"1. В бой\n2. Главное меню\n\n";

    int choice = 0;
    while (choice != 1 && choice != 2)
    {
        std::wcout << L"Ввод: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                Match(m_FirstPlayer, m_SecondPlayer);
                break;
            case 2:
                mainMenu();
                break;
            default:
                std::wcout << L"\nТакого варианта нет!\n\n";
        }
    }
}


void mainMenu()
{
    system("cls");
    Game aGame;

    std::wcout << L"\t\t\t|---Добро пожаловать в Low Fight Duel---|\n\n";

    std::wcout << L"1. Играть\n2. Выход\n\n";
    int choice = 0;

    while (choice != 1 && choice != 2)
    {
        std::wcout << L"Ввод: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            aGame.Play();
            break;
        case 2:
            exit(0);
            break;
        default:
            std::wcout << L"Такого пункта нет!\n\n";
            break;
        }
    }
}

void soon()
{
    system("cls");
    std::wcout << L"В разработке!\n";
    std::wcout << L"Введите 0, чтобы выйти в главное меню!\n";
    int choice1 = 1;
    while (choice1 != 0)
    {
        std::wcout << L"Ввод: ";
        std::cin >> choice1;

        switch (choice1)
        {
        case 0:
            mainMenu();
            break;
        default:
            std::wcout << L"Такого варианта нет!\n\n";
            break;
        }
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    setlocale(LC_ALL, "Russian");

    mainMenu();
}