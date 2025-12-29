#pragma once
#include "../CharacterState.h"

enum class EnemyAction
{
	Attack,
	Sabotage,
	Heal,
};

class Enemy :public Character
{
public:
	using Character::Character;
};