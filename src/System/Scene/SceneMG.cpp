#include "SceneMG.h"

//	シーンの読み込み
#include "Title/Title.h"
#include "Field/FieldScene.h"
#include "Battle/BattleScene.h"

void SceneMG::Init()
{
	SetChange(SceneType::Title);
	changeExcute();
}

void SceneMG::Update(double dt)
{
	if (currentScene)
	{
		currentScene->Update(dt);
		currentScene->Draw();
	}

	if (change)
	{
		changeExcute();
	}
}

//	シーン切り替え設定
void SceneMG::SetChange(SceneType type)
{
	nextSceneType = type;
	change = true;
}

void SceneMG::changeExcute()
{
	switch (nextSceneType)
	{
	case SceneType::Title:		
		currentScene = std::make_unique<TitleScene>();
		break;

	case SceneType::Field:
		currentScene = std::make_unique<FieldScene>();
		break;

	case SceneType::Battle:
		currentScene = std::make_unique<BattleScene>();
		break;

	case SceneType::Result:
		currentScene = std::make_unique<TitleScene>();
		break;

	default:
		break;
	}

	//	フラグをおる
	change = false;
}