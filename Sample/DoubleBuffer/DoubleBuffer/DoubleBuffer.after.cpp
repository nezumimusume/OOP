// DoubleBuffer.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>

class GPU {
private:
    // フレームバッファ。
    struct FrameBuffer {
        char colorBuffer[8][8];
    };
    std::mutex m_mutex;
    volatile bool m_wait = true;
    volatile bool m_isEnd = true;
    FrameBuffer m_frameBuffer[2];
    int m_frontBufferNo = 0;
public:
    GPU()
    {
        memset(m_frameBuffer[0].colorBuffer, ' ', sizeof(m_frameBuffer[0].colorBuffer));
        memset(m_frameBuffer[1].colorBuffer, ' ', sizeof(m_frameBuffer[1].colorBuffer));
    }
    void Start()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_wait = false;
        m_isEnd = false;
    }
    void Wait()
    {
        // スピンロックを行う。
        while (m_wait) {}
    }
    bool IsEnd() const
    {
        return m_isEnd;
    }
    void Draw(int x, int y, char c) 
    {
        m_frameBuffer[1^m_frontBufferNo].colorBuffer[y][x] = c;
    }
    // フレームバッファをクリア
    void ClearFrameBuffer()
    {
        memset(m_frameBuffer[1^m_frontBufferNo].colorBuffer, ' ', sizeof(m_frameBuffer[1^m_frontBufferNo].colorBuffer));
    }
    void Run()
    {

        while (true) {
            Wait();
            std::lock_guard<std::mutex> lock(m_mutex);
            m_isEnd = false;
            m_wait = true;

            //標準出力コンソールのハンドルを取得。
            HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD pos;
            pos.X = 0;
            pos.Y = 0;
            //標準コンソールのカーソルを0行目、0列に戻す。
            SetConsoleCursorPosition(hCons, pos);
           // std::system("cls");
            // フレームバッファの内容を書き込んでいく。
            for (int y = 0; y < 8; y++) {
                for (int x = 0; x < 8; x++) {
                    printf("%c", m_frameBuffer[m_frontBufferNo].colorBuffer[y][x]);
                }
                printf("\n");
                // ディスプレイのリフレッシュレートに時間がかかっていることを体感するために、
                // 少し眠らせる。
                Sleep(10);
                
            }
            // バッファを入れ替える。
            m_frontBufferNo = 1 ^ m_frontBufferNo;
            // 終わり。
            m_isEnd = true;
        }
    }
};

char sikakuPrimitive[4][4] = {
    {'*','*','*','*'},
    {'*','*','*','*'},
    {'*','*','*','*'},
    {'*','*','*','*'}
};

int main()
{
    GPU gpu;
    // GPUスレッドを作成。
    auto gpuThread = std::make_unique<std::thread>([&] {
        gpu.Run();
    });
    int shikakuPosX = 0;
    int shikakuPosY = 0;
    // ゲームループ
    while (true) {
        // GPUを走らせる。
        gpu.Start();
        // フレームバッファをクリア。
        gpu.ClearFrameBuffer();
        // 絵を書く。
        // Aボタンが押されたら■を描画する。
        if (GetAsyncKeyState(VK_LEFT)) {
            shikakuPosX = max(0, shikakuPosX - 1);
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            shikakuPosX = min(4, shikakuPosX + 1);
        }
        if (GetAsyncKeyState(VK_UP)) {
            shikakuPosY = max(0, shikakuPosY - 1);
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            shikakuPosY = min(4, shikakuPosY + 1);
        }
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                gpu.Draw(x + shikakuPosX, y + shikakuPosY, sikakuPrimitive[y][x]);
            }
            Sleep(10);
        }
        
        
        
        // GPUと同期をとる。
        while(gpu.IsEnd() ){}
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
