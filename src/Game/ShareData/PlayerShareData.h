#pragma once

#include <memory>
#include <vector> 

#include "../../singleton.h"

// バトルとフィールドのプレイヤーデータ共有用クラス

// クラスの作成（１つのクラスのみで管理したいためシングルトンでの管理）
// HP、MP、経験値、レベル、その他取得したアイテムを共有

class Character;

class PlayerShareData : public Singleton<PlayerShareData>
{
	friend class Singleton<PlayerShareData>;

private:

	std::vector<std::shared_ptr<Character>> playerStates;

	// コンストラクタ
	PlayerShareData();
	// デストラクタ
	~PlayerShareData();

public:

	// プレイヤーの状態を取得
	std::vector<std::shared_ptr<Character>>& GetPlayerStates() { return playerStates; }

};