using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2x2MatrixRecursiveIterativeSearch
{
    internal class _2x2MatrixRecursiveIterativeSearch
    {
        static int count = 0;

        static int matrixSize;
        static int targetRow;
        static int targetCol;

        static int order = 0b00; // use bit mask

        static void searchMatrix(ref int topLeftRow, ref int topLeftCol, ref int botRightRow, ref int botRightCol)
        {
            int newTLR, newTLC, newBRR, newBRC;

            if (targetRow <= topLeftRow + (botRightRow - topLeftRow) / 2)
            {
                newTLR = topLeftRow;
                newBRR = topLeftRow + (botRightRow - topLeftRow) / 2;
                order &= ~(1 << 0);
            }
            else
            {
                newTLR = topLeftRow + (botRightRow - topLeftRow) / 2 + 1;
                newBRR = topLeftRow + (botRightRow - topLeftRow);
                order |= (1 << 0);
            }

            if (targetCol <= topLeftCol + (botRightCol - topLeftCol) / 2)
            {
                newTLC = topLeftCol;
                newBRC = topLeftCol + (botRightCol - topLeftCol) / 2;
                order &= ~(1 << 1);
            }
            else
            {
                newTLC = topLeftCol + (botRightCol - topLeftCol) / 2 + 1;
                newBRC = topLeftCol + (botRightCol - topLeftCol);
                order |= (1 << 1);
            }

            topLeftRow = newTLR;
            topLeftCol = newTLC;
            botRightRow = newBRR;
            botRightCol = newBRC;
        }

        static void Main()
        {
            string[] str = Console.ReadLine()!.Split();

            matrixSize = int.Parse(str[0]);
            targetRow = int.Parse(str[1]);
            targetCol = int.Parse(str[2]);

            int tLR = 0;
            int tLC = 0;
            int bRR = (1 << matrixSize) - 1;
            int bLC = (1 << matrixSize) - 1;

            while (bRR - tLR != 1)
            {
                searchMatrix(ref tLR, ref tLC, ref bRR, ref bLC);

                switch (order)
                {
                    case 0:
                        count += (bRR - tLR + 1) * (bRR - tLR + 1) * 0;
                        break;
                    case 1:
                        count += (bRR - tLR + 1) * (bRR - tLR + 1) * 2;
                        break;
                    case 2:
                        count += (bRR - tLR + 1) * (bRR - tLR + 1) * 1;
                        break;
                    case 3:
                        count += (bRR - tLR + 1) * (bRR - tLR + 1) * 3;
                        break;
                    default:
                        break;
                }
            }

            count += (targetRow - tLR) * 2 + (targetCol - tLC);

            Console.Write(count);
        }
    }
}
