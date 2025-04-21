//////////////////////////////////////////////////
// シーン マネージャー
// 作成: Kanato Shimabukuro
//////////////////////////////////////////////////

#pragma once

#include "SceneBase.h"

class SceneManager {
private:
    SceneBase* current_scene;

public:
    SceneManager();
    ~SceneManager();

    void Startup();
    void Run();
    void Shutdown();

private:
    void Draw() const;
    void ChangeScene(eSceneType next_type);
    SceneBase* CreateScene(eSceneType next_type);
};