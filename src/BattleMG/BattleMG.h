#pragma once
#include <vector>
#include <memory>
#include <string>

class Character;

enum class BattleResult
{
	None,
	Win,
	Lose
};

// バトル状態の定義
enum class BattleState {
	Init,           // 初期化
	OrderStep,      // 行動順計算
	ActionStep,     // 個別のアクション実行
	CheckEnd,       // 終了判定
	ResultDisplay,  // 結果表示
	End             // 完全に終了
};

class BattleMG
{
public:

	//	デストラクタ
	~BattleMG();

	// 戦闘開始
	void Start(
		const std::vector<std::shared_ptr<Character>>& players,
		const std::vector<std::shared_ptr<Character>>& enemies
	);

	// 戦闘更新
	void Update();

	void Draw();

	// 戦闘終了判定
	bool IsBattleEnd() const { return currentState == BattleState::End; }

	BattleResult GetResult() const { return result; }


private:
	void ChangeState(BattleState newState);

	// 状態ごとの更新処理
	void UpdateInit();
	void UpdateOrderStep();
	void UpdateActionStep();
	void UpdateCheckEnd();
	void UpdateResultDisplay();

	//	状態毎の描画処理
	void DrawInit();
	void DrawOrderStep();
	void DrawActionStep();
	void DrawCheckEnd();
	void DrawResultDisplay();


	// 補助関数
	bool IsAllDead(int faction) const;
	void DrawStatus(); // 現在の全員のステータスをViewに送る

	std::vector<std::shared_ptr<Character>> characters;
	std::vector<std::shared_ptr<Character>> turnOrder;

	BattleState currentState = BattleState::Init;
	BattleResult result = BattleResult::None;

	size_t currentActorIndex = 0; // 現在誰の行動か
	std::string battleLog;        // 表示するログ
};