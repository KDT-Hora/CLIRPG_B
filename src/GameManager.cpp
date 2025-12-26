#include "GameManager.h"


#include "System/Window/Window.h"
#include "System/Time/DeltaTime.h"
#include "System/Scene/SceneMG.h"

#include "System/Input/InputMG.h"

void GameManager::Init()
{
	this->window = std::make_unique<Window>();
	this->deltaTime = std::make_unique<DeltaTime>();
	this->sceneMG = std::make_unique<SceneMG>();
	
	// デバッグ用
//	this->Field = std::make_unique<FieldController>();
}

void GameManager::Run()
{
	while (true)
	{
		//	システム的な更新
		InputMG::Instance().Update();

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
	this->sceneMG->Update(dt);

	// デバッグ用
//	this->Field->Update(dt);
}

void GameManager::draw()
{
	// デバッグ用
//	this->Field->Draw();
}