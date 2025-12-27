#pragma once

#include "singleton.h"
#include <memory>

#include "System/Time/DeltaTime.h"

class GameManager:public Singleton<GameManager>
{
	friend Singleton<GameManager>;

	//	ŠÔŠÇ—ƒNƒ‰ƒX
	std::unique_ptr<DeltaTime> deltaTime;

public :

	void Init();
	void Run();

private:

	void update();
	void draw();

};

