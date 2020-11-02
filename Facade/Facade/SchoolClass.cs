using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    /// <summary>
    /// 学校のクラス
    /// </summary>
    class SchoolClass
    {
        /// <summary>
        /// 生徒の名前のリスト。
        /// </summary>
        public List<string> names { get; set; }
        /// <summary>
        /// CSVファイルからクラスの情報をロード。。
        /// </summary>
        /// <param name="csvFileName"></param>
        public void LoadFromCSV(string csvFileName)
        {
            names = new List<string>();
            StreamReader sr = new StreamReader(csvFileName);
            while (!sr.EndOfStream)
            {
                //1行読み込み
                var line = sr.ReadLine();
                var values = line.Split(',');
                foreach (var value in values)
                {
                    names.Add(value);
                }
            }
        }
    }
}
