#include "Window.h"
#include "Drawble.h"
#include <iostream>

void Window::Draw()
{
	for(auto& drawable : this->drawList) {
		this->drawText(drawable);
	}
}

//	描画可能オブジェクトを追加するメソッド
void Window::AddDrawable(const Drawble& drawable)
{
	this->drawList.push_back(drawable);
}

//	テキストを描画するメソッド
void Window::drawText(const Drawble& drawable)
{
	std::cout << "\x1b[" 
		<< static_cast<int>(drawable.color) << "m" 
		<< drawable.text 
		<< "\x1b[0m";
}
