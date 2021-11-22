#include <iostream>
#include <string>
#include "GenericCharacter.h"
#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const std::wstring& name) :
    m_Name(name)
{}

std::wstring GenericPlayer::GetName() const
{
    return(m_Name);
}

std::wstring GenericPlayer::GetCharacterName() const
{
    return(m_Character->GetName());
}

std::wstring GenericPlayer::GetFirstSkillName() const
{
    return(m_Character->GetFirstSkillName());
}

std::wstring GenericPlayer::GetSecondSkillName() const
{
    return(m_Character->GetSecondSkillName());
}

std::wstring GenericPlayer::GetThirdSkillName() const
{
    return(m_Character->GetThirdSkillName());
}

int GenericPlayer::GetHealthPointsLevel() const
{
    return(m_Character->GetHealthPointsLevel());
}

int GenericPlayer::GetFirstSkillLevel() const
{
    return(m_Character->GetFirstSkillLevel());
}

int GenericPlayer::GetSecondSkillLevel() const
{
    return(m_Character->GetSecondSkillLevel());
}

int GenericPlayer::GetThirdSkillLevel() const
{
    return(m_Character->GetThirdSkillLevel());
}

int GenericPlayer::GetExpNum() const
{
    return(numExp);
}

int GenericPlayer::GetHealthPoints() const
{
    return(m_Character->GetHealthPoints());
}

int GenericPlayer::GetDefendPoints() const
{
    return(m_Character->GetDefendPoints());
}

int GenericPlayer::GetPhysicalDamage() const
{
    return(m_Character->GetPhysicalDamage());
}

int GenericPlayer::GetMagicalDamage() const
{
    return(m_Character->GetMagicalDamage());
}

int GenericPlayer::GetThirdSkillReady() const
{
    return(m_Character->GetThirdSkillReady());
}

int GenericPlayer::GetFullHP()
{
    return(m_Character->GetFullHP());
}

void GenericPlayer::HpUp() const
{
    m_Character->HealthPointsLevelUp();
}

void GenericPlayer::FslUp() const
{
    m_Character->FirstSkillLevelUp();
}

void GenericPlayer::SslUp() const
{
    m_Character->SecondSkillLevelUp();
}

void GenericPlayer::TslUp() const
{
    m_Character->ThirdSkillLevelUp();
}

void GenericPlayer::FirstSkill()
{
    m_Character->FirstSkill();
}

void GenericPlayer::SecondSkill()
{
    m_Character->SecondSkill();
}

void GenericPlayer::ThirdSkill()
{
    m_Character->ThirdSkill();
}

int GenericPlayer::MinusExpNum()
{
    return(--numExp);
}

void GenericPlayer::PlusNumExp(int plusExp)
{
    numExp += plusExp;
}

void GenericPlayer::TakeDamage(int physicalDamage, int magicalDamage)
{
    m_Character->TakeDamage(physicalDamage, magicalDamage);
}

void GenericPlayer::SetCharacter(GenericCharacter* c)
{
    m_Character = c;
}

bool GenericPlayer::Dead()
{
    if (m_Character->IsDie())
    {
        return true;
    }
    else
    {
        return false;
    }
}


Player::Player(const std::wstring& name) :
    GenericPlayer(name)
{}

std::wstring Player::GetPlayer() const
{
    return(L"Player");
}


Computer::Computer(const std::wstring& name) :
    GenericPlayer(name)
{}

std::wstring Computer::GetPlayer() const
{
    return(L"Computer");
}