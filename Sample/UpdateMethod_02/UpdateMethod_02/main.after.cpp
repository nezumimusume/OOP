#include "stdafx.h"
#include "GameWorld.h"
#include "InGame.h"

int main()
{
    // ゲームワールドクラスのオブジェクトを定義。
    GameWorld gameWorld;
    // step-4 インゲームクラスのゲームオブジェクトを生成。
    gameWorld.NewGameObject<InGame>();
    // ゲームループを実行。
    gameWorld.ExecuteGameLoop();

    return 0;
}
