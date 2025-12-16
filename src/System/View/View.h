#pragma once

#include <iostream>
#include <stralign.h>
#include <vector>

#include "../../singleton.h"

//	Viewクラス
//	各所からアクセスしたい都合と、描画バッファを2つでもつことないよねってことで
class View:public Singleton<View>
{
private:

	friend Singleton<View>;

	std::vector<std::string> cureentBuffer;
	std::vector<std::string> lastBuffer;

public:


	//	バッファクリア
	//	フレーム頭に呼び出し
	void Clear();

	//	バッファに追加
	//	各クラスからアクセス
	//	描画するものに追加
	void Add(const std::string& text);

	//	描画メソッド
	//	バッファにたまっているものを出力
	//	最初にバッファに前の描画と比較して異なっていたら描画
	void Update();

};
