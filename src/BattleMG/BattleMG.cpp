#include "BattleMG.h"
#include "../System/View/View.h"
#include "../System/Input/InputMG.h"
#include "../Game/CharacterState.h" // Faction等の定義がある想定
#include <algorithm>

BattleMG::~BattleMG() = default;

void BattleMG::Start(const std::vector<std::shared_ptr<Character>>& players,
    const std::vector<std::shared_ptr<Character>>& enemies) {

    characters.clear();

    for (auto& p : players) characters.push_back(p);
    for (auto& e : enemies) characters.push_back(e);

    ChangeState(BattleState::Init);
}

void BattleMG::ChangeState(BattleState newState) {
    currentState = newState;
}

void BattleMG::Update() {
    // 共通の描画処理（毎フレーム現在のHPなどを表示）
    DrawStatus();

    switch (currentState) {
    case BattleState::Init:          UpdateInit();          break;
    case BattleState::OrderStep:     UpdateOrderStep();     break;
    case BattleState::ActionStep:    UpdateActionStep();    break;
    case BattleState::CheckEnd:      UpdateCheckEnd();      break;
    case BattleState::ResultDisplay: UpdateResultDisplay(); break;
    case BattleState::End:                                  break;
    }

    View::Instance().Add("---------------------------");
    View::Instance().Add(battleLog);
}

void BattleMG::Draw()
{
   //   状態に応じて描画処理を行う
    switch (currentState)
    {
    case BattleState::Init:
		DrawInit();
        break;
    case BattleState::OrderStep:
		DrawOrderStep();
        break;
    case BattleState::ActionStep:
		DrawActionStep();
        break;
    case BattleState::CheckEnd:
		DrawCheckEnd();
        break;
    case BattleState::ResultDisplay:
		DrawResultDisplay();
        break;
    case BattleState::End:

        break;
    default:
        break;
    }
}


void BattleMG::UpdateInit() {
    battleLog = "戦闘開始！";
    //  スペースキーの入力で次へ
    if (InputMG::Instance().ChechKey(InputMG::Key::ENTER)) {
        ChangeState(BattleState::OrderStep);
    }
}

void BattleMG::UpdateOrderStep() {
    turnOrder = characters;
    // 素早さ順にソート
    std::sort(turnOrder.begin(), turnOrder.end(), [](const auto& a, const auto& b) {
        return a->GetState().AGI > b->GetState().AGI;
        });

    currentActorIndex = 0;
    battleLog = "行動順を決定しました。";
    if (InputMG::Instance().ChechKey(InputMG::Key::ENTER)) {
        ChangeState(BattleState::OrderStep);
    }
}

void BattleMG::UpdateActionStep() {

    if (currentActorIndex >= turnOrder.size()) {
        // 全員の行動終了、次のターンへ
        ChangeState(BattleState::OrderStep);
        return;
    }

    auto actor = turnOrder[currentActorIndex];
    if (actor->IsLife()) {
        // 本来はここでターゲット選択ロジックを入れる
        // 今回は簡易的に生存している敵対勢力を探す
        for (auto& target : characters) {
            if (target->GetFaction() != actor->GetFaction() && target->IsLife()) {
                actor->Attack(*target);
                battleLog = actor->GetName() + " の攻撃！";
                break;
            }
        }
    }

    currentActorIndex++;
    ChangeState(BattleState::CheckEnd); // 1人動くたびに終了判定
}

void BattleMG::UpdateCheckEnd() {
    if (IsAllDead((int)Faction::Enemy)) {
        result = BattleResult::Win;
        ChangeState(BattleState::ResultDisplay);
    }
    else if (IsAllDead((int)Faction::Player)) {
        result = BattleResult::Lose;
        ChangeState(BattleState::ResultDisplay);
    }
    else {
        // 続行なら次の人の行動へ
        ChangeState(BattleState::ActionStep);
    }
}

void BattleMG::UpdateResultDisplay() {
    battleLog = (result == BattleResult::Win) ? "勝利！" : "敗北...";
    View::Instance().Add("Push Any Key to End...");

    // 何らかの入力があったら終了へ（簡易実装として1フレームで飛ばす）
    ChangeState(BattleState::End);
}

void BattleMG::DrawInit()
{
}

void BattleMG::DrawOrderStep()
{
}

void BattleMG::DrawActionStep()
{
}

void BattleMG::DrawCheckEnd()
{
}

void BattleMG::DrawResultDisplay()
{
}

void BattleMG::DrawStatus() {
    View& view = View::Instance();
    view.Add("=== BATTLE FIELD ===");
    for (const auto& c : characters) {
        std::string info = (c->IsLife() ? "[ALV]" : "[DED]");
        info += " " + c->GetName() + " HP: " + std::to_string(c->GetHP());
        view.Add(info);
    }
}

bool BattleMG::IsAllDead(int faction) const {
    for (const auto& c : characters) {
        if ((int)c->GetFaction() == faction && c->IsLife()) return false;
    }
    return true;
}