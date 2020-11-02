using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            //まずはAクラスの情報をロード。
            SchoolClass sclass = new SchoolClass();
            sclass.LoadFromCSV("../../class_A.csv");
            //試験の情報をロード。
            TestResult testResult = new TestResult();
            testResult.LoadFromCSV("../../TestResult_A.csv");
            //試験結果に生徒の名前を結合して、新しいファイルとして出力。
            StreamWriter sr = new StreamWriter("../../TestResultEx_A.csv");
            //最初に試験名を追加する・
            sr.WriteLine(testResult.name);
            //生徒の数と試験の結果数は同じになるはずなので
            for(int i = 0; i < sclass.names.Count; i++)
            {
                sr.WriteLine(string.Format("{0}, {1}", sclass.names[i], testResult.scores[i]));
            }
            sr.Close();

            //続いてBクラスの情報をロード。
            sclass = new SchoolClass();
            sclass.LoadFromCSV("../../class_B.csv");
            //試験の情報をロード。
            testResult = new TestResult();
            testResult.LoadFromCSV("../../TestResult_B.csv");
            //試験結果に生徒の名前を結合して、新しいファイルとして出力。
            sr = new StreamWriter("../../TestResultEx_B.csv");
            //最初に試験名を追加する・
            sr.WriteLine(testResult.name);
            //生徒の数と試験の結果数は同じになるはずなので
            for (int i = 0; i < sclass.names.Count; i++)
            {
                sr.WriteLine(string.Format("{0}, {1}", sclass.names[i], testResult.scores[i]));
            }
            sr.Close();
        }
    }
}
