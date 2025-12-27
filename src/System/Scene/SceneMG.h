#pragma once

#include <memory>
#include <iostream>

#include "../../singleton.h"

#include "IScene.h"

class SceneMG:public Singleton<SceneMG>
{
	friend Singleton<SceneMG>;

private:

	std::unique_ptr<IScene> currentScene;
	SceneType nextSceneType;
 
	bool change = false;

	
public:
	
	void Init();

	void Update(double dt);

	void SetChange(SceneType type);
	
private:

	void changeExcute();


};