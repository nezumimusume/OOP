using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AbstractFactory
{
    class Program
    {
        static void Main(string[] args)
        {
            //Gameのインスタンスを作成。
            Game game = new Game();
            game.GameLoop();
        }
    }
}
