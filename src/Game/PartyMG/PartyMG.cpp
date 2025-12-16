#include "PartyMG.h"

#include "../CharacterState.h"

void ParytMG::Init()
{
	//	念のためクリア
	partyMembers.clear();

	//	キャラクター作成
	//	基準ステータスを取得して、特徴のある部分だけ変更
	Status sta1;
	sta1.STR = 15;
	sta1.VIT = 12;
	partyMembers.push_back(std::make_shared<Character>(sta1));



}

//	メンバーを追加するメソッド
void ParytMG::AddMember(std::shared_ptr<Character> charactor)
{
	//	引数で受け取ったメンバーを編成に追加

	//	最大なら何もしない
	if (partyMembers.size() >= PARTY_MAX)
	{
		return;
	}

	partyMembers.push_back(charactor);

}

const std::vector<std::shared_ptr<Character>>& ParytMG::GetParty() const
{
	// TODO: return ステートメントをここに挿入します
	return partyMembers;
}
