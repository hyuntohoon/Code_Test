#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<n;i++)
using ll = long long;

/*
1. 떨어뜨리는 위치 조정 => DFS 중복
2. 공 떨어뜨리는 로직 => 떨어지는 공이 벽을 만나는 로직
3. 벽이 터지는 로직 => 바로 터지는 것이 아닌 만나는 벽을 체크하고 나중에 다 삭제

4. 중력에 의해서 다 떨어지는 로직

1. DFS 중복으로 처리 => 매회 copy된 board를 사용
2. 위에서부터 체크, 0이 아닌 벽을 만나는 경우 확인 for문
3. 벽이 터지는 로직 => dx, dy를 통해서 bfs처럼 모두 체크
4. 이후 중력에 의해 떨어지는 로직
*/
int N, W, H;

vector<vector<int>> board(16, vector<int>(13, 0));
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void dropBirck(vector <vector<int>> &tempBoard) {
	FOR(i, W) {
		for (int j = H - 1; j >= 0; j--) {
			if (tempBoard[j][i] == 0) {
				for (int k = j - 1; k >= 0; k--) {
					if (tempBoard[k][i] != 0) {
						tempBoard[j][i] = tempBoard[k][i];
						tempBoard[k][i] = 0;
						break;
					}
				}
			}
		}
	}

}
void boomBrick(vector <vector<int>> &tempBoard, int startX, int startY) {
	queue<pair<int, int>> boom;
	boom.push({ startX,startY });
	bool willBoom[16][13] = { 0 };
	while (!boom.empty()) {
		int x = boom.front().first;
		int y = boom.front().second;
		int boomRange = tempBoard[x][y] - 1;
		willBoom[x][y] = true;
		boom.pop();
		FOR(k, 4) {
			FOR1(j, boomRange + 1) {
				int nx = x + dx[k] * j;
				int ny = y + dy[k] * j;
				if (nx >= 0 && ny >= 0 && nx < H && ny < W && willBoom[nx][ny] == 0) {
					willBoom[nx][ny] = true;
					boom.push({ nx,ny });
				}
			}
		}
	}
	FOR(i, H) {
		FOR(j, W) {
			if (willBoom[i][j] == 1) {
				tempBoard[i][j] = 0;
			}
		}
	}
}
int result = 987654321;
int remainCnt(vector <vector<int>> &tempBoard) {
	int cnt = 0;
	FOR(i, H) {
		FOR(j, W) {
			if (tempBoard[i][j] != 0) {
				cnt++;
				if (cnt >= result) return cnt;
			}
		}
	}
	return cnt;
}

void dropBall(vector<int> &order) {
	vector<vector<int>> tempBoard = board;
	for (int k = 0;k<N;k++) {
		FOR(i, H) {
			if (tempBoard[i][order[k]] != 0) { // 해당 숫자가 0이 아니면
				boomBrick(tempBoard, i, order[k]);
				dropBirck(tempBoard);
				break;
			}
		}
	}
	int nowCnt = 0;
	FOR(i, H) {
		FOR(j, W) {
			if (tempBoard[i][j] != 0) {
				nowCnt++;
				if (nowCnt >= result) return; // 가지치기를 통한 조기 종료
			}
		}
	}
	result = min(nowCnt, result);
}
void go(vector<int> &order, int cnt) {
	if (cnt == N) {
		dropBall(order);
		return;
	}
	FOR(i, W) {
		order[cnt] = i; 
		go(order,cnt+1);
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> W >> H;
		result = 987654321;
		FOR(i, H) {
			FOR(j, W) {
				cin >> board[i][j];
			}
		}
		vector<int> order(4,-1);
		go(order,0);
		cout << "#" << t << " " << result << endl;
	}
}
