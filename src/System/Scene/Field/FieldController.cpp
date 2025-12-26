#include "System/Scene/Field/FieldController.h"
#include "System/Input/InputMG.h"

void FieldController::SetupStageObjects()
{
	// プレイヤーの座標設定
	int px, py;
	Map_Manager.GetMapData().GetStartPos(px, py);
	M_Player.SetPos(px, py); // 座標を入れる

	// NPCの座標設定
	int nx, ny;
	nx = Map_Manager.GetMapData().GetWidth() / 2;
	ny = 5;
	M_Npc.SetPos(nx, ny); // 座標を入れる

	// 入力によるステージの更新
	Map_Manager.MarkDirty();
}

void FieldController::Init(int start_stage)
{
	// 最初のステージを設定
	current_stage = start_stage;
	Map_Manager.LoadMap(current_stage);

	// オブジェクトの初期化設定
	SetupStageObjects();
}

void FieldController::HandleMove()
{
	// ステージの情報をデータに入れる
	const MapData& Map = Map_Manager.GetMapData();

	// 入力更新処理
	if (Player_Ctrl.InputUpdate(M_Player, Map))
	{
		Map_Manager.MarkDirty(); // 移動した時だけ描画
	}
}

void FieldController::HandleStairs()
{
	// キー入力の取得
	auto key = InputMG::Instance().GetKey();
	// ステージ情報を入れる
	const MapData& Map = Map_Manager.GetMapData();

	// タイル情報の取得
	int tile = Map.GetTile(M_Player.GetX(), M_Player.GetY());

	// 画面の遷移方向を設定
	move_dir = StageMoveDir::None;

	// プレイヤーの座標が階段タイルのときのステージの切り替え処理
	// 上
	if (tile == static_cast<int>(TileType::StairUp) &&
		key == InputMG::RIGHT)
	{
		// 次のステージへ
		current_stage++;
		move_dir = StageMoveDir::Up; // 画面遷移設定を上にする
	}
	// 下
	else if (tile == static_cast<int>(TileType::StairDown) &&
		key == InputMG::LEFT)
	{
		// 前のステージへ
		current_stage--;
		move_dir = StageMoveDir::Down; // 画面遷移設定を下にする
	}
	else
	{
		return;
	}

	// ステージの上限
	if (current_stage < 1) current_stage = 1;
	if (current_stage > 10) current_stage = 10;

	// ステージの呼び出し
	Map_Manager.LoadMap(current_stage);

	// オブジェクトの初期化
	SetupStageObjects();

	// プレイヤーの座標更新（出現位置の決定）
	int x, y;
	const MapData& New_Map = Map_Manager.GetMapData();

	// 上
	if (move_dir == StageMoveDir::Up)
	{
		// 下りの階段では右に出現させる
		New_Map.GetStairDownPos(x, y);
		M_Player.SetPos(x + 1, y);
	}
	// 下
	else if (move_dir == StageMoveDir::Down)
	{
		// 上りの階段では左に出現させる
		New_Map.GetStairUpPos(x, y);
		M_Player.SetPos(x - 1, y);
	}

	// 画面の更新
	Map_Manager.MarkDirty();
}

FieldController::FieldController()
{
	Init(1);
}

void FieldController::Update(double dt)
{
	// 上記の処理を呼び出す
	HandleMove();
	HandleStairs();
}

void FieldController::Draw()
{
	// マップの描画処理
	Map_Manager.DrawIfNeeded(M_Player, M_Npc);
} 