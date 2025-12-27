#include "Title.h"
#include "../../../System/Input/InputMG.h"
#include "../../../System/View/View.h"

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
}

void TitleScene::Draw()
{
	std::string text = "Title Sence";
	View::Instance().Add(text);
}
