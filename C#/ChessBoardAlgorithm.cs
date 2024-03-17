using System;
using System.Collections.Specialized;

namespace ChessBoardAlgorithm
{
    internal class ChessBoardAlgorithm
    {
        static void Main()
        {
            int[] rowColNum = Array.ConvertAll(Console.ReadLine()!.Split(' '), int.Parse);
            char[][] chessBoard = new char[rowColNum[0]][];
            
            for (int i = 0; i < rowColNum[0]; i++)
            {
                chessBoard[i] = Console.ReadLine()!.ToCharArray();
            }
            // chessBoard[i][j] = char doesn't work.

            int cnt1 = Int32.MaxValue, cnt2 = Int32.MaxValue;
            
            for (int tempRow = 0; tempRow <= rowColNum[0] - 8; tempRow++)
            {
                for (int tempCol = 0;tempCol <= rowColNum[1] - 8; tempCol++)
                {
                    int tempCnt1 = 0, tempCnt2 = 0;
                    for (int row = tempRow; row < 8 + tempRow; row++)
                    {
                        for (int col = tempCol; col < 8 + tempCol; col++)
                        {
                            if ((row - tempRow) % 2 == 0)
                            {
                                if ((col - tempCol) % 2 == 0 && chessBoard[row][col] != 'W')
                                {
                                    tempCnt1++;
                                }
                                else if ((col - tempCol) % 2 == 1 && chessBoard[row][col] != 'B')
                                {
                                    tempCnt1++;
                                }

                                if ((col - tempCol) % 2 == 0 && chessBoard[row][col] != 'B')
                                {
                                    tempCnt2++;
                                }
                                else if ((col - tempCol) % 2 == 1 && chessBoard[row][col] != 'W')
                                {
                                    tempCnt2++;
                                }
                            }
                            else if ((row - tempRow) % 2 == 1)
                            {
                                if ((col - tempCol) % 2 == 0 && chessBoard[row][col] != 'B')
                                {
                                    tempCnt1++;
                                }
                                else if ((col - tempCol) % 2 == 1 && chessBoard[row][col] != 'W')
                                {
                                    tempCnt1++;
                                }

                                if ((col - tempCol) % 2 == 0 && chessBoard[row][col] != 'W')
                                {
                                    tempCnt2++;
                                }
                                else if ((col - tempCol) % 2 == 1 && chessBoard[row][col] != 'B')
                                {
                                    tempCnt2++;
                                }
                            }
                        }
                    }
                    if (cnt1 > tempCnt1) cnt1 = tempCnt1;
                    if (cnt2 > tempCnt2) cnt2 = tempCnt2;
                }
            }

            Console.WriteLine($"{cnt1} , and , {cnt2}");

            Console.WriteLine(MathF.Min(cnt1, cnt2));
        }
    }
}