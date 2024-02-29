// ConsoleApplication11.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

struct wormhole {
	int x, y, num;
	bool f;
	wormhole(int x, int y, int num, bool f) : x(x), y(y), num(num), f(f) {}
};

struct pinball {
	int x, y, d;
	pinball(int x, int y, int d) : x(x), y(y), d(d) {}
};
int T;
int N;
int board[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = {0,1,0,-1};
vector <wormhole> W;

pair<int, int> findOutWorm(int num, bool f) {
	for (int i = 0; i < W.size(); i++) { // W사이즈만큼 탐색
		auto w = W[i];
		if (w.num == num && w.f != f) return { w.x, w.y }; // 번호는 같고 다른 통로 찾아서 리턴
	}
	return { -1,-1 };
}
int result = 0;
void BFS(int startX, int startY, int startD) {
	int cnt = 0;
	int x = startX;
	int y = startY;
	int d = startD;
	bool f = false;
	while (true) {
		int nowNum = board[x][y]; // 지금 번호
			if (nowNum == -1 || (x == startX && y == startY && f == true)) {
				result = max(result, cnt);
				return;
			}
			else if (x < 0 || y < 0 || x >= N || y >= N) {
				x = x - dx[d];
				y = y - dy[d];
				d = (d + 2) % 4;
				cnt++;
			}
			else if (nowNum == 0) { // 지금 번호가 0이라면 방문하지 않았어야 함
				x = x + dx[d];
				y = y + dy[d];
			}
			else if (0 < nowNum && nowNum < 6) { // 블록인 경우
				cnt++;
				if (nowNum == 1) {
					if (d == 2) {
						y++;
						d = 1;
					}
					else if (d == 3) {
						x--;
						d = 0;
					}
					else {
						x = x - dx[d];
						y = y - dy[d];
						d = (d + 2) % 4;
					}
				}
				if (nowNum == 2) {
					if (d == 3) {
						x++;
						d = 2;
					}
					else if (d == 0) {
						y++;
						d = 1;
					}
					else {
						x = x - dx[d];
						y = y - dy[d];
						d = (d + 2) % 4;
					}
				}
				if (nowNum == 3) {
					if (d == 1) {
						x++;
						d = 2;
					}
					else if (d == 0) {
						y--;
						d = 3;
					}
					else {
						x = x - dx[d];
						y = y - dy[d];
						d = (d + 2) % 4;
					}
				}
				if (nowNum == 4) {
					if (d == 1) {
						x--;
						d = 0;
					}
					else if (d == 2) {
						y--;
						d = 3;
					}
					else {
						x = x - dx[d];
						y = y - dy[d];
						d = (d + 2) % 4;
					}
				}
				if (nowNum == 5) {
					x = x - dx[d];
					y = y - dy[d];
					d = (d + 2) % 4;
				}
			}
			else if (5 < nowNum && nowNum < 11) { // 웜홀인 경우
				for (int i = 0; i < W.size(); i++) { // W의 사이즈 만큼 탐색
					auto w = W[i];
					if (w.num == nowNum && w.x == x && w.y == y) { // 만약 같은 번호, 현재의 x,y값과 같다면 실행
						pair<int, int> temp = findOutWorm(nowNum, w.f); // findOutWorm 함수를 통해서 다른 통로 찾기
						x = temp.first + dx[d];
						y = temp.second + dy[d];
						break;
					}
				}
			}
			f = true;
	}
}

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++) {
		result = 0;
		cin >> N;
		bool visit[11];
		memset(board, 0, sizeof(board));
		W.clear();
		FOR(i, 11) visit[i] = 0;
		FOR(i, N) {
			FOR(j, N) {
				cin >> board[i][j];
				int nowNum = board[i][j];
				if (nowNum >= 6) {
					W.push_back({ i,j,nowNum,visit[nowNum] });
					if (!visit[nowNum]) visit[nowNum]++;
				}
			}
		}
		FOR(i, N) {
			FOR(j, N) {
				int nowNum = board[i][j];
				if (nowNum == 0) {
					FOR(d, 4) {
						BFS(i, j, d);
					}
				}
			}
		}
		cout << "#" << t << " " << result << endl;
	}
}
