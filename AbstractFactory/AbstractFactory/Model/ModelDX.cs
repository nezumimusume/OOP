using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AbstractFactory.Model
{
    class ModelDX : IModel
    {
        public void Draw()
        {
            Console.WriteLine("ModelDX.Draw");
        }
    }
}
