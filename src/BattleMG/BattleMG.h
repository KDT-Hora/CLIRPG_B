#pragma once
#include <vector>
#include <memory>

class Character;

enum class BattleResult
{
	Win,
	Lose,
	Escape
};

class BattleMG
{
public:
	BattleMG(const std::shared_ptr<Character>& characters);

	BattleResult Start();

private:
	std::vector<std::shared_ptr<Character>> characters_;

	void PlayerTurn();
	void EnemyTurn();

	bool IsAllDead(int faction) const;
};