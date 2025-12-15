#pragma once

namespace EcsSeq
{
	enum Type
	{
		Reset = 0,
		Bold = 1,
		Underline = 4,
		Reversed = 7,

		FG_Black = 30,
		FG_Red = 31,
		FG_Green = 32,
		FG_Yellow = 33,
		FG_Blue = 34,
		FG_Magenta = 35,
		FG_Cyan = 36,
		FG_White = 37,
		//		FG_Reset = 39,

		BG_Black = 40,
		BG_Red = 41,
		BG_Green = 42,
		BG_Yellow = 43,
		BG_Blue = 44,
		BG_Magenta = 45,
		BG_Cyan = 46,
		BG_White = 47,
		//		BG_Reset = 49,
	};
}