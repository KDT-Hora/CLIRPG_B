#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Stage.h"

// ステージのファクトリークラス
// ステージの種類を増やしたい場合、このクラスから拡張する

class CStageFactory
{
public:
	// ステージの生成関数
	static std::shared_ptr<CStage> CreateStage(int id)
	{
		// ステージのIDによって生成するステージを変更
		switch (id)
		{
		case 0:
			return std::make_shared<CStage>(std::vector<std::string>
			{
				// ステージの生成
				"#####################",
				"#                   #",
				"#     ステージ１    #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                 o #",
				"#####################",
			});

		case 1:
			return std::make_shared<CStage>(std::vector<std::string>
			{
				// ステージの生成
				"#####################",
				"#                   #",
				"#     ステージ２    #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                 o #",
				"#####################",
			});

		case 2:
			return std::make_shared<CStage>(std::vector<std::string>
			{
				// ステージの生成
				"#####################",
				"#                   #",
				"#     ステージ３    #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                 o #",
				"#####################",
			});
		case 3:
			return std::make_shared<CStage>(std::vector<std::string>
			{
				// ステージの生成
				"#####################",
				"#                   #",
				"#    ステージ４     #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                 o #",
				"#####################",
			});

		case 4:
			return std::make_shared<CStage>(std::vector<std::string>
			{
				// ステージの生成
				"#####################",
				"#                   #",
				"#    ステージ５     #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                 o #",
				"#####################",
			});

		case 5:
			return std::make_shared<CStage>(std::vector<std::string>
			{
				// ステージの生成
				"#####################",
				"#                   #",
				"#    ステージ６     #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                 o #",
				"#####################",
			});

		case 6:
			return std::make_shared<CStage>(std::vector<std::string>
			{
				// ステージの生成
				"#####################",
				"#                   #",
				"#    ステージ７     #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                 o #",
				"#####################",
			});

		case 7:
			return std::make_shared<CStage>(std::vector<std::string>
			{
				// ステージの生成
				"#####################",
				"#                   #",
				"#    ステージ８     #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                 o #",
				"#####################",
			});

		case 8:
			return std::make_shared<CStage>(std::vector<std::string>
			{
				// ステージの生成
				"#####################",
				"#                   #",
				"#    ステージ９     #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                 o #",
				"#####################",
			});

		case 9:
			return std::make_shared<CStage>(std::vector<std::string>
			{
				// ステージの生成
				"#####################",
				"#                   #",
				"#    ステージ１０   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                   #",
				"#                 o #",
				"#####################",
			});
		}

		return nullptr;	//	無効なIDの場合はnullptrを返す
	}
};