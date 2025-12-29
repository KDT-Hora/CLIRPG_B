#pragma once


#include "../../../Game/Map/MapManager.h"
#include "../../../Game/Map/MapPlayer/MapPlayer.h"
#include "../../../Game/Map/MapPlayer/MapPlayerCon.h"
#include "../../../Game/Map/MapEnemy/MapEnemy.h"

#include "FieldView/FieldViewSystem.h"
#include "../IScene.h"

// フィールドクラス
// プレイヤーのフィールド間のタイル移動やステージの更新を行う

// 回復イベント追加
// プレイヤーの座標がヒールタイルの上を通った時にHPをプレイヤーのHPとMPを回復
// プレイヤー移動後に現在のタイルをチェックさせる

// 衝突判定の追加
// エネミータイルをプレイヤーが通った際にシーンをバトルに変更する

// 遷移方向
enum class StageMoveDir
{
	None, // なし
	Up,	  // 上
	Down, // 下
};

class FieldScene : public IScene
{
private:

	// マップマネージャークラス
	MapManager Map_Manager;
	// プレイヤークラス
	MapPlayer M_Player;
	// プレイヤーコントローラー
	MapPlayerController Player_Ctrl;
	// NPCクラス
	MapEnemy M_Npc;

	// 画面遷移
	StageMoveDir move_dir = StageMoveDir::None;
	// フィールド描画管理クラスを呼び出す
	std::unique_ptr<FieldViewSystem> FieldViewPtr = std::make_unique<FieldViewSystem>();

	// 現在のステージ
	int current_stage = 1;

	// タイル移動処理関数
	void HandleMove();
	// ステージ移動処理関数
	void HandleStairs();
	// オブジェクトの初期化設定用関数
	void SetupStageObjects();

	// ヒールタイルのイベント用関数の追加
	// ヒールタイルにプレイヤーが通った時に処理を実行
	// プレイヤーのステータスのHPを増やす

	// エネミータイルのイベント用関数の追加
	// エネミータイルにプレイヤーが通った時に処理を実行
	// シーンマネージャーからシーンをバトルに移行
	// 戦闘開始フラグを作成する

	// バトルシーン終了後の切り替え時に処理用関数

public:

	// コンストラクタ
	FieldScene();
	// デストラクタ
	virtual ~FieldScene() override = default;

	// 初期化処理
	void Init(int start_stage);
	// 更新処理
	void Update(double dt) override;
	// 描画処理
	void Draw() override;
};