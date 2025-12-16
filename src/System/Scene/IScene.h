#pragma once


class IScene
{
public:

	virtual ~IScene() = default;
	virtual void Update(double dt) = 0;
	virtual void Draw() = 0;

};


enum class SceneType
{
	Title,
	Field,
	Battle,
	Result,
	
};
