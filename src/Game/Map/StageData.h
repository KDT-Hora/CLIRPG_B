#pragma once

struct StageData
{
private:

	// ステージ番号（１～１０）
	int stage_id;

	// 座標
	int width;
	int height;

	// タイルの数
	const int* tiles;

public:

	// コンストラクタ
	constexpr StageData(int arg_id, int arg_w, int arg_h, const int* arg_t)
		:stage_id(arg_id), width(arg_w), height(arg_h), tiles(arg_t)
	{ }

	// デストラクタ
	virtual ~StageData() = default;

	// メンバ変数のゲッター関数
	int GetStageID() const { return stage_id; }
	int GetWidth() const { return width; }
	int GetHeight() const { return height; }
	const int* GetTiles() const { return tiles; }
};
