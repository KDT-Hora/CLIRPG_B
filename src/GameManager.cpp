#include "GameManager.h"


#include "System/Window/Window.h"
#include "System/Time/DeltaTime.h"
#include "System/Scene/SceneMG.h"

#include "System/Input/InputMG.h"
#include "System/View/View.h"

void GameManager::Init()
{
	this->window = std::make_unique<Window>();
	this->deltaTime = std::make_unique<DeltaTime>();
	this->sceneMG = std::make_unique<SceneMG>();
}

void GameManager::Run()
{
	while (true)
	{
		//	システム的な更新
		View::Instance().Clear();
		InputMG::Instance().Update();

		this->update();

		//	画面の更新
		View::Instance().Update();

		//	強制終了
		//	デバッグ用処理
		if (InputMG::Instance().GetKey() == InputMG::Key::CANCEL)
		{
			break;
		}

	}

}

void GameManager::update()
{

	auto dt = deltaTime->GetSeconds();
	this->sceneMG->Update(dt);

}

