using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Adapter
{
    class Game
    {
        public IModel model { get;  set; }
        public void Run()
        {
            while (true)
            {
                model.PreDraw();
                Thread.Sleep(100);      //100ミリ秒眠る
                model.Draw();
                Thread.Sleep(100);      //100ミリ秒眠る
                model.PostDraw();
            }
        }
    }
}
