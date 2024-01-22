#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, M;
char arr[11][11];

pair <int, int> RED, BLUE;
queue <pair<int, int>> Q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int result = 987654321;

void input() {
	cin >> N >> M;;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B')
			{
				BLUE.first = j; 
				BLUE.second = i; 
				arr[i][j] = '.'; 
				continue;
			}
			if (arr[i][j] == 'R')
			{
				RED.first = j; 
				RED.second = i; 
				arr[i][j] = '.';
				continue;
			}
		}
	}
}
int distanceCal(int x, int y, int nx, int ny) {
	int sum = abs(x - nx) + abs(y - ny);
	return sum;
}
int inverseDir(int dir) {
	if (dir == 0) return 1;
	if (dir == 1) return 0;
	if (dir == 2) return 3;
	if (dir == 3) return 2;

	return 0;
}
void go(int rx,int ry, int bx, int by, int cnt, int dir) {
	if (cnt > 10) return;
	if (cnt >= result) return;
	int nRx = rx;
	int nRy = ry;
	int nBx = bx;
	int nBy = by;
	//cout << "RedSt" << nRx << " " << nRy << endl;
	//cout << "BlueSt" << nBx << " " << nBy << endl;

	bool redFlag = 0;
	bool blueFlag = 0;
	while (true) {
		if (nRy + dy[dir] < 0 || nRx + dx[dir] < 0) break;
		nRx = nRx + dx[dir];
		nRy = nRy + dy[dir];
		//cout <<"Red"<< nRx << " " << nRy << endl;
		if (arr[nRy][nRx] == '#') break;
		if (arr[nRy][nRx] == 'O') {
			redFlag = 1;
			break;
		}
	}
	nRx = nRx - dx[dir];
	nRy = nRy - dy[dir];
	while (true) {
		if (nBy + dy[dir] < 0 || nBx + dx[dir] < 0) break;
		nBx = nBx + dx[dir];
		nBy = nBy + dy[dir];
		//cout << "Blue" << nBx<<" "<<nBy << endl;
		if (arr[nBy][nBx] == '#') break;
		if (arr[nBy][nBx] == 'O') {
			blueFlag = 1;
			return;
		}
	}
	nBx = nBx - dx[dir];
	nBy = nBy - dy[dir];
	if (blueFlag == 0 && redFlag == 1) result = min(result, cnt);
	if (nBy == nRy && nBx == nRx) { //겹친경우
		int redDistance = distanceCal(rx, ry, nRx, nRy);
		int blueDistance = distanceCal(bx, by, nBx, nBy);
		if (redDistance > blueDistance) { 
			nRx = nRx - dx[dir]; 
			nRy = nRy - dy[dir]; 
		} 
		else{
			nBx = nBx - dx[dir]; 
			nBy = nBy - dy[dir];
		}
	}
	for (int i = 0; i < 4; i++) {
		if (dir == i) continue;
		if (i == inverseDir(dir)) continue;

		go(nRx, nRy, nBx, nBy, cnt+1, i);
	}

}

void solve() {
	input();
	for (int i = 0; i < 4; i++) {
		go(RED.first, RED.second, BLUE.first, BLUE.second, 1,i);
	}
	if (result == 987654321) {
		cout << -1;
		return;
	}

	cout << result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}
