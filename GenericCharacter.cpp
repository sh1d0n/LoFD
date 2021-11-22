#include <iostream>
#include <string>
#include <ctime>
#include "GenericCharacter.h"



bool chance(int needChance)
{
    srand(static_cast<unsigned int>(time(0)));
    int indexChance = (rand() % 100) + 1;
    return(indexChance <= needChance);
}

GenericCharacter::GenericCharacter(const int hpUp, const int fsl, const int ssl, const int tsl, const std::wstring name, int hp, int dp, int hpmax) :
    m_HealthPointsLevel(hpUp),
    m_FirstSkillLevel(fsl),
    m_SecondSkillLevel(ssl),
    m_ThirdSkillLevel(tsl),
    m_ClassName(name),
    m_HealthPoints(hp),
    m_DefendPoints(dp),
    m_HealthPointsMax(hpmax)
{}

int GenericCharacter::HealthPointsLevelUp()
{
    m_HealthPoints += 20;
    return(m_HealthPointsLevel++);
}

int GenericCharacter::FirstSkillLevelUp()
{
    return(m_FirstSkillLevel++);
}

int GenericCharacter::SecondSkillLevelUp()
{
    return(m_SecondSkillLevel++);
}

int GenericCharacter::ThirdSkillLevelUp()
{
    return(m_ThirdSkillLevel++);
}

int GenericCharacter::GetHealthPointsLevel() const
{
    return(m_HealthPointsLevel);
}

int GenericCharacter::GetFirstSkillLevel() const
{
    return(m_FirstSkillLevel);
}

int GenericCharacter::GetSecondSkillLevel() const
{
    return(m_SecondSkillLevel);
}

int GenericCharacter::GetThirdSkillLevel() const
{
    return(m_ThirdSkillLevel);
}

int GenericCharacter::GetPhysicalDamage() const
{
    return(m_PhysicalDamage);
}

int GenericCharacter::GetMagicalDamage() const
{
    return(m_MagicalDamage);
}

int GenericCharacter::GetThirdSkillReady() const
{
    return(m_ThirdSkillReady);
}

int GenericCharacter::GetHealthPoints()
{
    if (m_HealthPoints < 0)
    {
        m_HealthPoints = 0;
    }
    return(m_HealthPoints);
}

int GenericCharacter::GetDefendPoints()
{
    if (m_DefendPoints < 0)
    {
        m_DefendPoints = 0;
    }
    return(m_DefendPoints);
}

int GenericCharacter::GetFullHP()
{
    m_FullHP = m_HealthPointsMax;
    for (int i = 1; i < m_HealthPointsLevel; i++)
    {
        m_FullHP += 20;
    }

    return(m_FullHP);
}

std::wstring GenericCharacter::GetName() const
{
    return(m_ClassName);
}

void GenericCharacter::MinusHP(int damage)
{
    m_HealthPoints -= damage;
}

void GenericCharacter::MinusDefend(int damage)
{
    m_DefendPoints -= damage;
}

