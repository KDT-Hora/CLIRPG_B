#pragma once
#include <iostream>
#include <array>
#include <Windows.h>

// 入管理クラス
class Input
{
public:
    //　シングルトンの取得
    static Input& Instance()
    {
        //　静的ローカル変数のシングルトン
        static Input instance;
        //　シングルトンを返す
        return instance;
    }

    //　キー入力の更新処理
    void Update();

    //　キー入力の取得処理
    bool IsKeyDown(int key);
    //　押されたら瞬間
    bool IsKeyPressed(int key);
    //　離した瞬間　
    bool IsKeyReleased(int key);

private:
    Input() {}  // コンストラクタ非公開
	~Input() {} // デストラクタ非公開
    //　コピーコンストラクタ・代入演算子を削除　
    Input(const Input&) = delete;
    void operator=(const Input&) = delete;

	//　キー入力配列
	static const int KEY_NUM = 256;         //　キーの数
	std::array<bool, KEY_NUM> key{};        //　現在のキー入力状態
	std::array<bool, KEY_NUM> prevKey{};    //　一つ前のキー入力状態
};