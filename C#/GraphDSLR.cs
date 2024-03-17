using System;
using System.Text;
using System.Collections.Generic;


namespace GraphDSLR
{
    record struct History
    {
        public char alphabet;
        public int from;
    };

    internal class GraphDSLR
    {
        private static int D(int num)
        {
            return (2 * num) % 10_000;
        }
        private static int S(int num)
        {
            return (num - 1 < 0) ? 9999 : num - 1;
        }
        private static int L(int num)
        {
            return (num % 1000) * 10 + num / 1000;
        } // 1234 % 1000 = 234    ,   1234 / 1000 = 1
        private static int R(int num)
        {
            return (num % 10) * 1000 + num / 10;
        } // 1234 / 10 = 123     ,   1234 % 10 = 4 *1000

        public static void Print(ref StringBuilder sb, ref History[] path, int cur, ref int A)
        {
            if (cur == A) return;
            Print(ref sb, ref path, path[cur].from, ref A);
            sb.Append(path[cur].alphabet);

            return;
        }

        public static void Main()
        {
            var sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
            var sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));

            int testCase;
            int A, B;

            testCase = int.Parse(sr.ReadLine());

            while (testCase-- > 0)
            {
                string[] str = sr.ReadLine().Split(' ');
                A = int.Parse(str[0]);
                B = int.Parse(str[1]);

                bool[] updated = new bool[10_000];
                History[] path = new History[10_000];

                for (int i = 0; i < 10_000; i++)
                {
                    updated[i] = false;
                }

                int answer = A;
                updated[answer] = true;

                Queue<int> q = new();
                q.Enqueue(A);

                while (q.Count != 0)
                {
                    int current = q.Peek();
                    q.Dequeue();

                    answer = current;

                    int temp = D(answer);
                    if (!updated[temp])
                    {
                        q.Enqueue(temp);
                        updated[temp] = true;
                        path[temp].from = current;
                        path[temp].alphabet = 'D';
                    }
                    if (temp == B)
                    {
                        StringBuilder sb = new StringBuilder(100);
                        Print(ref sb, ref path, temp, ref A);
                        sw.WriteLine(sb.ToString());
                        break;
                    }

                    temp = L(answer);
                    if (!updated[temp])
                    {
                        q.Enqueue(temp);
                        updated[temp] = true;
                        path[temp].from = current;
                        path[temp].alphabet = 'L';
                    }
                    if (temp == B)
                    {
                        StringBuilder sb = new StringBuilder(100);
                        Print(ref sb, ref path, temp, ref A);
                        sw.WriteLine(sb.ToString());
                        break;
                    }

                    temp = S(answer);
                    if (!updated[temp])
                    {
                        q.Enqueue(temp);
                        updated[temp] = true;
                        path[temp].from = current;
                        path[temp].alphabet = 'S';
                    }
                    if (temp == B)
                    {
                        StringBuilder sb = new StringBuilder(100);
                        Print(ref sb, ref path, temp, ref A);
                        sw.WriteLine(sb.ToString());
                        break;
                    }

                    temp = R(answer);
                    if (!updated[temp])
                    {
                        q.Enqueue(temp);
                        updated[temp] = true;
                        path[temp].from = current;
                        path[temp].alphabet = 'R';
                    }
                    if (temp == B)
                    {
                        StringBuilder sb = new StringBuilder(100);
                        Print(ref sb, ref path, temp, ref A);
                        sw.WriteLine(sb.ToString());
                        break;
                    }
                }
            }
            sw.Flush();
            sr.Close();
            sw.Close();
        }   
    }
}