bool GenericCharacter::IsDie()
{
    if (m_HealthPoints == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


Knight::Knight(const int hpUp, const int fsl, const int ssl, const int tsl, const std::wstring name, int hp, int dp, int hpmax) :
    GenericCharacter(hpUp, fsl, ssl, tsl, name, hp, dp, hpmax)
{}

std::wstring Knight::GetFirstSkillName() const
{
    return(L"Слабый удар мечем");
}

std::wstring Knight::GetSecondSkillName() const
{
    return(L"Блокирование щитом");
}

std::wstring Knight::GetThirdSkillName() const
{
    return(L"Контр удар");
}

void Knight::TakeDamage(int physicalDamage, int magicalDamage)
{
    int damage = 0;
    if (IsSecondSkill)
    {
        if (GetSecondSkillLevel() == 1)
        {
            if (magicalDamage == 0)
            {
                damage = physicalDamage * 0.25;
                MinusHP(damage);
            }
            else
            {
                damage = magicalDamage * 0.5;
                MinusHP(damage);
            }
        }
        else
        {
            if (magicalDamage == 0)
            {
                MinusHP(damage);
            }
            else
            {
                damage = magicalDamage * 0.25;
                MinusHP(damage);
            }
        }
        IsSecondSkill = false;
    }
    else
    {
        if (m_DefendPoints != 0)
        {
            if (magicalDamage == 0)
            {
                damage = physicalDamage * 0.5;
                MinusDefend(damage);
                MinusHP(damage);
            }
            else
            {
                MinusHP(magicalDamage);
            }
        }
        else
        {
            MinusHP(physicalDamage);
            MinusHP(magicalDamage);
        }
    }
}

void Knight::FirstSkill()
{
    if (chance(10))
    {
        m_PhysicalDamage = 15 * m_FirstSkillLevel * 2;
    }
    else
    {
        m_PhysicalDamage = 15 * m_FirstSkillLevel;
    }
}

void Knight::SecondSkill()
{
    m_PhysicalDamage = 0;
    IsSecondSkill = true;
    m_ThirdSkillReady++;
}

void Knight::ThirdSkill()
{
    m_ThirdSkillReady = 0;
    if (chance(10))
    {
        m_PhysicalDamage = 25 * m_ThirdSkillLevel * 2;
    }
    else
    {
        m_PhysicalDamage = 25 * m_ThirdSkillLevel;
    }
}


Withard::Withard(const int hpUp, const int fsl, const int ssl, const int tsl, std::wstring name, int hp, int dp, int hpmax) :
    GenericCharacter(hpUp, fsl, ssl, tsl, name, hp, dp, hpmax)
{}

std::wstring Withard::GetFirstSkillName() const
{
    return(L"Огненый шар");
}

std::wstring Withard::GetSecondSkillName() const
{
    return(L"Восстановление");
}

std::wstring Withard::GetThirdSkillName() const
{
    return(L"Дыхание огня");
}

void Withard::TakeDamage(int physicalDamage, int magicalDamage)
{
    int damage = 0;
    if (m_DefendPoints != 0)
    {
        if (magicalDamage == 0)
        {
            damage = physicalDamage * 0.5;
            MinusHP(damage);
            MinusDefend(damage);
        }
        else
        {
            damage = magicalDamage * 0.25;
            MinusDefend(damage);
            damage = magicalDamage - damage;
            MinusHP(damage);
        }
    }
    else
    {
        MinusHP(physicalDamage);
        MinusHP(magicalDamage);
    }
}

void Withard::FirstSkill()
{
    if (chance(30))
    {
        m_MagicalDamage = 10 * m_FirstSkillLevel + 10 * m_FirstSkillLevel * 0.5;
    }
    else
    {
        m_MagicalDamage = 10 * m_FirstSkillLevel;
    }
    m_ThirdSkillReady++;
}

void Withard::SecondSkill()
{
    m_MagicalDamage = 0;

    if (GetSecondSkillLevel() == 1)
    {
        m_HealthPoints = m_HealthPoints + GetFullHP() * 0.2;
    }
    else
    {
        m_HealthPoints = m_HealthPoints + GetFullHP() * 0.4;
    }
}

void Withard::ThirdSkill()
{
    m_ThirdSkillReady = 0;
    if (chance(30))
    {
        m_MagicalDamage = 20 * m_ThirdSkillLevel + 20 * m_ThirdSkillLevel * 0.5;
    }
    else
    {
        m_MagicalDamage = 20 * m_ThirdSkillLevel;
    }
}


Assasin::Assasin(const int hpUp, const int fsl, const int ssl, const int tsl, const std::wstring name, int hp, int dp, int hpmax) :
    GenericCharacter(hpUp, fsl, ssl, tsl, name, hp, dp, hpmax)
{}

std::wstring Assasin::GetFirstSkillName() const
{
    return(L"Удар кинжалом");
}

std::wstring Assasin::GetSecondSkillName() const
{
    return(L"Исчезновение");
}

std::wstring Assasin::GetThirdSkillName() const
{
    return(L"Отравленный клинок");
}

void Assasin::TakeDamage(int physicalDamage, int magicalDamage)
{
    int damage = 0;
    if (IsSecondSkill)
    {
        if (chance(10 * m_SecondSkillLevel + 20))
        {
            MinusHP(damage);
            m_ThirdSkillReady++;
        }
        else
        {
            if (physicalDamage != 0 || magicalDamage != 0)
            {
                MinusHP(physicalDamage);
                MinusHP(magicalDamage);
                m_ThirdSkillReady = 0;
            }
        }
    }
    else
    {
        if (chance(10 * m_SecondSkillLevel))
        {
            MinusHP(damage);
            m_ThirdSkillReady++;
        }
        else
        {
            if (physicalDamage != 0 || magicalDamage != 0)
            {
                MinusHP(physicalDamage);
                MinusHP(magicalDamage);
                m_ThirdSkillReady = 0;
            }
        }
    }
}

void Assasin::FirstSkill()
{
    if (IsThirdSkill > 0)
    {
        if (m_ThirdSkillReady != 0)
        {
            m_PhysicalDamage = 15 * m_FirstSkillLevel + 5 * m_ThirdSkillLevel;
        }
        else
        {
            m_PhysicalDamage = 5 * m_FirstSkillLevel + 5 * m_ThirdSkillLevel;
        }
        IsThirdSkill--;
    }
    else
    {
        if (m_ThirdSkillReady != 0)
        {
            m_PhysicalDamage = 15 * m_FirstSkillLevel;
        }
        else
        {
            m_PhysicalDamage = 5 * m_FirstSkillLevel;
        }
    }
}

void Assasin::SecondSkill()
{
    m_PhysicalDamage = 0;
    IsSecondSkill = true;
    if (IsThirdSkill > 0)
    {
        m_PhysicalDamage = 5 * m_ThirdSkillLevel;
        IsThirdSkill--;
    }
}

void Assasin::ThirdSkill()
{
    m_ThirdSkillReady = 0;
    m_PhysicalDamage = 5 * m_ThirdSkillLevel;
    IsThirdSkill = 3;
}