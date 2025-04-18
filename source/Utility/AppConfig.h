//////////////////////////////////////////////////
// アプリケーション 構成
// 作成: Kanato Shimabukuro
//////////////////////////////////////////////////

#pragma once

#include <string>

#define	D_SUCCESS (0)
#define	D_FAILURE (-1)

#define D_SCREEN_WIDTH (1280)
#define D_SCREEN_HEIGHT (720)
#define D_COLOR_BIT (32)

#define D_FPS (60)

#define D_APP_NAME "DxLib"

#define DEBUG 1

void FrameControl();

const float& GetDeltaSecond();

int ErrorThrow(std::string error_log);