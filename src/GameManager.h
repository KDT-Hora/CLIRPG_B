#pragma once

#include "singleton.h"
#include <memory>

//class Window;
//class DeltaTime;
//class SceneMG;
#include "System/Window/Window.h"
#include "System/Time/DeltaTime.h"
#include "System/Scene/SceneMG.h"

class GameManager:public Singleton<GameManager>
{
	friend Singleton<GameManager>;

	//	画面ウィンドウ
	std::unique_ptr<Window> window;
	//	時間管理クラス
	std::unique_ptr<DeltaTime> deltaTime;
	//	シーン管理クラス
	std::unique_ptr<SceneMG> sceneMG;

public :

	void Init();
	void Run();

private:

	void update();
	void draw();

};

