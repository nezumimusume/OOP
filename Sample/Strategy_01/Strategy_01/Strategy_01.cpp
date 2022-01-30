// Strategy_01.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <Windows.h>
#include "Enemy.h"
#include "EnemyMoveRandom.h"

bool isPRessAButtonLast = false;
bool isPressAButton = false;
bool isTriggerAButton = false;

bool isPRessBButtonLast = false;
bool isPressBButton = false;
bool isTriggerBButton = false;

void UpdateKeyInput()
{
    isPRessAButtonLast = isPressAButton;
    if (GetAsyncKeyState('A')) {
        // キーボードのAが押された。
        isPressAButton = true;
    }
    if (isPressAButton == true && isPRessAButtonLast == false) {
        // トリガー入力。
        isTriggerAButton = true;
    }
    else {
        isTriggerAButton = false;
    }

    isPRessBButtonLast = isPressBButton;
    if (GetAsyncKeyState('B')) {
        // キーボードのBが押された。
        isPressBButton = true;
    }
    if (isPressBButton == true && isPRessBButtonLast == false) {
        // トリガー入力。
        isTriggerBButton = true;
    }
    else {
        isTriggerBButton = false;
    }
}
int main()
{
    Enemy enemy;
    while (true) {
        // キー入力を更新。
        UpdateKeyInput();
       
        if (isTriggerAButton) {
            // Aボタンが押された。
            enemy.ChangeMove(new EnemyMoveRandom);
        }
        if (isTriggerBButton) {
            // Bボタンが押された。
            
        }
        enemy.Update();
        Sleep(1000);
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
