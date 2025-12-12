#include"Stage.h"

void CStage::Draw() const
{
	// 画面クリア
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	// 範囲ループ
	for (const auto& line : Data)
	{
		std::cout << line << std::endl;
	}
}