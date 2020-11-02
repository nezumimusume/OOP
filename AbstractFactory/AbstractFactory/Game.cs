using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AbstractFactory
{
    class Game
    {
        public enum Platform
        {
            PS4,
            DX
        }
        public static Game instance{get;set;}
        public Platform platform { get; private set; }
        public Game()
        {
            instance = this;
        }
        public void GameLoop()
        {
            Console.WriteLine("プラットフォームを選択してください。");
            Console.WriteLine("0:PS4、1:DX");
            int pl = int.Parse(Console.ReadLine());
            if(pl == 0)
            {
                platform = Platform.PS4;
            }else
            {
                platform = Platform.DX;
            }
            Player player = new Player();
            while (true)
            {
                player.Update();
            }
        }
    }
}
