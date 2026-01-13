#include "EnemyFactory.h"

std::shared_ptr<Character> EnemyFactory::CreateEnemy(EnemyType type) {

    Status stats;
    std::string name;

    switch (type) {
    case EnemyType::Slime:
        name = "Slime";
        stats.MaxHP = 30;
        stats.MaxMP = 0;
        stats.STR = 8;
        stats.VIT = 5;
        stats.AGI = 4;
        stats.Exp = 5; // 倒したときの経験値として使用
        break;

    case EnemyType::Goblin:
        name = "Goblin";
        stats.MaxHP = 60;
        stats.MaxMP = 0;
        stats.STR = 12;
        stats.VIT = 8;
        stats.AGI = 9;
        stats.Exp = 15;
        break;

    case EnemyType::Orc:
        name = "Orc";
        stats.MaxHP = 150;
        stats.MaxMP = 0;
        stats.STR = 18;
        stats.VIT = 15;
        stats.AGI = 6;
        stats.Exp = 50;
        break;

    case EnemyType::DemonKing:
        name = "Demon King";
        stats.MaxHP = 500;
        stats.MaxMP = 999;
        stats.STR = 30;
        stats.INT = 30;
        stats.VIT = 25;
        stats.MND = 25;
        stats.AGI = 20;
        stats.Exp = 0; // ラスボス
        break;
    }

    stats.HP = stats.MaxHP;
    stats.MP = stats.MaxMP;

    // 生成して返す (Faction::Enemyを指定)
    return std::make_shared<Character>(name, Faction::Enemy, stats);
}