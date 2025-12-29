#include "BattleMG.h"
#include "../Game/CharacterState.h"

BattleMG::BattleMG(const std::vector<std::shared_ptr<Character>>& characters)
	: characters_(characters)
{
}

BattleResult BattleMG::Start()
{
	while (true)
	{
		PlayerTurn();
		if (IsAllDead((int)Faction::Enemy))
		{
			return BattleResult::Win;
		}
		EnemyTurn();
		if (IsAllDead((int)Faction::Player))
		{
			return BattleResult::Lose;
		}
	}
}


void BattleMG::PlayerTurn()
{
	for (auto& character : characters_)
	{
		if (!character->IsLife())  { continue; }
		if (character->GetFaction() != Faction::Player) { continue; }

		for (auto& target : characters_)
		{
			if (!target->IsLife()) continue;
			if (target->GetFaction() == Faction::Enemy)
			{
				character->Attack(*target);
				break;
			}
		}
	}
}

void BattleMG::EnemyTurn()
{
	for (auto& actor : characters_)
	{
		if (!actor->IsLife()) continue;
		if (actor->GetFaction() != Faction::Enemy) continue;

		for (auto& target : characters_)
		{
			if (!target->IsLife()) continue;
			if (target->GetFaction() == Faction::Player)
			{
				actor->Attack(*target);
				break;
			}
		}
	}
}

//	w‰c•Ê‘S–Å”»’è
bool BattleMG::IsAllDead(int faction) const
{
	for (auto& c : characters_)
	{
		if ((int)c->GetFaction() == faction && c->IsLife())
			return false;
	}
	return true;
}