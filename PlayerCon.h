#pragma once
#include "PlayerModel.h"
#include "Stage.h"
#include "StageFactory.h"

#include <iostream>

class CPlayerController
{
private:

	// プレイヤーモデルを呼び出す
	std::shared_ptr<CPlayerModel> model;

	// ステージの切り替えを取得するための関数
	bool WantStageChange;

public:

	// 引数コンストラクタ
	CPlayerController(std::shared_ptr<CPlayerModel>& Model)
		:model(Model), WantStageChange(false)
	{}

	// 入力処理関数
	void HandleInput(char key, const std::shared_ptr<CStage>& stage);

	// ステージ切り替え入力関数
	bool RequestStageChange() const;
};
