#include "BattleScene.h"

#include "../../../Game/CharacterState.h"
#include "../../../Game/ShareData/PlayerShareData.h"
#include "../../../Game/EnemyFactory/EnemyFactory.h"
#include "../SceneMG.h"
#include "../../Input/InputMG.h"


BattleScene::BattleScene()
{

	std::vector<std::shared_ptr<Character>>  playerCharacters;
	std::vector<std::shared_ptr<Character>>  enemyCharacters;

	playerCharacters = PlayerShareData::Instance().GetPlayerStates();

	//	今の階層に応じて敵を生成
	enemyCharacters.push_back(EnemyFactory::CreateEnemy(EnemyType::Slime));
	enemyCharacters.push_back(EnemyFactory::CreateEnemy(EnemyType::Slime));
	enemyCharacters.push_back(EnemyFactory::CreateEnemy(EnemyType::Slime));

	//	初期化処理
	battleMG.Start(playerCharacters, enemyCharacters);

}

BattleScene::~BattleScene() = default;

void BattleScene::Update(double dt)
{
	//	戦闘更新
	battleMG.Update();

	//	スペースキーで前のシーンへ戻る（デバッグ用）
	//if (InputMG::Instance().ChechKey(InputMG::Key::CANCEL))
	//{
	//	//	戦闘結果の取得
	//	auto result = battleMG.GetResult();
	//	//	シーンマネージャーに戦闘終了を通知
	//	SceneMG::Instance().SetChange(SceneType::Field);
//	}
}

void BattleScene::Draw()
{
	battleMG.Draw();
}

void BattleScene::CreateEnemy()
{

}
