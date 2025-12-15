#pragma once
#include <vector>
#include "drawble.h"
#include "IWindow.h"

//	ウィンドウクラス
class Window :public IWindow
{

	//	描画リスト
	std::vector<Drawble> drawList;

public:


	//	描画を行うメソッド
	void Draw();

	//	描画可能オブジェクトを追加するメソッド
	void AddDrawable(const Drawble& drawable) override;

private:

	//	テキストを描画するメソッド
	void drawText(const Drawble& drawable);



};

