using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Adapter
{
    class ModelDX : IModel
    {
        public void PreDraw()
        {
            Console.WriteLine("DirectX Draw!!!");
        }
        public void Draw()
        {
            Console.WriteLine("DirectX PreDraw!!!");
        }
        public void PostDraw()
        {
            Console.WriteLine("DirectX PostDraw!!!");
        }
    }
}
