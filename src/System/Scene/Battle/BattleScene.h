#pragma once

#include "../IScene.h"

class BattleScene :public IScene
{
public:

	BattleScene();
	~BattleScene();

	void Update(double dt)override;
	void Draw()override;

};