
#include <iostream>

#include "Stage.h"
#include "StageFactory.h"
#include "KeyInput.h"
#include "PlayerModel.h"
#include "PlayerCon.h"
#include "PlayerView.h"

int main()
{
	// ステージ数
	int cur_stage = 0;

	// ステージクラスのインスタンスを生成
	std::shared_ptr<CStage> Stage = CStageFactory::CreateStage(0);

	// プレイヤーのインスタンスを生成
	std::shared_ptr<CPlayerModel> PlayerModel = std::make_shared<CPlayerModel>(12, 17);
	std::shared_ptr<CPlayerView> PlayerView = std::make_shared<CPlayerView>();
	std::shared_ptr<CPlayerController> PlayerCon = std::make_shared<CPlayerController>(PlayerModel);

	while(true)
	{
		// ステージの描画
		Stage->DrawWithPlayer(PlayerModel->GetX(), PlayerModel->GetY());
		//// プレイヤーの描画
		//PlayerView->Draw(*PlayerModel);

		// キー入力の取得
		char key = CKeyInput::GetInstance().GetKey();
		// プレイヤーの入力処理
		PlayerCon->HandleInput(key, Stage);

		// 次のステージ
		if (key == 'e' && Stage->IsNextStage(PlayerModel->GetX(), PlayerModel->GetY()))
		{
			// 次のステージへ
			cur_stage++;
			Stage = CStageFactory::CreateStage(cur_stage);
			PlayerModel->SetPosition(3, 17);	//	下右側に出現
		}

		// 前のステージ
		if (key == 'e' && Stage->IsPrevStage(PlayerModel->GetX(), PlayerModel->GetY()))
		{
			// 前のステージへ
			cur_stage--;
			Stage = CStageFactory::CreateStage(cur_stage);
			PlayerModel->SetPosition(21, 17); // 下左側に出現
		}

		//// ステージ切り替え
		//if (PlayerCon->RequestStageChange())
		//{
		//	// ステージを順番通りに切り替える
		//	cur_stage++;

		//	// ステージの範囲を決める
		//	if (cur_stage > 9) cur_stage = 0;

		//	Stage = CStageFactory::CreateStage(cur_stage);

		//	// プレイヤーの位置をリセット
		//	PlayerModel->SetPosition(5, 5);
		//}

		//// 入力されたキーによってステージを変更
		//if (key == '1') Stage = CStageFactory::CreateStage(0);
		//else if (key == '2') Stage = CStageFactory::CreateStage(1);
		//else if (key == '3') Stage = CStageFactory::CreateStage(2);
		//else if (key == '4') Stage = CStageFactory::CreateStage(3);
		//else if (key == '5') Stage = CStageFactory::CreateStage(4);
		//else if (key == '6') Stage = CStageFactory::CreateStage(5);
		//else if (key == '7') Stage = CStageFactory::CreateStage(6);
		//else if (key == '8') Stage = CStageFactory::CreateStage(7);
		//else if (key == '9') Stage = CStageFactory::CreateStage(8);
		//else if (key == '0') Stage = CStageFactory::CreateStage(9);
	}

	/*  std::cout << "Hello World!\n";*/
}