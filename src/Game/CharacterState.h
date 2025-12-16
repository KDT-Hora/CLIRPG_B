#pragma once

#include <string>

struct Status {

	int Lv = 1;
	int Exp = 0;

	int MaxHP;
	int HP = MaxHP;
	int MaxMP;
	int MP = MaxMP;

	int STR;
	int INT;
	int VIT;
	int MND;
	int AGI;

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

class Character {

protected:

	std::string name;
	Status state;

	bool isLife = true;

public:

	Character(std::string name, Status baseStatas)
		:name(name), state(baseStatas) 
	{
	}

	const Status& GetState()const
	{
		return state;
	}

	bool IsLife() { return isLife; }

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