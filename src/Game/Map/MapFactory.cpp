#include "MapFactory.h"

#include <iostream>
#include <array>

// Next→プレイヤーのWASD入力でのマス移動とアクション

namespace
{
	// 定数
	// タイル数
	constexpr int MAP_W = 25;
	constexpr int MAP_H = 17;
	// タイル数の合計
	constexpr int MAP_SIZE = MAP_W * MAP_H;
	
	// タイル情報
	constexpr int F = static_cast<int>(TileType::Floor);
	constexpr int W = static_cast<int>(TileType::Wall);
	constexpr int D = static_cast<int>(TileType::StairDown);
	constexpr int U = static_cast<int>(TileType::StairUp);
	constexpr int C = static_cast<int>(TileType::Chest);
	constexpr int H = static_cast<int>(TileType::HealSpot);
	constexpr int S = static_cast<int>(TileType::StartPoint);

	// 外周壁
	constexpr int MakeTile(int x, int y)
	{
		return (x == 0 || y == 0 || x == MAP_W - 1 || y == MAP_H - 1)
			? W : F;
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
	static const std::array<int, MAP_SIZE> BuildStage1()
	{
		// タイルの配置
		auto d = BuildBase();
		d[(MAP_H - 2) * MAP_W + 1] = S;             // 初期位置
		d[(MAP_H - 2) * MAP_W + (MAP_W - 2)] = U;	// 上に行く階段
		return d;
	}

	// 2～9階
	static const std::array<int, MAP_SIZE> BuildMiddleStage()
	{
		auto d = BuildBase();
		d[(MAP_H - 2) * MAP_W + 1] = D;				// 下に行く階段
		d[(MAP_H - 2) * MAP_W + 3] = H;				// ヒールエリア
		d[(MAP_H - 2) * MAP_W + (MAP_W - 2)] = U;	// 上に行く階段
		return d;
	}

	// 10階
	static const std::array<int, MAP_SIZE> BuildLastStage()
	{
		auto d = BuildBase();
		d[(MAP_H - 2) * MAP_W + 1] = D;				// 下に行く階段
		d[(MAP_H - 2) * MAP_W + 2] = H;				// ヒールエリア
		return d;
	}

	// 実体
	static const auto STAGE1 = BuildStage1();
	static const auto STAGE_MID = BuildMiddleStage();
	static const auto STAGE10 = BuildLastStage();

	// ステージデータの割り当て
	static const StageData STAGE_TABLE[] =
	{
		{1, MAP_W, MAP_H, STAGE1.data()},
		{2, MAP_W, MAP_H, STAGE_MID.data()},
		{3, MAP_W, MAP_H, STAGE_MID.data()},
		{4, MAP_W, MAP_H, STAGE_MID.data()},
		{5, MAP_W, MAP_H, STAGE_MID.data()},
		{6, MAP_W, MAP_H, STAGE_MID.data()},
		{7, MAP_W, MAP_H, STAGE_MID.data()},
		{8, MAP_W, MAP_H, STAGE_MID.data()},
		{9, MAP_W, MAP_H, STAGE_MID.data()},
		{10, MAP_W, MAP_H, STAGE10.data()},
	};


	// StageDataのデータ数を取得
	constexpr int STAGE_TABLE_SIZE =
		sizeof(STAGE_TABLE) / sizeof(StageData);
}

bool MapFactory::CreateStage(int stage_id, MapData& OutMap)
{
	// ステージを生成する際に使用するデータを取得
	for (int i = 0; i < STAGE_TABLE_SIZE; ++i)
	{
		if (STAGE_TABLE[i].GetStageID() == stage_id)
		{
			OutMap.Init
			(
				STAGE_TABLE[i].GetWidth(),
				STAGE_TABLE[i].GetHeight(),
				STAGE_TABLE[i].GetTiles()
			);
			return true;
		}
	}
	return false;
}
