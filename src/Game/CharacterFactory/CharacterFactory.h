#pragma once
#include <iostream>

// キャラクターファクトリークラス
class CharacterFactory {
public:
	// 仮想デストラクタ
	virtual ~CharacterFactory() {}

	// 純粋仮想関数
	virtual void Updete() = 0;		// 行動
	virtual void Attack() = 0;		// 攻撃
	virtual void Defense() = 0;		// 防御
	virtual void Damage() = 0;		// ダメージ

};

// 勇者クラス
class heroFactory : public CharacterFactory {
public:
	// 勇者の行動の実装
	void Updete() override {
		std::cout << "勇者の行動" << std::endl;
	}
	// 勇者の攻撃の実装
	void Attack() override {
		std::cout << "勇者の攻撃" << std::endl;
	}
	// 勇者の防御の実装
	void Defense() override {
		std::cout << "勇者は防御した" << std::endl;
	}
	// 勇者のダメージの実装
	void Damage() override {
		std::cout << "勇者はダメージを受けた" << std::endl;
	}
};

// 魔法使いクラス
class MageFactory : public CharacterFactory {
public:
	// 魔法使いの行動の実装
	void Updete() override {
		std::cout << "魔法使いの行動" << std::endl;
	}
	// 魔法使いの魔法の実装
	void Attack() override {
		std::cout << "魔法使いの魔法" << std::endl;
	}
	// 魔法使いの防御の実装
	void Defense() override {
		std::cout << "魔法使いは防御した" << std::endl;
	}
	// 魔法使いのダメージの実装
	void Damage() override {
		std::cout << "魔法使いはダメージを受けた" << std::endl;
	}
};

class warriorFactory : public CharacterFactory {
public:
	// 戦士の行動の実装
	void Updete() override {
		std::cout << "戦士の行動" << std::endl;
	}
	// 戦士の攻撃の実装
	void Attack() override {
		std::cout << "戦士の攻撃" << std::endl;
	}
	// 戦士の防御の実装
	void Defense() override {
		std::cout << "戦士は防御した" << std::endl;
	}
	// 戦士のダメージの実装
	void Damage() override {
		std::cout << "戦士はダメージを受けた" << std::endl;
	}
};

class monkFactory : public CharacterFactory {
public:
	// 僧侶の行動の実装
	void Updete() override {
		std::cout << "僧侶の行動" << std::endl;
	}
	// 僧侶の攻撃の実装
	void Attack() override {
		std::cout << "僧侶の回復" << std::endl;
	}
	// 僧侶の防御の実装
	void Defense() override {
		std::cout << "僧侶は防御した" << std::endl;
	}
	// 僧侶のダメージの実装
	void Damage() override {
		std::cout << "僧侶はダメージを受けた" << std::endl;
	}
};


// キャラクターファクトリー列挙型
enum class CharaFactory
{
	Hero,		// 勇者
	Mage,		// 魔法使い
	warrior,	// 戦士
	monk		// 僧侶
};

// ファクトリークラス
class Factory {
public:
	// 静的メンバ関数
	static CharacterFactory* Chara(CharaFactory type) {
		// 型に応じたキャラクターファクトリーを生成して返す
		switch (type) {
		case CharaFactory::Hero:	// 勇者キャラクターファクトリーの生成
			return new heroFactory();
		case CharaFactory::Mage:	// 魔法使いキャラクターファクトリーの生成
			return new MageFactory();
		case CharaFactory::warrior:	// 戦士キャラクターファクトリーの生成
			return new warriorFactory();
		case CharaFactory::monk:	// 僧侶キャラクターファクトリーの生成
			return new monkFactory();
		default:
			return nullptr;
		}
	}
};

