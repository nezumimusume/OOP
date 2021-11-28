// Facade_01.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "RenderContext.h"

class Model {
private:
    Texture m_tex;
    VertexBuffer m_vertexBuffer;
    IndexBuffer m_indexBuffer;
public:
    void Draw(RenderContext& rc)
    {
        rc.SetIndexBuffer(m_indexBuffer);
        rc.SetVertexBuffer(m_vertexBuffer);
        rc.SetTexture(m_tex);
        rc.Draw();
    }
};
int main()
{
    // レンダリングコンテキスト
    RenderContext rc;

    // 背景のモデルを描画するための各種データを用意する。
    Model bgModel;

    // プレイヤーキャラクターのモデルを描画するための各種データを用意する。
    Model plModel;

    // 敵キャラクターのモデルを描画するための各種データを用意する。
    Model enModel;

    while (true)
    {
        // 背景を描画する。
        bgModel.Draw(rc);

        // プレイヤーを描画する。
        plModel.Draw(rc);

        // 敵を描画する。
        enModel.Draw(rc);
    }

}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
