#include "PlayerShareData.h"

#include "../CharacterState.h"
#include "../PlayerFactory/PlayerFactory.h"

// コンストラクタ
PlayerShareData::PlayerShareData()
{
	//	初期化処理
	playerStates.clear();

	//	プレイヤーデータを3人分作成
	playerStates.push_back(PlayerFactory::CreatePlayer(PlayerType::Hero));
	playerStates.push_back(PlayerFactory::CreatePlayer(PlayerType::Warrior));
	playerStates.push_back(PlayerFactory::CreatePlayer(PlayerType::Mage));
	playerStates.push_back(PlayerFactory::CreatePlayer(PlayerType::Cleric));


}

// デストラクタ
PlayerShareData::~PlayerShareData() = default;

