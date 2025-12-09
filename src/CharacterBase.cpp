#include "CharacterState.h"

// キャラクターの攻撃力を返す
int CharacterState::Attack() {
	return this->state.ATK;
}

// キャラクターが防御状態にあるかどうかを判定する(仮)
bool CharacterState::IsDefence() {
	return false;
}

// キャラクターが死亡しているかどうかを判定する
bool CharacterState::IsDead() {
	return this->state.HP <= 0;
}

// ダメージを受け取り、実際に受けたダメージを返す(仮)
int CharacterState::TakeDamage(int damage) {
	int actualDamage = damage - this->state.DEF;
	if (actualDamage < 0) {
		actualDamage = 0;
	}
	this->state.HP -= actualDamage;
	if (this->state.HP < 0) {
		this->state.HP = 0;
	}
	return actualDamage;
}