using System;
using System.Collections.Generic;

namespace DivideConquer_ColorPaper
{
    internal class DivideConquer_ColorPaper
    {
        public static void calculation(int[,] matrix, int size, ref int white, ref int black, int startRow, int startCol)
        {
            bool whiteB = false;
            bool blackB = false;

            for (int i = startRow; i < startRow + size; i++)
            {
                for (int j = startCol; j < startCol + size; j++)
                {
                    if (matrix[i, j] == 1)
                        blackB = true;
                    else if (matrix[i, j] == 0)
                        whiteB = true;
                    if (whiteB && blackB)
                    {
                        calculation(matrix, size / 2, ref white, ref black, startRow, startCol);
                        calculation(matrix, size / 2, ref white, ref black, startRow + size / 2, startCol);
                        calculation(matrix, size / 2, ref white, ref black, startRow, startCol + size / 2);
                        calculation(matrix, size / 2, ref white, ref black, startRow + size / 2, startCol + size / 2);
                        return;
                    }
                }
            }

            if (whiteB) white++;
            if (blackB) black++;
        }
      
        public static void Main()
        {
            var sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
            var sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));

            int N = int.Parse(sr.ReadLine());
            int[, ] matrix = new int[N, N];

            for (int i = 0; i < N; i++)
            {
                string[] temp = sr.ReadLine().Split(' ');
                    ;
                for (int j = 0; j < N; j++)
                {
                    matrix[i, j] = int.Parse(temp[j]);
                }
            }

            int white = 0;
            int black = 0;
            calculation(matrix, N, ref white, ref black, 0, 0);

            sw.WriteLine(white);
            sw.WriteLine(black);

            sw.Flush();

            sr.Close();
            sw.Close();
        }
    }
}
