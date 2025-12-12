#include "GameManager.h"

#include "Window.h"

void GameManager::Init()
{
	this->window = std::make_unique<Window>();
}

void GameManager::Run()
{
	while (true)
	{
		this->update();
		this->draw();
	}
}

void GameManager::update()
{
}
void GameManager::draw()
{
	this->window->Draw();
}
