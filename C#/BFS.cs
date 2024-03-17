using System;
using System.Collections.Generic;

namespace BFS
{
    internal class BFS
    {
        public static int BFS_calculation(ref List<int>[] edges) // test 'ref' keyword for memory - save pointer memory
        {
            int answer = 0;
            Queue<int> ints = new Queue<int>();
            bool[] visited = new bool[edges.Length];
            for (int i = 1; i < edges.Length; i++)
            {
                visited[i] = false;
            }

            visited[1] = true;
            ints.Enqueue(1);

            while (ints.Count > 0)
            {
                int current = ints.Dequeue();

                foreach (int i in edges[current])
                {
                    if (visited[i] == false)
                    {
                        visited[i] = true;
                        ints.Enqueue(i);
                        answer++;
                    }
                }
            }
            return answer;
        }
        public static void Main()
        {
            var sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
            var sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));

            int numVer = int.Parse(sr.ReadLine());
            int numEdg = int.Parse(sr.ReadLine());

            List<int>[] edges = new List<int>[numVer + 1]; // 1-indexing

            for (int i = 0; i < numVer + 1; i++)
            {
                edges[i] = new List<int>();
            }

            for (int i = 0; i < numEdg; i++)
            {
                int temp1, temp2;
                string[] str = sr.ReadLine().Split(' ');
                temp1 = int.Parse(str[0]);
                temp2 = int.Parse(str[1]);

                edges[temp1].Add(temp2);
                edges[temp2].Add(temp1);
            }

            sw.WriteLine(BFS_calculation(ref edges));

            sw.Flush();
            sw.Close();
            sr.Close();
        }
    }
}
