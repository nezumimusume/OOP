using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    /// <summary>
    /// テストの結果クラス。
    /// </summary>
    class TestResult
    {
        /// <summary>
        /// 点数のリスト。
        /// </summary>
        public List<int> scores { get; set; }
        /// <summary>
        /// 試験名。
        /// </summary>
        public string name { get; set; }
        /// <summary>
        /// CSVファイルからテストの結果を読み込み。
        /// </summary>
        public void LoadFromCSV(string csvFileName)
        {
            scores = new List<int>();
            StreamReader sr = new StreamReader(csvFileName);
            while (!sr.EndOfStream)
            {
                //1行読み込み
                var line = sr.ReadLine();
                var values = line.Split(',');
                foreach (var value in values)
                {
                    if (name == null)
                    {
                        //先頭には試験名が入っている。
                        name = value;
                    }
                    else
                    {
                        scores.Add(int.Parse(value));
                    }
                }
            }
        }

    }
}
