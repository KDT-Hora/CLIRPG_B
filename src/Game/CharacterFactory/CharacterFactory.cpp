#include "CharacterFactory.h"
// メイン関数
int main() {
	// キャラクターファクトリーの生成
	CharacterFactory* hero = Factory::Chara(CharaFactory::Hero);		// 勇者キャラクターファクトリーの生成
	CharacterFactory* mage = Factory::Chara(CharaFactory::Mage);		// 魔法使いキャラクターファクトリーの生成
	CharacterFactory* warrior = Factory::Chara(CharaFactory::warrior);	// 戦士キャラクターファクトリーの生成
	CharacterFactory* monk = Factory::Chara(CharaFactory::monk);		// 僧侶キャラクターファクトリーの生成

	// 勇者ファクトリーの使用
	hero->Updete();		// 勇者の行動
	hero->Attack();		// 勇者の攻撃
	hero->Defense();	// 勇者の防御
	hero->Damage();		// 勇者のダメージ

	// 魔法使いファクトリーの使用
	mage->Updete();		// 魔法使いの行動
	mage->Attack();		// 魔法使いの魔法
	mage->Defense();	// 魔法使いの防御
	mage->Damage();		// 魔法使いのダメージ

	//	戦士ファクトリーの使用
	warrior->Updete();		// 戦士の行動
	warrior->Attack();		// 戦士の攻撃
	warrior->Defense();		// 戦士の防御
	warrior->Damage();		// 戦士のダメージ

	//	僧侶ファクトリーの使用
	monk->Updete();		// 僧侶の行動
	monk->Attack();		// 僧侶の回復
	monk->Defense();	// 僧侶の防御
	monk->Damage();		// 僧侶のダメージ

	// キャラクターファクトリーの解放
	delete hero;		// 勇者キャラクターファクトリーの解放
	delete mage;		// 魔法使いキャラクターファクトリーの解放
	delete warrior;		// 戦士キャラクターファクトリーの解放
	delete monk;		// 僧侶キャラクターファクトリーの解放

	return 0;



}