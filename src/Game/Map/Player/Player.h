#pragma once

class Player
{
private:

	// 開始座標
	int m_x = 1;
	int m_y = 1;

public:

	// コンストラクタ
	Player()
		: m_x(0),m_y(0)
	{ }

	// デストラクタ
	virtual ~Player() = default;

	// 座標導入処理
	void SetPos(int arg_x, int arg_y);
	// 移動処理
	void Move(int dx, int dy);

	// 座標取得関数
	int GetX() const { return m_x; }
	int GetY() const { return m_y; }
};