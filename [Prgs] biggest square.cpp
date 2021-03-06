// 프로그래머스 알고리즘 : 가장 큰 정사각형 찾기
// https://programmers.co.kr/learn/courses/30/lessons/12905

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
	int answer = 0;
	int lowest = 1000;
	int highest = 0;

	for (int y = 1; y<board.size(); y++)
		for (int x = 1; x<board[0].size(); x++) {
			if (board[y - 1][x - 1] != 0 && board[y - 1][x] != 0 &&
				board[y][x - 1] != 0 && board[y][x] != 0) {
				if (lowest > board[y - 1][x - 1]) lowest = board[y - 1][x - 1];
				if (lowest > board[y - 1][x]) lowest = board[y - 1][x];
				if (lowest > board[y][x - 1]) lowest = board[y][x - 1];
				board[y][x] = lowest + 1;
				lowest = 1000;
			}
		}

	for (int x = 0; x<board[0].size(); x++)
		for (int y = 0; y<board.size(); y++)
			if (highest < board[y][x]) highest = board[y][x];

	answer = highest * highest;
	return answer;
}

int main()
{
	cout << solution({ {0,1,1,1}, {1,1,1,1}, {1,1,1,1}, {0,0,1,0} }) << endl;
    return 0;
}

