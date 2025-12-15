#pragma once

#include <memory>
#include <iostream>
#include "map"

#include "IScene.h"

class SceneMG
{
private:

	std::unique_ptr<IScene> currentScene;
	SceneType nextSceneType;
 
	bool change = false;

	
public:

	SceneMG();
	
	void Update(double dt);

	void Draw();

	void SetChange(SceneType type);
	
private:

	void changeExcute(SceneType type);


};