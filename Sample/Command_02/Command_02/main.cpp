#include "stdafx.h"
#include "system/system.h"
#include <deque>


class ActionCommand {
public:
    virtual void Execute() = 0;
    virtual void Undo() = 0;
};
// 上移動。
class UpCommand : public ActionCommand {
private:
    Vector3* m_pos;
    Vector3 m_oldPos;
public:
    UpCommand( Vector3& pos ) :
        m_pos(&pos){}
    void Execute() 
    {
        // 移動前の座標を記憶する。
        m_oldPos = *m_pos;
        m_pos->y += 10.0f;
    }
    void Undo()
    {
        *m_pos = m_oldPos;
    }
};
// 下移動。
class DownCommand : public ActionCommand {
private:
    Vector3* m_pos;
    Vector3 m_oldPos;
public:
    DownCommand(Vector3& pos) :
        m_pos(&pos) {}
    void Execute() 
    {
        m_oldPos = *m_pos;
        m_pos->y -= 10.0f;
    }
    void Undo()
    {
        *m_pos = m_oldPos;
    }
};
// 右移動。
class RightCommand : public ActionCommand {
private:
    Vector3* m_pos;
    Vector3 m_oldPos;
public:
    RightCommand(Vector3& pos) :
        m_pos(&pos) {}
    void Execute()
    {
        m_oldPos = *m_pos;
        m_pos->x -= 10.0f;
    }
    void Undo()
    {
        *m_pos = m_oldPos;
    }
};
// 右移動。
class LeftCommand : public ActionCommand {
private:
    Vector3* m_pos;
    Vector3 m_oldPos;
public:
    LeftCommand(Vector3& pos) :
        m_pos(&pos) {}
    void Execute()
    {
        m_oldPos = *m_pos;
        m_pos->x += 10.0f;
    }
    void Undo()
    {
        *m_pos = m_oldPos;
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

    

    ModelInitData modelInitData;
    modelInitData.m_tkmFilePath = "Assets/modelData/unityChan.tkm";
    modelInitData.m_fxFilePath = "Assets/shader/model.fx";
    
   
    Model model;
    model.Init(modelInitData);
    
    Vector3 pos;
    // 各種アクションコマンドを初期化。
   
    /*UpCommand upCommand(m_modelPos);
    DownCommand downCommand( m_modelPos );
    RightCommand rightCommand( m_modelPos );
    LeftCommand leftCommand( m_modelPos );
    */
    using ActionCommandPtr = std::shared_ptr<ActionCommand>;
    std::deque<ActionCommandPtr> m_commandList;
    

    //////////////////////////////////////
    // 初期化を行うコードを書くのはここまで！！！
    //////////////////////////////////////
    auto& renderContext = g_graphicsEngine->GetRenderContext();

    // ここからゲームループ
    while (DispatchWindowMessage())
    {
        // 1フレームの開始
        g_engine->BeginFrame();

        model.UpdateWorldMatrix(pos, g_quatIdentity, g_vec3One);
        model.Draw(renderContext);

        if (g_pad[0]->IsTrigger(enButtonUp)) {
            // 上移動コマンドを作成。
            auto command = std::make_shared<UpCommand>(pos);
            // コマンドを実行。
            command->Execute();
            // 実行済みのコマンドをリストに積む。
            m_commandList.push_back(command);
        }
        if (g_pad[0]->IsTrigger(enButtonDown)) {
            // 下移動コマンドを作成。
            auto command = std::make_shared<DownCommand>(pos);
            // コマンドを実行。
            command->Execute();
            // 実行済みのコマンドをリストに積む。
            m_commandList.push_back(command);
        }

        if (g_pad[0]->IsTrigger(enButtonRight)) {
            // 右移動コマンドを作成。
            auto command = std::make_shared<RightCommand>(pos);
            // コマンドを実行。
            command->Execute();
            // 実行済みのコマンドをリストに積む。
            m_commandList.push_back(command);
        }

        if (g_pad[0]->IsTrigger(enButtonLeft)) {
            // 左移動コマンドを作成。
            auto command = std::make_shared<LeftCommand>(pos);
            // コマンドを実行。
            command->Execute();
            // 実行済みのコマンドをリストに積む。
            m_commandList.push_back(command);
        }

        // アンドゥ
        if (g_pad[0]->IsTrigger(enButtonB) && m_commandList.empty() == false) {
            // リストの末尾の要素のアンドゥ処理を実行。
            m_commandList.back()->Undo();
            // リストの末尾の要素を削除
            m_commandList.pop_back();
        }
        // 実習課題。
        // リドゥを実装してください。
        

        // 1フレーム終了
        g_engine->EndFrame();
    }
    return 0;
}


