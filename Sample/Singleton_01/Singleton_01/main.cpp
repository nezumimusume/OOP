#include "stdafx.h"
#include "system/system.h"
#include "InGame.h"



///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    // ゲームの初期化
    InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));

    //////////////////////////////////////
    // ここから初期化を行うコードを記述する
    //////////////////////////////////////
    g_camera3D->SetPosition( 0.0f, 80.0f, 200.0f);
    g_camera3D->SetTarget( 0.0f, 80.0f, 0.0f );

    // step-5 Gameクラスのインスタンスを生成する。

    
    //////////////////////////////////////
    // 初期化を行うコードを書くのはここまで！！！
    //////////////////////////////////////
    auto& renderContext = g_graphicsEngine->GetRenderContext();

    // ここからゲームループ
    while (DispatchWindowMessage())
    {
        // 1フレームの開始
        g_engine->BeginFrame();
        
        // step-6 インゲームの更新処理と描画処理を実行する。

        // step-7 ゲームパッドの入力でGameクラスのインスタンスを新たに生成する。
        

        // 1フレーム終了
        g_engine->EndFrame();
    }
    return 0;
}


