#pragma once

#include <string>

struct Status {

	int Lv = 1;
	int Exp = 0;

	int MaxHP = 100;
	int HP = MaxHP;
	int MaxMP = 50;
	int MP = MaxMP;

	//	ïWèÄílÅ@ÇPÇO
	int STR = 10;
	int INT = 10;
	int VIT = 10;
	int MND = 10;
	int AGI = 10;

	void LevelUp()
	{
		if (Lv >= 10)return;

		MaxHP += 20;
		MaxMP += 10;
		STR += 2;
		INT += 2;
		VIT += 2;
		MND += 2;
		AGI += 2;

		Exp = 0;
	}


};

// ÉLÉÉÉâÉNÉ^Å[ÇÃêwâc
enum class Faction
{
	Player,
	Enemy
};

class Character {

protected:

	std::string name;
	Status state;

	bool isLife = true;

	Faction faction;
public:

	Faction GetFaction()const { return faction; }

	Character(std::string name,Faction faction, Status baseStatas)
		:name(name),faction(faction), state(baseStatas)
	{
	}

	~Character() {}

	const Status& GetState()const
	{
		return state;
	}

	bool IsLife() { return isLife; }

	int Attack(Character& target) const
	{
		return state.STR;
	}

	void TakeDamage(int damage)
	{
		if (damage < 0)damage = 0;
		state.HP -= damage;
		if (state.HP < 0)
		{
			state.HP = 0;
			isLife = false;
		}
	}

	void Heal(int value)
	{
		if (value < 0) { return; }
		state.HP += value;
		if (state.HP > state.MaxHP)
		{
			state.HP = state.MaxHP;
		}
	}

};