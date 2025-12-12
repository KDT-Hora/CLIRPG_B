#pragma once
#include <iostream>

// キー入力クラス

class CKeyInput
{
private:

	// キー入力取得変数
	char key; 

public:

	// コピー・代入禁止
	CKeyInput(const CKeyInput&) = delete;
	CKeyInput& operator=(const CKeyInput&) = delete;

	// シングルトン
	static CKeyInput& GetInstance()
	{
		static CKeyInput instance;
		return instance;
	}

	// コンストラクタ
	CKeyInput()
	: key(' ') 
	{}
	// デストラクタ
	virtual ~CKeyInput() 
	{}

	// キー入力取得関数
	char GetKey();
};
