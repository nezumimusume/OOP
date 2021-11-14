// Sample_03_01.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <Windows.h>

int SelectCar();

// step-1 車の基底クラスを定義する。
class Car {
public:
    virtual void Run()
    {
        std::cout << "普通車の走行性能\n";
    }
    virtual void Accell()
    {
        std::cout << "普通車のアクセル性能\n";
    }
    virtual void Brake()
    {
        std::cout << "普通車のブレーキ性能\n";
    }
    virtual void OpenDoor()
    {
        std::cout << "普通車の開閉処理\n";
    }
};

// step-2 Fitクラスを定義する。
// 何もかもが普通なので、処理のオーバーライドはしない
class Fit : public Car
{
};
// step-3 Tantクラスを作る
class Tant : public Car
{
public:
    void Run()
    {
        std::cout << "軽自動車の走行性能\n";
    }
    void Accell()
    {
        std::cout << "軽自動車のアクセル性能\n";
    }
    void Brake()
    {
        std::cout << "軽自動車のブレーキ性能\n";
    }
    void OpenDoor()
    {
        std::cout << "スライドドアの開閉処理\n";
    }
};

// step-4 フェラーリクラスを作る。
class Ferrari : public Car
{
    public:
    void Run()
    {
        std::cout << "スペシャルな走行性能\n";
    }
    void Accell()
    {
        std::cout << "スペシャルなアクセル性能\n";
    }
    void Brake()
    {
        std::cout << "スペシャルなブレーキ性能\n";
    }
    void OpenDoor()
    {
        std::cout << "ウィングドアの開閉処理\n";
    }
};
/// <summary>
/// メイン関数
/// </summary>
/// <returns></returns>
int main()
{
    // 使用する車を選択する。
    int carNo = SelectCar();

    // step-5 各種車を定義する。
    Fit fit;           // FIT 
    Tant tant;          // タント
    Ferrari ferrari;   //  フェラーリ

    // step-6 使用する車のアドレスをセットする。
    Car* car = nullptr;
    if (carNo == 0) {
        // fitを使用する。
        car = &fit;
    }
    if (carNo == 1) {
        // タントを使用する
        car = &tant;
    }
    if (carNo == 2) {
        // フェラーリを使用する。
        car = &ferrari;
    }
    // ゲームループ
    while (true) {
        // step-7 carクラスのポインタを使って、選択した車の各種処理を呼び出す。
        if (GetAsyncKeyState('A')) {
            // アクセル
            car->Accell();
        }
        if (GetAsyncKeyState('B')) {
            // ブレーキ
            car->Brake();
        }
        if( GetAsyncKeyState( 'D') ){
            // ドアを開く
            car->OpenDoor();
        }
        // 走行処理。
        car->Run();
        Sleep(200);
    }
}

int SelectCar()
{
    std::cout << "使用する車を選んでください。\n";
    
    char useCar;
    while (true) {
        std::cout << "0 : Fit、1 : タント、2：フェラーリ\n";
        std::cin >> useCar;
        if (useCar >= '0' && useCar <= '2') {
            std::cout << "車が選ばれました。\n";
            break;
        }
        else {
            std::cout << "選んだ車が不正です。\n";
            std::cout << "もう一度選択してください。\n";
        }
    }

    int carNo = static_cast<int>(useCar - '0');
    return carNo;
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
