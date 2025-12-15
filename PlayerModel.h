#pragma once

class CPlayerModel
{
private:
	// 座標
	int x;
	int y;

public:

	// 引数コンストラクタ
	CPlayerModel(int start_x, int start_y)
		: x(start_x), y(start_y)
	{}

	// 座標取得関数
	int GetX() const { return x; }
	int GetY() const { return y; }

	// 座標移動関数
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	// 座標セット関数
	void SetPosition(int new_x, int new_y);
};
