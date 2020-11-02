using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AbstractFactory.Sound
{
    class SoundPS4 : ISound
    {
        string fileName;
        public void Load(string fileName)
        {
            this.fileName = fileName;
        }
        public void Play()
        {
            Console.WriteLine("SoundPS4.Play " + fileName);
        }
    }
}
