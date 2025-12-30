#pragma once

#include <vector>
#include <memory>

//	パーティの最大人数
#define PARTY_MAX 4

class Character;

class PartyMG
{
private:

	std::vector<std::shared_ptr<Character>> partyMembers;

public:

	void Init();
	void AddMember(std::shared_ptr<Character> charactor);
	const std::vector<std::shared_ptr<Character>>& GetParty() const;

};