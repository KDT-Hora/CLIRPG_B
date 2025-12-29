#include "Title.h"
#include "../../../System/Input/InputMG.h"
#include "../../../System/View/View.h"

#include "../SceneMG.h"

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
	if (InputMG::Instance().ChechKey(InputMG::Key::ENTER))
	{
		SceneMG::Instance().SetChange(SceneType::Field);
	}
}

void TitleScene::Draw()
{
	std::string text = "Title Sence";
	View::Instance().Add(text);
}
