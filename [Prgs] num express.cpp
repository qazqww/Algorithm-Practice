// 프로그래머스 알고리즘 : 숫자의 표현
// https://programmers.co.kr/learn/courses/30/lessons/12924

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	for (int i = 1; i <= n / 2; i = i + 2)
		if (n%i == 0 && n / i - i / 2 > 0) answer++;

	for (int i = 2; i <= n / 2; i = i + 2)
		if (n%i != 0 && n % (i / 2) == 0) {
			if ((n / (i / 2)) % 2 == 1 && n / i - i / 2 + 1 > 0) answer++;
		}

	return answer;
}

int main()
{
	cout << solution(15) << endl;
    return 0;
}

