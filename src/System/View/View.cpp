#include "View.h"

void View::ClearBuffer()
{
	//	バッファのデータを移動させる
	lastBuffer = cureentBuffer;
	cureentBuffer.clear();
}

void View::Add(const std::string& text)
{
	cureentBuffer.push_back(text);
}

void View::Update()
{
	//	前の描画と比較して、同じならスルー
	if (cureentBuffer == lastBuffer)
	{
		return;
	}

	//	画面クリア
	system("cls");

	//	描画
	for (auto a : cureentBuffer)
	{
		std::cout << a << std::endl;
	}

}
