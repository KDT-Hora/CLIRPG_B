#pragma once

#include "singleton.h"
#include <memory>

#include "System/Time/DeltaTime.h"

// デバッグ用
#include "System/Scene/Field/FieldScene.h"

class GameManager:public Singleton<GameManager>
{
	friend Singleton<GameManager>;

	//	時間管理クラス
	std::unique_ptr<DeltaTime> deltaTime;

public :

	void Init();
	void Run();

private:

	void update();
	void draw();
};

