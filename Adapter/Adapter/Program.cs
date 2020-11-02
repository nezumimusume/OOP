using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Adapter
{
    class Program
    {
        static void Main(string[] args)
        {
            Game game = new Game();
            while (true)
            {
                Console.WriteLine("プラットフォームを選択してください。");
                Console.WriteLine("0:DirectX、1:OpenGL、2:PS4");
                int pl = int.Parse(Console.ReadLine());
                //DirectX用のモデル描画処理のインスタンスを生成。
                if (pl == 0)
                {
                    game.model = new ModelDX();
                    break;
                }
                if (pl == 1)
                {
                    game.model = new ModelGL();
                    break;
                }
                if (pl == 2)
                {
                    //ModelPS4はベンダーが提供しているクラスなため変更できない。
                    //gameクラスも変更できない、どうすればいい？
                }
                
            }
            game.Run();
        }
    }
}
