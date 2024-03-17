using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FloydAllShortestPaths
{
    internal class FloydAllShortestPaths
    {
        static void Main()
        {
            string[] str = Console.ReadLine()!.Split(' ');

            int vertexNum = int.Parse(str[0]);
            int edgeNum = int.Parse(str[1]);

            int[,] matrix = new int[vertexNum + 1, vertexNum + 1];

            for (int i = 1; i < vertexNum + 1; i++)
            {
                for (int j = 1; j < vertexNum + 1; j++)
                {
                    if (i == j)
                    {
                        matrix[i, j] = 0;
                        continue;
                    }
                    matrix[i, j] = Int32.MaxValue;
                }
            }

            int a, b;
            for (int i = 0; i < edgeNum; i++)
            {
                str = Console.ReadLine()!.Split(' ');
                a = int.Parse(str[0]);
                b = int.Parse(str[1]);

                matrix[a, b] = 1;
                matrix[b, a] = 1;
            }

            for (int k = 1; k < vertexNum + 1; k++)
            {
                for (int i = 1; i < vertexNum + 1; i++)
                {
                    for (int j = 1; j < vertexNum + 1; j++)
                    {
                        if (matrix[i, k] != Int32.MaxValue && matrix[k,j] != Int32.MaxValue && matrix[i,j] > matrix[i,k] + matrix[k, j])
                        {
                            matrix[i, j] = matrix[i, k] + matrix[k, j];
                            matrix[j, i] = matrix[i, j];
                        }
                    }
                }
            }

            int min = Int32.MaxValue;
            int minIndex = 0;

            for (int i = 1; i < vertexNum + 1; i++)
            {
                for (int j = 1; j < vertexNum + 1; j++)
                {
                    if (i == j)
                    {
                        continue;
                    }
                    matrix[i, i] += matrix[i, j];
                }
                if (min > matrix[i, i])
                {
                    min = matrix[i,i]; minIndex = i;
                }
            }

            Console.WriteLine(minIndex);
        }
    }
}

// 6028 KB	64 ms