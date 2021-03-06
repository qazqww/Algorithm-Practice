// 카카오 블라인트 테스트 : 비밀지도
// https://programmers.co.kr/learn/courses/30/lessons/17681

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string IntToBin(int num) {
	string bin;
	while (num >= 1) {
		if (num % 2 == 0) bin += "0";
		else bin += "1";
		num /= 2;
	}
	reverse(bin.begin(), bin.end());
	return bin;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	string bin, temp;
	int needZero;

	for (int i = 0; i < arr1.size(); i++) {
		temp = "";
		bin = IntToBin(arr1[i] | arr2[i]);
		needZero = n - bin.length();

		if (needZero == 0) answer.push_back(bin);
		else {
			for (int j = 0; j < needZero; j++) temp += "0";
			answer.push_back(temp + bin);
		}
		replace(answer[i].begin(), answer[i].end(), '1', '#');
		replace(answer[i].begin(), answer[i].end(), '0', ' ');
	}

	return answer;
}


int main()
{
	vector<string> sol;
	sol = solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21 ,17, 28 });
	for (int i = 0; i < sol.size(); i++) cout << sol[i] << endl;
	
	cout << endl;
	sol = solution(6, { 46, 33, 33, 22, 31, 50 }, { 27, 56, 19, 14, 14, 10 });
	for (int i = 0; i < sol.size(); i++) cout << sol[i] << endl;

    return 0;
}

