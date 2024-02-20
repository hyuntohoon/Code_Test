// ConsoleApplication5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

vector<vector<int>> board, tempBoard;
int N, M, D;
int manualPopcount(unsigned int n) {
	int count = 0;
	while (n) {
		count += n & 1; // n의 가장 오른쪽 비트가 1인지 확인
		n >>= 1; // n을 오른쪽으로 1비트 이동
	}
	return count;
}
int answer = -1;

void moveEnemies() {
	for (int i = N - 1; i > 0; i--) {
		tempBoard[i] = tempBoard[i - 1];
	}
	tempBoard[0] = vector<int>(M, 0);
}
int attackEnemies(int archers) {
	int count = 0;
	tempBoard = board;
	FOR(i, N) {
		vector<pair<int,int>> targets;
		FOR(j, M) {
			if ((archers >> j) & 1) {
				int minDist = D + 1, targetY = -1, targetX = -1;
				for (int r = N - 1; r >= 0; r--) {
					FOR(c, M) {
						if (tempBoard[r][c] == 1 && abs(N - r) + abs(j - c) <= D) { //거리내
							int dist = abs(N - r) + abs(j - c);
							if (dist < minDist || (dist == minDist && c < targetY)) {
								targetX = r;
								targetY = c;
								minDist = dist;
							}
						}
					}
				}
				if (targetY != -1) {
					targets.push_back({ targetX, targetY });
				}
			}
		}
		sort(targets.begin(), targets.end());
		targets.erase(unique(targets.begin(), targets.end()), targets.end());
		count += targets.size();
		for (auto &target : targets) {
			tempBoard[target.first][target.second] = 0;
		}
		moveEnemies();
	}
	return count;
}

int main()
{

	 cin >> N >> M >> D;

	board.assign(N, vector<int>(M));
	FOR(i, N) {
		FOR(j, M) {
			cin >> board[i][j];
		}
	}
	for (int bit = 0; bit < (1 << M); bit++) {
		if (manualPopcount(bit) == 3) {
			answer = max(answer, attackEnemies(bit));
		}
	}
	cout << answer;
}
