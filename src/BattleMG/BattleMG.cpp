#include "BattleMG.h"
#include "../Game/CharacterState.h"
#include <algorithm>


void BattleMG::Start(
    const std::vector<std::shared_ptr<Character>>& players,
    const std::vector<std::shared_ptr<Character>>& enemies)
{
    characters.clear();
    turnOrder.clear();
    battleEndFlag = false;
	result = BattleResult::None;

    // プレイヤー
    for (const std::shared_ptr<Character>& p : players)
    {
        characters.push_back(p);
    }

    // エネミー
    for (const std::shared_ptr<Character>& e : enemies)
    {
        characters.push_back(e);
    }

    CreateTurnOrder();
}


void BattleMG::Update()
{
    if (battleEndFlag)
        return;

    ExecuteTurn();


    if (IsAllDead((int)Faction::Enemy))
    {
        battleEndFlag = true;
		result = BattleResult::Win;
    }
    else if (IsAllDead((int)Faction::Player))
    {
        battleEndFlag = true;
		result = BattleResult::Lose;
    }
}



bool BattleMG::IsBattleEnd() const
{
    return battleEndFlag;
}


void BattleMG::CreateTurnOrder()
{
    turnOrder = characters;

    std::sort(
        turnOrder.begin(),
        turnOrder.end(),
        [](const std::shared_ptr<Character>& a,
            const std::shared_ptr<Character>& b)
        {
            return a->GetState().AGI > b->GetState().AGI;
        }
    );
}



void BattleMG::ExecuteTurn()
{
    for (const std::shared_ptr<Character>& actor : turnOrder)
    {
        if (!actor->IsLife())
            continue;

        if (actor->GetFaction() == Faction::Player)
        {
            PlayerTurn(actor);
        }
        else
        {
            EnemyTurn(actor);
        }

        // ターン途中でも終了判定
        if (IsAllDead((int)Faction::Enemy) ||
            IsAllDead((int)Faction::Player))
        {
            battleEndFlag = true;
            return;
        }
    }
}



void BattleMG::PlayerTurn(const std::shared_ptr<Character>& actor)
{
    // 仮実装：最初に見つかった生存エネミーを攻撃
	// TODO: 攻撃対象選択
    for (const std::shared_ptr<Character>& target : characters)
    {
        if (target->GetFaction() == Faction::Enemy &&
            target->IsLife())
        {
            actor->Attack(*target);
            break;
        }
    }
}



void BattleMG::EnemyTurn(const std::shared_ptr<Character>& actor)
{
    // 仮実装：最初に見つかった生存エネミーを攻撃
	// TODO: 攻撃対象選択ランダム化
    for (const std::shared_ptr<Character>& target : characters)
    {
        if (target->GetFaction() == Faction::Player &&
            target->IsLife())
        {
            actor->Attack(*target);
            break;
        }
    }
}


bool BattleMG::IsAllDead(int faction) const
{
    for (const std::shared_ptr<Character>& c : characters)
    {
        if ((int)c->GetFaction() == faction && c->IsLife())
            return false;
    }
    return true;
}
