#pragma once
#include <memory>
#include <string> 
#include "../CharacterState.h"

enum class PlayerType {
    Hero,       // 勇者
    Warrior,    // 戦士
    Mage,       // 魔法使い
    Cleric      // 僧侶
};

class PlayerFactory {
public:
    // プレイヤー生成メソッド
    static std::shared_ptr<Character> CreatePlayer(PlayerType type);
};