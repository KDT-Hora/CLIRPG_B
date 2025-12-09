#include "Window.h"
#include "Drawble.h"
#include <iostream>

void Window::Draw()
{
	
	//	画面をクリアする
	system("cls");


	//	描画リストが空なら何もしない
	if (drawList.empty()) {
		return;
	}

	//　描画リストの内容をすべて描画する
	for (auto drawable : this->drawList) {
		this->drawText(drawable);
	}

	//	描画リストをクリアする
	this->drawList.clear();
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
