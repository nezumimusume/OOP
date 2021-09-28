#include "stdafx.h"
#include "system/system.h"


enum EnAnimClip {
    enAnimClip_Idle,
    enAnimClip_Run,
    enAnimClip_Jump,
    enAnimClip_Walk,
    enAnimClip_Num,
};
// アクションコマンドのインターフェースクラス。
class ActionCommand {
public:
    virtual void Execute(Animation& anim) = 0;
};
// ジャンプアクション。
class JumpCommand : public ActionCommand {
public:
    void Execute(Animation& anim) {
        anim.Play(enAnimClip_Jump);
    }
};
// 待機アクション
class IdleCommand : public ActionCommand {
public:
    void Execute(Animation& anim) {
        anim.Play(enAnimClip_Idle);
    }
};
// 走りアクション
class RunCommand : public ActionCommand {
public:
    void Execute(Animation& anim) {
        anim.Play(enAnimClip_Run);
    }
};
// 歩き
class WalkCommand : public ActionCommand {
public:
    void Execute(Animation& anim) {
        anim.Play(enAnimClip_Walk);
    }
};
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

    Skeleton skeleton;
    skeleton.Init("Assets/modelData/unityChan.tks");

    ModelInitData modelInitData;
    modelInitData.m_tkmFilePath = "Assets/modelData/unityChan.tkm";
    modelInitData.m_fxFilePath = "Assets/shader/model.fx";
    modelInitData.m_vsSkinEntryPointFunc = "VSSkinMain";
    modelInitData.m_modelUpAxis = enModelUpAxisY;   
    modelInitData.m_skeleton = &skeleton;
    Model model;
    model.Init(modelInitData);
    
    AnimationClip animClips[enAnimClip_Num];
    animClips[enAnimClip_Idle].Load("Assets/animData/idle.tka");
    animClips[enAnimClip_Idle].SetLoopFlag(true);
    animClips[enAnimClip_Run].Load("Assets/animData/run.tka");
    animClips[enAnimClip_Run].SetLoopFlag(true);

    animClips[enAnimClip_Jump].Load("Assets/animData/jump.tka");
    animClips[enAnimClip_Walk].Load("Assets/animData/walk.tka");
    animClips[enAnimClip_Walk].SetLoopFlag(true);

    //アニメーションを初期化。
    Animation animation;
    animation.Init(
        skeleton,			//アニメーションを流し込むスケルトン。
        animClips,	//アニメーションクリップ。
        enAnimClip_Num		//アニメーションの数。
    );

    // 各種アクションコマンドを初期化。
    // Aボタンが押された時のコマンド
    JumpCommand jumpCommand;
    RunCommand runCommand;
    WalkCommand walkCommand;
    IdleCommand idleCommand;

    // Aボタンが押された時のコマンド。
    ActionCommand* commandA = &jumpCommand;
    // Bボタンが押された時のコマンド。
    ActionCommand* commandB = &runCommand;
    // Xボタンが押された時のコマンド。
    ActionCommand* commandX = &walkCommand;
    // Yボタン押された時のコマンド。
    ActionCommand* commandY = &idleCommand;

    //////////////////////////////////////
    // 初期化を行うコードを書くのはここまで！！！
    //////////////////////////////////////
    auto& renderContext = g_graphicsEngine->GetRenderContext();

    // ここからゲームループ
    while (DispatchWindowMessage())
    {
        // 1フレームの開始
        g_engine->BeginFrame();

        animation.Progress(1.0f / 60.0f);
        skeleton.Update(model.GetWorldMatrix());
        model.Draw(renderContext);

        if (g_pad[0]->IsTrigger(enButtonA)) {
            commandA->Execute(animation);
        }
        if (g_pad[0]->IsTrigger(enButtonB)) {
            commandB->Execute(animation);
        }
        if (g_pad[0]->IsTrigger(enButtonX)) {
            commandX->Execute(animation);
        }
        if (g_pad[0]->IsTrigger(enButtonY)) {
            commandY->Execute(animation);
        }
        // 1フレーム終了
        g_engine->EndFrame();
    }
    return 0;
}


