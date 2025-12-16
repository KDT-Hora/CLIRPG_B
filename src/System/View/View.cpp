#include "View.h"

void View::Clear()
{
	cureentBuffer.clear();
}

void View::Add(const std::string& text)
{
	cureentBuffer.push_back(text);
}

void View::Update()
{
	if (cureentBuffer == lastBuffer)
	{
		return;
	}

	//	‰æ–ÊƒNƒŠƒA
	system("cls");

	//	•`‰æ
	for (auto a : cureentBuffer)
	{
		std::cout << a << std::endl;
	}

}
