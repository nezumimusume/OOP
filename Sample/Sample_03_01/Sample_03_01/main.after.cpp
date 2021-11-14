// Sample_03_01.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <Windows.h>
#include "ITouch.h"
#include "TouchIOS.h"
#include "TouchAndroid.h"

/// <summary>
/// メイン関数
/// </summary>
/// <returns></returns>
int main()
{
    
   
    char platform = 0;
    while (true) {
        std::cout << "プラットフォームを選んでください。0 : iOS、1 : Android\n";
        
        std::cin >> platform;
        if (platform >= '0' && platform <= '1') {
            if( platform)
            break;
        }
        else {
            std::cout << "選んだプラットフォームが不正です。\n";
            std::cout << "もう一度選択してください。\n";
        }
    }

    // step-6 選ばれたプラットフォームに応じて、タッチ入力処理のインスタンスを作成する。
    ITouch* touch = nullptr;
    switch (platform) {
    case '0':
        touch = new TouchIOS;
        break;
    case '1':
        touch = new TouchAndroid;
        break;
    }
    // ゲームループ
    while (true) {
        // step-7 タッチ入力の各種処理を呼び出す。
        if (touch->IsPressTouch()) {
            // タッチされていたら座標を取得する。
            float x, y;
            touch->GetTouchPosition(x, y);
        }
        
        Sleep(200);
    }
    delete touch;
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
