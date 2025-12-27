#include "FieldViewSystem.h"

#include <iostream>
#include <cstdlib>

void FieldViewSystem::Clear()
{
	// ‰æ–Ê‚ÌƒNƒŠƒA
	system("cls");
}

void FieldViewSystem::DrawField(const MapData& m_Map, const Player& m_Player, const Npc& m_Npc)
{
	// •`‰æ‚ğŒÄ‚Ño‚·
	Map_Render.Draw(m_Map, m_Player, m_Npc);
}