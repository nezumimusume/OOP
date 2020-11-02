using AbstractFactory.Model;
using AbstractFactory.Sound;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AbstractFactory
{
    class Player
    {
        IModel model;
        /// <summary>
        /// コンストラクタ
        /// </summary>
        public Player()
        {
            switch (Game.instance.platform)
            {
                case Game.Platform.PS4:
                    model = new ModelPS4();
                    break;
                case Game.Platform.DX:
                    model = new ModelDX();
                    break;
            }
        }
        /// <summary>
        /// 更新
        /// </summary>
        public void Update()
        {
            Console.WriteLine("歩くかジャンプするか選んで下さい。");
            Console.WriteLine("0:歩く、1:ジャンプする");
            int pl = int.Parse(Console.ReadLine());
            if (pl == 0)
            {
                //歩く
                ISound s = null;
                switch (Game.instance.platform)
                {
                    case Game.Platform.PS4:
                        s = new SoundPS4();
                        break;
                    case Game.Platform.DX:
                        s = new SoundDX();
                        break;
                }
                s.Load("walk.wav");
                s.Play();
            }
            else
            {
                //ジャンプする
                ISound s = null;
                switch (Game.instance.platform)
                {
                    case Game.Platform.PS4:
                        s = new SoundPS4();
                        break;
                    case Game.Platform.DX:
                        s = new SoundDX();
                        break;
                }
                s.Load("jump.wav");
                s.Play();
            }
            //モデルを描画
            model.Draw();
        }
    }
}
