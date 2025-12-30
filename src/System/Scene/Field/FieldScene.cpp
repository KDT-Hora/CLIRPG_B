#include "FieldScene.h"
#include "../../Input/InputMG.h"
#include "../../View/View.h"
#include "../SceneMG.h"

// コンストラクタ
FieldScene::FieldScene()
{
	Init(1);
}

void FieldScene::SetupStageObjects()
{
	// プレイヤーの座標設定
	int px, py;
	Map_Manager.GetMapData().GetStartPos(px, py);
	M_Player.SetPos(px, py); // 座標を入れる

	// 初期位置設定後に視界の確立
	Map_Manager.GetMapData().UpdateExploredArea(px, py);

	// NPCの座標設定
	int nx, ny;
	nx = Map_Manager.GetMapData().GetWidth() / 2;
	ny = 5;

	// 範囲外には行かないように設定
	if (Map_Manager.GetMapData().IsInBounds(nx, ny))
	{
		M_Npc.SetPos(nx, ny);	// 座標を入れる
	}
	else // 範囲外に行ってしまった場合
	{
		M_Npc.SetPos(0, 0);		// ファイルセーフ
	}

	// 入力によるステージの更新
	Map_Manager.MarkDirty();
}

void FieldScene::Init(int start_stage)
{
	// 最初のステージを設定
	current_stage = start_stage;
	Map_Manager.LoadMap(current_stage);

	// オブジェクトの初期化設定
	SetupStageObjects();
}

void FieldScene::HandleMove()
{
	// 座標の設定用ローカル変数
	int px = 0;
	int py = 0;

	// キー入力の取得
	auto key = InputMG::Instance().GetKey();

	// キー入力による移動処理
	switch (key)
	{
	case InputMG::UP:		py = -1; break;
	case InputMG::DOWN:		py = 1; break;
	case InputMG::LEFT:		px = -1; break;
	case InputMG::RIGHT:	px = 1; break;
	}

	// 特定の状態の時はリターンを返す
	if (px == 0 && py == 0)
	{
		return;
	}

	// ステージの情報をデータに入れる
	const MapData& Map = Map_Manager.GetMapData();

	// 座標移動用ローカル変数
	int nx = M_Player.GetX() + px;
	int ny = M_Player.GetY() + py;

	// 移動できるときはリターンを返す
	if (!Map.CanMove(nx, ny))
		return;

	// プレイヤーの移動入力更新処理
	Player_Ctrl.InputUpdate(M_Player, px, py);

	// 初期位置設定後に視界の確立
	Map_Manager.GetMapData().UpdateExploredArea(
		M_Player.GetX(),
		M_Player.GetY()
	);

	Map_Manager.MarkDirty(); // 移動した時だけ描画

}

void FieldScene::HandleStairs()
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

	// 初期位置設定後に視界の確立
	Map_Manager.GetMapData().UpdateExploredArea(
		M_Player.GetX(),
		M_Player.GetY()
	);

	// 画面の更新
	Map_Manager.MarkDirty();
}

void FieldScene::Update(double dt)
{
	// 上記の処理を呼び出す
	HandleMove();
	HandleStairs();

	//	デバッグ用シーン遷移処理
	if (InputMG::Instance().ChechKey(InputMG::Key::ENTER))
	{
		SceneMG::Instance().SetChange(SceneType::Battle);
	}

}

void FieldScene::DrawGuide()
{
	// 操作方法
	View::Instance().Add("W / A / S / D : 移動");

	// 座標を取得
	int px = M_Player.GetX();
	int py = M_Player.GetY();

	// マップ情報を取得
	const auto& Map_Data = Map_Manager.GetMapData();
	// タイル情報を取得
	TileType tile = static_cast<TileType>(Map_Data.GetTile(px, py));

	// 階段タイル情報
	View::Instance().Add("<< ：次のステージ | >>：前のステージ");
	View::Instance().Add("&& : 敵");
	
	// 回復タイルを踏んでいるときだけ描画
	if (Map_Data.IsHealTile(px, py)) 
	{
		View::Instance().Add("回復ポイント");
	}
}

void FieldScene::Draw()
{
	// 描画の呼び出し
	FieldViewPtr->FieldDraw(
		Map_Manager.GetMapData(),
		M_Player,
		M_Npc
	);

	// ガイドの描画
	this->DrawGuide();
}