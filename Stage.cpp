#include"Stage.h"

void CStage::Draw() const
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	// ”ÍˆÍƒ‹[ƒv
	for (const auto& line : Data)
	{
		std::cout << line << std::endl;
	}
}