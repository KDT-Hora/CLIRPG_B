#pragma once
#include <vector>
#include <memory>

class Character;

enum class BattleResult
{
	None,
	Win,
	Lose
};


class BattleMG
{
public:
	/// 戦闘開始
	void Start(
		const std::vector<std::shared_ptr<Character>>& players,
		const std::vector<std::shared_ptr<Character>>& enemies
	);

	/// 戦闘更新
	void Update();

	/// 戦闘終了判定
	bool IsBattleEnd() const;

	BattleResult GetResult() const { return result; }


private:
	/// 行動順作成
	void CreateTurnOrder();

	/// ターン実行
	void ExecuteTurn();

	/// 各陣営のターン
	void PlayerTurn(const std::shared_ptr<Character>& actor);
	void EnemyTurn(const std::shared_ptr<Character>& actor);

	/// 陣営別全滅判定
	bool IsAllDead(int faction) const;

	std::vector<std::shared_ptr<Character>> characters;
	std::vector<std::shared_ptr<Character>> turnOrder;

	bool battleEndFlag = false;

	BattleResult result = BattleResult::None;
};
