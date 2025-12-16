
#include <iostream>
#include "GameManager.h"

#include "Stage.h"
#include "StageFactory.h"
#include "KeyInput.h"
#include "PlayerModel.h"
#include "PlayerCon.h"
#include "PlayerView.h"

int main()
{
    std::cout << "Hello World!\n";

	GameManager::Instance().Init();
	GameManager::Instance().Run();

	std::cout << "Game End";

	return 0;
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

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
