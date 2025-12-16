#include "View.h"

void View::Clear()
{
	cureentBuffer.clear();
}

void View::Add(const std::string& text)
{
	cureentBuffer.push_back(text);
}

void View::Update()
{
	if (cureentBuffer == lastBuffer)
	{
		return;
	}

	//	‚©‚«‚©‚¯
}
