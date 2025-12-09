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
private:
	State state;
public:
	virtual ~CharacterState() {}

	/// <summary>
	/// bool型で防御状態かどうかを返す(仮)
	/// </summary>
	/// <returns></returns>
    bool IsDefence();

	/// <summary>
	/// bool型で死亡判定
	/// </summary>
	/// <returns></returns>
	bool IsDead();

	/// <summary>
	/// ダメージを受け取り、実際に受けたダメージを返す(仮実装)
	/// </summary>
	/// <param name="damage"></param>
	/// <returns></returns>
	int TakeDamage(int damage);
};