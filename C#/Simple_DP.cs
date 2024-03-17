using System;
using System.Collections.Generic;

namespace Simple_DP
{
    internal class Simple_DP
    {
        public static void Main()
        {
            var sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
            var sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));

            int[] answers = { 1, 1, 2, 4, 0, 0, 0, 0, 0, 0, 0 };

            int testCase = int.Parse(sr.ReadLine());

            for (int i = 4; i < answers.Length; i++)
            {
                answers[i] = answers[i - 3] + answers[i - 2] + answers[i - 1];
            }

            for (int i = 0; i < testCase; i++)
            {
                int temp = int.Parse(sr.ReadLine());
                sw.WriteLine(answers[temp]);
            }

            sw.Flush();

            sr.Close();
            sw.Close();
        }
    }
}
