using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Adapter
{
    class snModelPS4
    {
        public void draw()
        {
            Console.WriteLine("DrawPS4!!!");
        }
        public void beginDraw()
        {
            Console.WriteLine("DirectX beginDraw!!!");
        }
        public void endDraw()
        {
            Console.WriteLine("DirectX endDraw!!!");
        }
    }
}
