// 2017 카카오 블라인드 테스트 : 다트 게임
// https://programmers.co.kr/learn/courses/30/lessons/17682

#include "stdafx.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int solution(string dartResult) {

	int answer = 0;
	int score[3] = { 0, 0, 0 };
	int count = 0;
	int i = 0;

	while (count <= 2) {

		if (dartResult[i] == '1' && dartResult[i + 1] == '0') {
			score[count] = 10;
			i++;
		}
		else
			score[count] = dartResult[i] - 48;
		i++;

		switch (dartResult[i]) {
		case 'D':
			score[count] = pow(score[count], 2);
			break;
		case 'T':
			score[count] = pow(score[count], 3);
			break;
		}
		i++;

		switch (dartResult[i]) {
		case '*':
			if (count > 0) score[count - 1] *= 2;
			score[count] *= 2;
			i++;
			break;
		case '#':
			score[count] *= -1;
			i++;
			break;
		}

		count++;
	}

	for (i = 0; i < count; i++) answer += score[i];
	return answer;
}

int main()
{
	cout << solution("1S2D*3T") << endl;
	cout << solution("1D2S#10S") << endl;
	cout << solution("1D2S0T") << endl;
	cout << solution("1S*2T*3S") << endl;
	cout << solution("1D#2S*3S") << endl;
	cout << solution("1T2D3D#") << endl;
	cout << solution("1D2S3T*") << endl;

    return 0;
}

