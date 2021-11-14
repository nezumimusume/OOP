// Sample_03_01.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <Windows.h>

// バイクの基底クラス。
class Bike {
public:
    virtual void Run()
    {
        std::cout << "普通の走行性能\n";
    }
    virtual void Accell()
    {
        std::cout << "普通のアクセル性能\n";
    }
    virtual void Brake()
    {
        std::cout << "普通のブレーキ性能\n";
    }
};

// スペシャルレアのバイク。
// Bikeクラスをpublic継承する。
// 走行性能だけスペシャルな性能。
class SRBike : public Q１_______________
{
public:
    // Run()関数をオーバーライドする。
    void Q２_______________()
    {
        std::cout << "SRバイクの走行性能\n";
    }
};
// スーパースペシャルレアのバイク。
// バイクベースを継承する。
// すべての性能がスペシャル！！！
class SSRBike : public Bike
{
public:
    // Run()関数をオーバーライドする。
    void Ｑ３_______________()
    {
        std::cout << "SSRバイクの走行性能\n";
    }
    // Accell()関数をオーバーライドする。
    void Ｑ４_______________()
    {
        std::cout << "SSRバイクのアクセル性能\n";
    }
    // Break()関数をオーバーライドする。
    void Ｑ５_______________()
    {
        std::cout << "SSRバイクのブレーキ性能\n";
    }
};
/// <summary>
/// メイン関数
/// </summary>
/// <returns></returns>
int main()
{
    std::cout << "使用するバイクを選んでください。\n";
    
    char useBike;
    while (true) {
        std::cout << "0 : 通常バイク、1 : SRバイク、2：SSRバイク\n";
        std::cin >> useBike;
        if (useBike >= '0' && useBike <= '2') {
            std::cout << "バイクが選ばれました。\n";
            break;
        }
        else {
            std::cout << "選んだバイクが不正です。\n";
            std::cout << "もう一度選択してください。\n";
        }
    }

    int bikeNo = static_cast<int>(useBike - '0');

    // 各種バイクを定義する。
    Bike normalBike;    // 通常バイク
    SRBike srBike;      // SRバイク
    SSRBike ssrBike;   // SSRバイク

    Bike* bike = nullptr;
    if (bikeNo == 0) {
        // 通常バイクを使用するので、
        // bike変数に通常バイクのオブジェクトのアドレスを代入する。
        bike = Ｑ６_______________;
    }
    if (bikeNo == 1) {
        // SRバイクを使用するので、
        // bike変数にSRバイクのオブジェクトのアドレスを代入する。
        bike = Ｑ７_______________;
    }
    if (bikeNo == 2) {
        bike = &ssrBike;
    }
    // ゲームループ
    while (true) {
        if (GetAsyncKeyState('A')) {
            // アクセル
            bike->Accell();
        }
        if (GetAsyncKeyState('B')) {
            // ブレーキ
            bike->Brake();
        }
        // 走行処理。
        bike->Run();
        Sleep(200);
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
