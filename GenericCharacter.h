#pragma once
bool chance(int needChance);

class GenericCharacter
{
    public:
        GenericCharacter(const int hpUp = 1, const int fsl = 1, const int ssl = 1, const int tsl = 1, const std::wstring name = L"", int hp = 175, int dp = 0, int hpmax = 0);
        virtual std::wstring GetFirstSkillName() const = 0;
        virtual std::wstring GetSecondSkillName() const = 0;
        virtual std::wstring GetThirdSkillName() const = 0;
        virtual void TakeDamage(int physicalDamage, int magicalDamage) = 0;
        virtual void FirstSkill() = 0;
        virtual void SecondSkill() = 0;
        virtual void ThirdSkill() = 0;
        int HealthPointsLevelUp();
        int FirstSkillLevelUp();
        int SecondSkillLevelUp();
        int ThirdSkillLevelUp();
        int GetHealthPointsLevel() const;
        int GetFirstSkillLevel() const;
        int GetSecondSkillLevel() const;
        int GetThirdSkillLevel() const;
        int GetPhysicalDamage() const;
        int GetMagicalDamage() const;
        int GetThirdSkillReady() const;
        int GetHealthPoints();
        int GetDefendPoints();
        int GetFullHP();
        std::wstring GetName() const;
        void MinusHP(int damage);
        void MinusDefend(int damage);
        bool IsDie();
    protected:
        int m_HealthPointsLevel;
        int m_FirstSkillLevel;
        int m_SecondSkillLevel;
        int m_ThirdSkillLevel;
        std::wstring m_ClassName;
        int m_HealthPoints;
        int m_DefendPoints;
        int m_HealthPointsMax;
        int m_PhysicalDamage = 0;
        int m_MagicalDamage = 0;
        int m_ThirdSkillReady = 0;
        int m_FullHP = 0;
};

class Knight : public GenericCharacter
{
    public:
        Knight(const int hpUp = 1, const int fsl = 1, const int ssl = 1, const int tsl = 1, const std::wstring name = L"׀ûצאנü", int hp = 250, int dp = 100, int hpmax = 250);
        virtual std::wstring GetFirstSkillName() const;
        virtual std::wstring GetSecondSkillName() const;
        virtual std::wstring GetThirdSkillName() const;
        virtual void TakeDamage(int physicalDamage, int magicalDamage);
        virtual void FirstSkill();
        virtual void SecondSkill();
        virtual void ThirdSkill();
    protected:
        bool IsSecondSkill = false;
};

class Withard : public GenericCharacter
{
    public:
        Withard(const int hpUp = 1, const int fsl = 1, const int ssl = 1, const int tsl = 1, const std::wstring name = L"ּאד", int hp = 175, int dp = 100, int hpmax = 175);
        virtual std::wstring GetFirstSkillName() const;
        virtual std::wstring GetSecondSkillName() const;
        virtual std::wstring GetThirdSkillName() const;
        virtual void TakeDamage(int physicalDamage, int magicalDamage);
        virtual void FirstSkill();
        virtual void SecondSkill();
        virtual void ThirdSkill();
    protected:
        bool IsSecondSkill = false;
};

class Assasin : public GenericCharacter
{
public:
    Assasin(const int hpUp = 1, const int fsl = 1, const int ssl = 1, const int tsl = 1, const std::wstring name = L"׃בטיצא", int hp = 210, int dp = 0, int hpmax = 210);
    virtual std::wstring GetFirstSkillName() const;
    virtual std::wstring GetSecondSkillName() const;
    virtual std::wstring GetThirdSkillName() const;
    virtual void TakeDamage(int physicalDamage, int magicalDamage);
    virtual void FirstSkill();
    virtual void SecondSkill();
    virtual void ThirdSkill();
protected:
    bool IsSecondSkill = false;
    int IsThirdSkill = 0;
};