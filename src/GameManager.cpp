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
}

void GameManager::Run()
{
	while (true)
	{
		//	システム的な更新
		InputMG::Instance().Update();

		this->update();
		this->draw();
	}

}

void GameManager::update()
{

	auto dt = deltaTime->GetSeconds();
	this->sceneMG->Update(dt);

}

void GameManager::draw()
{


}
