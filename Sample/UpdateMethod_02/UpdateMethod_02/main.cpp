﻿#include "stdafx.h"
#include "GameWorld.h"
#include "InGame.h"

int main()
{
    // ゲームワールドクラスのオブジェクトを定義。
    GameWorld gameWorld;

    // step-5 インゲームクラスのゲームオブジェクトを生成。
    
    // ゲームループを実行。
    gameWorld.ExecuteGameLoop();

    return 0;
}