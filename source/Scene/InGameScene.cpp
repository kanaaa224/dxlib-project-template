//////////////////////////////////////////////////
// ゲームメイン シーン
// 作成: Kanato Shimabukuro
//////////////////////////////////////////////////

#include "InGameScene.h"
#include "../Utility/ResourceManager.h"
#include "../Utility/InputCtrl.h"
#include "../Utility/FPS.h"
#include "DxLib.h"

InGameScene::InGameScene() {}
InGameScene::~InGameScene() {}

void InGameScene::Initialize() {
    ResourceManager* rm = ResourceManager::GetInstance();

    return __super::Initialize();
}

eSceneType InGameScene::Update(const float& delta_second) {
    if (InputCtrl::GetKeyState(KEY_INPUT_1)) FPS::SetLimitRate(10.0f);
    if (InputCtrl::GetKeyState(KEY_INPUT_2)) FPS::SetLimitRate(20.0f);
    if (InputCtrl::GetKeyState(KEY_INPUT_3)) FPS::SetLimitRate(30.0f);

    return __super::Update(delta_second);
}

void InGameScene::Draw() const {
    SetFontSize(16);

    DrawFormatString(10, 40, GetColor(255, 255, 255), "This is the GameMain.");

    return __super::Draw();
}

void InGameScene::Finalize() {
    return __super::Finalize();
}

const eSceneType InGameScene::GetNowSceneType() const {
    return eSceneType::in_game;
}