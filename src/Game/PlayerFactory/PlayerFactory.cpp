#include "PlayerFactory.h"

std::shared_ptr<Character> PlayerFactory::CreatePlayer(PlayerType type) {

    Status stats;
    std::string name;

    // タイプごとのステータスと名前の調整
    switch (type) {
    case PlayerType::Hero:
        name = "Hero";
        stats.MaxHP = 120;
        stats.MaxMP = 40;
        stats.STR = 12;
        stats.VIT = 12;
        stats.AGI = 12;
        break;

    case PlayerType::Warrior:
        name = "Warrior";
        stats.MaxHP = 150;
        stats.MaxMP = 10;
        stats.STR = 16;
        stats.VIT = 14;
        stats.INT = 5;
        stats.AGI = 8;
        break;

    case PlayerType::Mage:
        name = "Mage";
        stats.MaxHP = 70;
        stats.MaxMP = 100;
        stats.STR = 4;
        stats.VIT = 8;
        stats.INT = 16;
        stats.MND = 14;
        break;

    case PlayerType::Cleric:
        name = "Cleric";
        stats.MaxHP = 90;
        stats.MaxMP = 80;
        stats.STR = 8;
        stats.VIT = 10;
        stats.INT = 10;
        stats.MND = 16;
        break;
    }

    stats.HP = stats.MaxHP;
    stats.MP = stats.MaxMP;

    return std::make_shared<Character>(name, Faction::Player, stats);
}