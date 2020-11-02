using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AbstractFactory.Model
{
    class ModelPS4 : IModel
    {
        public void Draw()
        {
            Console.WriteLine("ModelPS4.Draw");
        }
    }
}
