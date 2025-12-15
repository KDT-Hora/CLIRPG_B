#pragma once

#include "../IScene.h"

class TitleScene:public IScene
{
public:

	TitleScene();
	~TitleScene();
	
	void Update(double dt)override;
	void Draw()override;

};