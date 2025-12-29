#pragma once

// NPC用クラス

class MapEnemy
{
private:

	// 座標
	int x = 0;
	int y = 0;

public:

	// コンストラクタ
	MapEnemy() = default;
	MapEnemy(int px, int py) : x(px), y(py)
	{ }

	// デストラクタ
	virtual ~MapEnemy() = default;

	// 座標をいれる関数
	void SetPos(int px, int py);

	// ゲッター
	int GetX() const { return x; }
	int GetY() const { return y; }
};
