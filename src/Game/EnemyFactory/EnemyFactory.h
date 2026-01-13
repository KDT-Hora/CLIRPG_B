#pragma once
#include <memory>
#include "../CharacterState.h"


// 敵の種類
enum class EnemyType  
{
    Slime,      // スライム（雑魚）
    Goblin,     // ゴブリン（少し強い）
    Orc,        // オーク（中ボス級）
    DemonKing   // 魔王（ラスボス）
};

class EnemyFactory 
{
public:

    // 敵生成メソッド
    // タイプを指定して作成（名前は自動設定）
    static std::shared_ptr<Character> CreateEnemy(EnemyType type);
};