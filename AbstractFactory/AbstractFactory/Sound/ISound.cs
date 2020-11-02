using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AbstractFactory.Sound
{
    interface ISound
    {
        void Load(string fileName);
        void Play();
    }
}
