#pragma once
class GenericPlayer
{
	public:
		GenericPlayer(const std::wstring& name = L"");
		virtual std::wstring GetPlayer() const = 0;
		std::wstring GetName() const;
		std::wstring GetCharacterName() const;
		std::wstring GetFirstSkillName() const;
		std::wstring GetSecondSkillName() const;
		std::wstring GetThirdSkillName() const;
		int GetHealthPointsLevel() const;
		int GetFirstSkillLevel() const;
		int GetSecondSkillLevel() const;
		int GetThirdSkillLevel() const;
		int GetExpNum() const;
		int GetHealthPoints() const;
		int GetDefendPoints() const;
		int GetPhysicalDamage() const;
		int GetMagicalDamage() const;
		int GetThirdSkillReady() const;
		int GetFullHP();
		void HpUp() const;
		void FslUp() const;
		void SslUp() const;
		void TslUp() const;
		void FirstSkill();
		void SecondSkill();
		void ThirdSkill();
		int MinusExpNum();
		void PlusNumExp(int plusExp);
		void TakeDamage(int physicalDamage, int magicalDamage);
		void SetCharacter(GenericCharacter* c);
		bool Dead();
	protected:
		std::wstring m_Name;
		GenericCharacter* m_Character;
		int numExp = 4;
};

class Player : public  GenericPlayer
{
	public:
		Player(const std::wstring& name = L"");
		virtual std::wstring GetPlayer() const;
};

class Computer : public GenericPlayer
{
	public:
		Computer(const std::wstring& name = L"");
		virtual std::wstring GetPlayer() const;
};