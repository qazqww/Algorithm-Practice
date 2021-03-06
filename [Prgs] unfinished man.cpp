// 프로그래머스 알고리즘 : 완주하지 못한 선수
// https://programmers.co.kr/learn/courses/30/lessons/42576

#include "stdafx.h"
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	string str = "";
	int i;

	unordered_map<string, int> list;
	for (i = 0; i < completion.size(); i++) {
		list.insert({ completion[i], i + 1 });
	}

	unordered_map<string, int>::iterator iter;

	for (i = 0; i < participant.size(); i++) {
		iter = list.find(participant[i]);
		if (iter != list.end()) {
			list.erase(iter->first);
		}
		else {
			answer = participant[i];
			return answer;
		}
	}
	return answer;
}


int main()
{
	cout << solution({ "leo", "kiki", "eden" }, { "eden", "kiki" }) << endl;
	cout << solution({ "marina", "josipa", "nikola", "vinko", "filipa" }, { "josipa", "filipa", "marina", "nikola" }) << endl;
	cout << solution({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" }) << endl;
    return 0;
}

