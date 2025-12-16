#include "Title.h"
#include "../../../System/Input/InputMG.h"

//	一時的なインクルード
#include <iostream>

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{
}

void TitleScene::Update(double dt)
{
	system("cls");

	std::cout << "Title" << std::endl;
}

void TitleScene::Draw()
{
}
