#include "MapFactory.h"

#include <iostream>
#include <array>

namespace
{
	// 座標を表す構造体
	struct TilePos
	{
		int x;
		int y;
	};

	// 定数
	// タイル数
	constexpr int MAP_W = 25;
	constexpr int MAP_H = 17;
	// タイル数の合計
	constexpr int MAP_SIZE = MAP_W * MAP_H;

	// タイルの座標
	constexpr TilePos START_POS			{ 2, MAP_H - 2 };			// スタート座標
	constexpr TilePos STAIR_UP_POS		{ MAP_W - 2, MAP_H - 2 };	// 上の階に行く階段
	constexpr TilePos STAIR_DOWN_POS	{ 1, MAP_H - 2 };			// 下の階に行く階段
	constexpr TilePos HEAL_POS			{ 3, MAP_H - 2 };			// ヒールタイル

	// タイルの種類とそれに合わせた座標設定
	constexpr int ToIndex(const TilePos& Pos)
	{
		return Pos.y * MAP_W + Pos.x;
	}

	// タイルの種類を取得するためのインライン関数
	inline int ToTile(TileType type)
	{
		return static_cast<int>(type);
	}

	// 外周壁
	// 壁かフロアかで通れるか通れないかの判定
	constexpr int MakeTile(int x, int y)
	{
		return (x == 0 || y == 0 || x == MAP_W - 1 || y == MAP_H - 1)
			? ToTile(TileType::Wall) : ToTile(TileType::Floor);
	}

	// ベースマップ
	std::array<int, MAP_SIZE> BuildBase()
	{
		std::array<int, MAP_SIZE> d{};

		for (int y = 0; y < MAP_H; ++y)
			for (int x = 0; x < MAP_W; ++x)
				d[y * MAP_W + x] = MakeTile(x, y);

		return d;
	}

	// 1階
	static const std::array<int, MAP_SIZE> BuildFirstStage()
	{
		// タイルの配置
		auto d = BuildBase();
		d[ToIndex(START_POS)] = ToTile(TileType::StartPoint);					// 初期位置
		d[ToIndex(STAIR_UP_POS)] = ToTile(TileType::StairUp);					// 上に行く階段
		return d;
	}

	// 2～9階
	static const std::array<int, MAP_SIZE> BuildMiddleStage()
	{
		auto d = BuildBase();
		d[ToIndex(STAIR_DOWN_POS)] = ToTile(TileType::StairDown);				// 下に行く階段
		d[ToIndex(HEAL_POS)] = ToTile(TileType::HealSpot);						// ヒールエリア
		d[ToIndex(STAIR_UP_POS)] = ToTile(TileType::StairUp);					// 上に行く階段
		return d;
	}

	// 10階
	static const std::array<int, MAP_SIZE> BuildLastStage()
	{
		auto d = BuildBase();
		d[ToIndex(STAIR_DOWN_POS)] = ToTile(TileType::StairDown);				// 下に行く階段
		d[ToIndex(HEAL_POS)] = ToTile(TileType::HealSpot);						// ヒールエリア
		return d;
	}

	// 実体
	static const auto FIRST_STAGE = BuildFirstStage();
	static const auto MID_STAGE = BuildMiddleStage();
	static const auto LAST_STAGE = BuildLastStage();

	// ステージデータの割り当て
	static const StageData STAGE_TABLE[] =
	{
		{1, MAP_W, MAP_H, FIRST_STAGE.data()},
		{2, MAP_W, MAP_H, MID_STAGE.data()},
		{3, MAP_W, MAP_H, MID_STAGE.data()},
		{4, MAP_W, MAP_H, MID_STAGE.data()},
		{5, MAP_W, MAP_H, MID_STAGE.data()},
		{6, MAP_W, MAP_H, MID_STAGE.data()},
		{7, MAP_W, MAP_H, MID_STAGE.data()},
		{8, MAP_W, MAP_H, MID_STAGE.data()},
		{9, MAP_W, MAP_H, MID_STAGE.data()},
		{10, MAP_W, MAP_H, LAST_STAGE.data()},
	};


	// StageDataのデータ数を取得
	constexpr int STAGE_TABLE_SIZE =
		sizeof(STAGE_TABLE) / sizeof(StageData);
}

MapData MapFactory::CreateStage(int stage_id)
{
	// ステージを生成する際に使用するデータを取得
	for (int i = 0; i < STAGE_TABLE_SIZE; ++i)
	{
		if (STAGE_TABLE[i].GetStageID() == stage_id)
		{
			return MapData
			(
				STAGE_TABLE[i].GetWidth(),
				STAGE_TABLE[i].GetHeight(),
				STAGE_TABLE[i].GetTiles()
			);
		}
	}

	// 見つからなかった場合は描画しない
	return MapData(0, 0, nullptr);
}
