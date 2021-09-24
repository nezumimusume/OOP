#include "stdafx.h"
#include "system/system.h"
#include "Enemy.h"                                                                                                                                                                                                              

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
    g_camera3D->SetPosition( 0.0f, 100.0f, 250.0f);
    g_camera3D->SetTarget( 0.0f, 25.0f, 0.0f );
    
    // 背景モデルを初期化。
    Model model;
    ModelInitData modelInitData;
    modelInitData.m_tkmFilePath = "Assets/modelData/bg/bg.tkm";
    modelInitData.m_fxFilePath = "Assets/shader/model.fx";  
    model.Init(modelInitData);

    // 敵を初期化。
    Enemy enemy;
    
    //////////////////////////////////////
    // 初期化を行うコードを書くのはここまで！！！
    //////////////////////////////////////
    auto& renderContext = g_graphicsEngine->GetRenderContext();

    // ここからゲームループ
    while (DispatchWindowMessage())
    {
        // 1フレームの開始
        g_engine->BeginFrame();

        enemy.Update();
        enemy.Draw(renderContext);

        model.Draw(renderContext);

        // 1フレーム終了
        g_engine->EndFrame();
    }
    return 0;
}


