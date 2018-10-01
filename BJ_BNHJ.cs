// 백준 알고리즘 : 부녀회장이 될테야
// https://www.acmicpc.net/problem/2775

using System;

namespace BJ_BNHJ
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int count = int.Parse(s);
            int i, j, k;
            int fmax = 0;
            int hmax = 0;
            int[] floor = new int[count];
            int[] ho = new int[count];
            int[,] mansion = new int[15, 15];
            for (i = 0; i < count; i++)
            {
                floor[i] = int.Parse(Console.ReadLine());
                ho[i] = int.Parse(Console.ReadLine());
            }

            for (i = 0; i < count; i++)
            {
                if (fmax < floor[i]) fmax = floor[i];
                if (hmax < ho[i]) hmax = ho[i];
            }

            for (i = 0; i <= fmax; i++)
                for (j = 0; j <= hmax; j++)
                {
                    if (i == 0) mansion[i, j] = j + 1;
                    else
                    {
                        for (k = 0; k <= j; k++)
                            mansion[i, j] += mansion[i - 1, k];
                    }
                }

            for (i = 0; i < count; i++)
            {
                Console.WriteLine(mansion[floor[i], ho[i] - 1]);
            }
        }
    }
}