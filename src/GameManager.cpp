#include "GameManager.h"


void GameManager::Run()
{
	int i = 0;
	while (true)
	{
		this->update();

		i++;
		if(i == 1000) {
			window.AddDrawable(
				{ EcsSeq::Type::Reset,
				"Hello, World!\n" });
		}
		this->draw();
		if(i >= 1005) {
			break;
		}
	}
}

void GameManager::update()
{
	
}

void GameManager::draw()
{
	// ウィンドウに描画を指示する
	this->window.Draw();
}
