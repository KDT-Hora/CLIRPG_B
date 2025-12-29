#include "PartyMG.h"

#include "../CharacterState.h"

void PartyMG::Init()
{
	//	念のためクリア
	partyMembers.clear();

	//	キャラクター作成
	//	基準ステータスを取得して、特徴のある部分だけ変更
	Status sta1;
	sta1.STR = 15;
	sta1.VIT = 12;
	partyMembers.push_back(std::make_shared<Character>("name",Faction::Player,sta1));


	Status sta2;
	sta2.INT = 15;
	sta2.MND = 12;
	partyMembers.push_back(std::make_shared<Character>("name2", Faction::Player, sta2));

	Status sta3;
	sta3.AGI = 15;
	sta3.STR = 12;
	partyMembers.push_back(std::make_shared<Character>("name3", Faction::Player, sta3));

	Status sta4;
	sta4.VIT = 15;
	sta4.MND = 12;
	partyMembers.push_back(std::make_shared<Character>("name4", Faction::Player, sta4));
}

//	メンバーを追加するメソッド
void PartyMG::AddMember(std::shared_ptr<Character> charactor)
{
	//	引数で受け取ったメンバーを編成に追加

	//	最大なら何もしない
	if (partyMembers.size() >= PARTY_MAX)
	{
		return;
	}

	partyMembers.push_back(charactor);

}

const std::vector<std::shared_ptr<Character>>& PartyMG::GetParty() const
{
	// TODO: return ステートメントをここに挿入します
	return partyMembers;
}
