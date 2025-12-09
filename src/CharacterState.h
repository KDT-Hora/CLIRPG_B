#pragma once

struct State {
	int MAX_HP;
	int HP;
	int MAX_MP;
	int MP;
	int ATK;
	int DEF;
	int INT;
	int MND;
	int SPD;
};

class CharacterState {
public:
	virtual ~CharacterState(){}

	int Attack();
    bool IsDefence();
	bool IsDead();
};