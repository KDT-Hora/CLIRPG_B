#pragma once
#include <string>
#include "EscSequence.h"

//	描画可能オブジェクト構造体
struct Drawble
{
	EcsSeq::Type color = EcsSeq::Type::Reset;
	std::string text;
};