// 백준 알고리즘 : ACM 호텔
// https://www.acmicpc.net/problem/10250

using System;

namespace BJ_ACMhotel
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int count = int.Parse(s);
            int[] answer = new int[count];
            string temp;
            int dong, ho, i;
            for (i = 0; i < count; i++)
            {
                temp = Console.ReadLine();
                dong = int.Parse(temp.Split()[2]) % int.Parse(temp.Split()[0]);
                ho = int.Parse(temp.Split()[2]) / int.Parse(temp.Split()[0]) + 1;
                if (dong == 0)
                {
                    dong = int.Parse(temp.Split()[0]);
                    ho--;
                }
                answer[i] = dong * 100 + ho;
            }
            for (i = 0; i < count; i++)
                Console.WriteLine(answer[i]);
        }
    }
}