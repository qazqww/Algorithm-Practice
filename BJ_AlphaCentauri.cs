// 백준 알고리즘 : Fly me to the Alpha Centauri
// https://www.acmicpc.net/problem/1011

using System;

namespace BJ_AlphaCentauri
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int count = int.Parse(s);
            string temp;
            int[] diff = new int[count];
            int i;
            int minus, answer;
            for (i = 0; i < count; i++)
            {
                temp = Console.ReadLine();
                diff[i] = int.Parse(temp.Split()[1]) - int.Parse(temp.Split()[0]);
            }

            for (i = 0; i < count; i++)
            {
                answer = 0;
                minus = 1;
                while (diff[i] > 0)
                {
                    diff[i] -= minus;
                    answer++;
                    if (diff[i] > 0)
                    {
                        diff[i] -= minus;
                        answer++;
                        minus++;
                    }
                }
                Console.WriteLine(answer);
            }
        }
    }
}