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

protected:

	State state;

public:

	virtual ~CharacterState() = default;

	const State& GetState()const
	{
		return state;
	}
};