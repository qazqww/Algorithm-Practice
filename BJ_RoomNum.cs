// 백준 알고리즘 : 방 번호
// https://www.acmicpc.net/problem/1475

using System;

namespace BJ_RoomNum
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int num = int.Parse(s);
            int[] nums = new int[10];
            int max = 0;
            int i;

            for (i = 0; i < s.Length; i++)
                nums[s[i] - 48]++;

            if ((nums[6] + nums[9]) % 2 == 1) nums[6] = (nums[6] + nums[9]) / 2 + 1;
            else nums[6] = (nums[6] + nums[9]) / 2;
            nums[9] = nums[6];

            for (i = 0; i < 10; i++)
                if (max < nums[i]) max = nums[i];

            Console.WriteLine(max);
        }
    }
}