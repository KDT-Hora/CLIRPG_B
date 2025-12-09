#pragma once

#include "Window.h"

class GameManager
{
public :

	void Run();

private:
	
	Window window;

	void update();
	void draw();

};

