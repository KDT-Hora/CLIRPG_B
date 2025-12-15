#include "PlayerCon.h"

void CPlayerController::HandleInput(char key, const std::shared_ptr<CStage>& stage)
{
	// 座標の管理
	int next_x = model->GetX();
	int next_y = model->GetY();

	switch (key)
	{
	case 'w': case 'W': next_y--; break;		// Wキーが入力されたとき
	case 's': case 'S': next_y++; break;	// Sキーが入力されたとき
	case 'a': case 'A': next_x--; break;	// Aキーが入力されたとき
	case 'd': case 'D': next_x++; break;	// Dキーが入力されたとき
	}

	// 壁当たり判定
	if (!stage->IsWall(next_x, next_y))
	{
		model->SetPosition(next_x, next_y);
	}

	// 画面切り替えマス判定
	if ((key == 'f' || key == 'F') &&
		stage->IsEvent(model->GetX(), model->GetY()))
	{
		// 画面切り替えを有効
		WantStageChange = true;
	}
	else
	{
		// それ以外のマスでの入力ではfalse
		WantStageChange = false;
	}
}

bool CPlayerController::RequestStageChange() const
{
	// ステージ切り替えフラグを返す
	return WantStageChange;
}
