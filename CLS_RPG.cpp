#include <iostream>
#include <chrono>
#include <thread>
#include "Input.h"

// ゲームの更新処理
void GameUpdate() {
	// キー入力の更新
	auto& input = Input::Instance();
	// キー入力の更新処理を呼び出す
	if (input.IsKeyPressed('1')) {
		std::cout << "攻撃" << std::endl;
	}
	// キーが押されている間
	if (input.IsKeyDown('2')) {
		std::cout << "守る" << std::endl;
	}
	// キーが離された瞬間
	if (input.IsKeyReleased('3')) {
		std::cout << "回復" << std::endl;
	}

	// エンターキーが押されたら終了
	if (input.IsKeyPressed(VK_RETURN)) {
		exit(0);
	}
	
}

int main()
{
	std::cout << "1～3の数字を入力してください。" << std::endl;

	auto& input = Input::Instance();

	const int FPS = 60;
	const auto frameTime = std::chrono::milliseconds(1000 / FPS);

	while (true)
	{
		auto frameStart = std::chrono::steady_clock::now();

		// 入力更新
		input.Update();

		// ゲーム処理（ゲームロジック）
		GameUpdate();

		// FPS制御
		auto frameEnd = std::chrono::steady_clock::now();
		auto elapsed = frameEnd - frameStart;

		if (elapsed < frameTime)
		{
			std::this_thread::sleep_for(frameTime - elapsed);
		}
	}

	return 0;
}