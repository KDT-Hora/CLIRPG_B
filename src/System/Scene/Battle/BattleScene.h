#pragma once

#include "../IScene.h"
#include <memory>
#include "../../../BattleMG/BattleMG.h"

class BattleScene :public IScene
{
private:

	BattleMG battleMG;



public:

	BattleScene();
	~BattleScene();

	void Update(double dt)override;
	void Draw()override;

	void CreateEnemy();
};