#include "SceneMG.h"

//	シーンの読み込み
#include "Title/Title.h"
#include "Field/FieldController.h"

//	一時的なインクルード
#include "../Input/InputMG.h"



SceneMG::SceneMG()
{
	this->changeExcute(SceneType::Title);
}

void SceneMG::Update(double dt)
{
	if (currentScene)
	{
		currentScene->Update(dt);
	}

	// シーン遷移処理があればここで実行
	if (change) 
	{
		// 実際はswitch文でnew Field(), new Battle()などを生成
		// currentScene = std::make_unique<FieldScene>(); 
		change = false;
	}
}

void SceneMG::Draw()
{
}

//	シーン切り替え設定
void SceneMG::SetChange(SceneType type)
{
	nextSceneType = type;
	change = true;
}

void SceneMG::changeExcute(SceneType type)
{
	if (type == SceneType::Title)
	{
		currentScene = std::make_unique<TitleScene>();
	}
	else if (type == SceneType::Field)
	{
		currentScene = std::make_unique<FieldController>();

	}
	else if (type == SceneType::Battle)
	{
		currentScene = std::make_unique<TitleScene>();

	}
	else if (type == SceneType::Result)
	{
		currentScene = std::make_unique<TitleScene>();

	}


}