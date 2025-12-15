#pragma once

struct Drawble;

class IWindow
{
public:
	virtual ~IWindow() = default;

	virtual void AddDrawable(const Drawble& drawable) = 0;

};