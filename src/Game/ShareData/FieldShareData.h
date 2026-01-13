#pragma once

#include <vector>
#include <memory>
#include "../../singleton.h"

class FieldShareData : public Singleton<FieldShareData>
{
	friend class Singleton<FieldShareData>;
private:

	//	コンストラクタ
	FieldShareData() = default;
	//	デストラクタ
	~FieldShareData() = default;


	//	情報保存用変数
	int current_stage = 1;
	int player_x = 0;
	int player_y = 0;

public:

	//	現在のステージ取得
	int GetCurrentStage() const { return current_stage; }
	//	現在のステージ設定
	void SetCurrentStage(int stage) { current_stage = stage; }
	//	プレイヤーX座標取得
	int GetPlayerX() const { return player_x; }
	//	プレイヤーX座標設定
	void SetPlayerX(int x) { player_x = x; }
	//	プレイヤーY座標取得
	int GetPlayerY() const { return player_y; }
	//	プレイヤーY座標設定
	void SetPlayerY(int y) { player_y = y; }
};