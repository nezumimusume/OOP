// Adapter_01.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <Windows.h>
#include <iostream>
#include "ModelDx11.h"
// step-3 ModelDx10.hをインクルードする。
#include "ModelDx10.h"
#include "ModelDX12.h"

int main()
{
    char graphicsAPI = 0;
    while (true) {
        std::cout << "描画APIを選んでください。0 : DirectX10、1 : DirectX11、2 : DirectX12\n";

        std::cin >> graphicsAPI;
        if (graphicsAPI >= '0' && graphicsAPI <= '2') {
            if (graphicsAPI)
                break;
        }
        else {
            std::cout << "選んだプラットフォームが不正です。\n";
            std::cout << "もう一度選択してください。\n";
        }
    }

    // 選ばれた描画APIに応じて、適切なモデル描画処理のインスタンスを生成する。
    IModel* model = nullptr;
    switch (graphicsAPI) {
    case '0':
        // step-4 ModelDx10のインスタンスを作成する。
        model = new ModelDx10;
        break;
    case '1':
        model = new ModelDx11;
        break;
    case '2':
        model = new ModelDx12;
        break;
    }
    // モデルの初期化処理。
    model->Init();

    // ゲームループ。
    while (true) {
        model->BeginDraw();
        model->Draw();
        model->EndDraw();
        Sleep(100);
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
