#include "GameManager.h"


#include "System/Time/DeltaTime.h"
#include "System/Scene/SceneMG.h"
#include "System/View/View.h"
#include "System/Input/InputMG.h"

void GameManager::Init()
{
	this->deltaTime = std::make_unique<DeltaTime>();
	SceneMG::Instance().Init();
}

void GameManager::Run()
{
	while (true)
	{
		//	システム的な更新
		InputMG::Instance().Update();
		View::Instance().ClearBuffer();

		this->update();
		this->draw();

		if (InputMG::Instance().GetKey() == InputMG::Key::CANCEL)
		{
			break;
		}

	}

}

void GameManager::update()
{

	auto dt = deltaTime->GetSeconds();
	SceneMG::Instance().Update(dt);

}

void GameManager::draw()
{
	//	描画システム更新
	View::Instance().Update();

}
