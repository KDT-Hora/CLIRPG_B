#include "Input.h"

//　キー入力の更新処理
void Input::Update()
{
    //　キー入力状態の保存
    prevKey = key;

	//　キー入力状態の取得
    for (int i = 0; i < KEY_NUM; i++)
    {
        SHORT s = GetAsyncKeyState(i);
        key[i] = (s & 0x8000) != 0;
    }
}

//　キー入力の取得処理
bool Input::IsKeyDown(int k)
{
	//　キーが押されているかを返す
    return key[k];
}
//　押された瞬間の取得処理
bool Input::IsKeyPressed(int k)
{
	//　キーが押された瞬間かを返す
    return key[k] && !prevKey[k];
}
//　離した瞬間の取得処理
bool Input::IsKeyReleased(int k)
{
	//　キーが離された瞬間かを返す
    return !key[k] && prevKey[k];
}