// Facade_01.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "RenderContext.h"

int main()
{
    // レンダリングコンテキスト
    RenderContext rc;

    // 背景のモデルを描画するための各種データを用意する。
    Texture bgTex;
    VertexBuffer bgVertexBuffer;
    IndexBuffer bgIndexBuffer;

    // プレイヤーキャラクターのモデルを描画するための各種データを用意する。
    Texture plTex;
    VertexBuffer plVertexBuffer;
    IndexBuffer plIndexBuffer;

    // 敵キャラクターのモデルを描画するための各種データを用意する。
    Texture enTex;
    VertexBuffer enVertexBuffer;
    IndexBuffer enIndexBuffer;

    while (true)
    {
        // 背景を描画する。
        rc.SetIndexBuffer(bgIndexBuffer);
        rc.SetVertexBuffer(bgVertexBuffer);
        rc.SetTexture(bgTex);
        rc.Draw();

        // プレイヤーを描画する。
        rc.SetIndexBuffer(plIndexBuffer);
        rc.SetVertexBuffer(plVertexBuffer);
        rc.SetTexture(plTex);
        rc.Draw();

        // 敵を描画する。
        rc.SetIndexBuffer(enIndexBuffer);
        rc.SetVertexBuffer(enVertexBuffer);
        rc.SetTexture(enTex);
        rc.Draw();
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
