#pragma once


#include <memory>

#include "Window.h"

class GameManager
{
	//	画面ウィンドウ
	std::unique_ptr<Window> window;


public :

	void Init();
	void Run();

private:

	void update();
	void draw();

};

