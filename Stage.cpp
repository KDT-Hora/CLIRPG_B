#include"Stage.h"

void CStage::DrawWithPlayer(int player_x, int player_y) const
{
	// 画面クリア
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif

	// バッファにステージデータをコピー
	std::vector<std::string> buffer = Data;

	// プレイヤーの位置にキャラクターを配置
	if (player_y >= 0 && player_y < height &&
		player_x >= 0 && player_x < width)
	{
		buffer[player_y][player_x] = '@';
	}


	// 範囲ループ
	for (auto& line : buffer)
	{
		// 表示の切り替え
		for (char& c : line)
		{
			// 外枠
			if (c == '#') c = '■';
			// 階段
			if (c == 'c') c = '〇';
		}

		std::cout << line << std::endl;
	}
}

bool CStage::IsWall(int x, int y) const
{
	// 範囲外は壁扱い
	if (x < 0 || x >= width || y < 0 || y >= height)
	{
		return true;
	}
	
	// 図形を返す
	return Data[y][x] == '#';
}

bool CStage::IsEvent(int x, int y) const
{
	// マスを指定する
	if (x < 0 || x >= width || y < 0 || y >= height)
	{
		return false;
	}

	return Data[y][x] == 'o';
}
