#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define FOR(i,n) for(int i = 0;i<n;i++)
#define FOR1(i,n) for(int i = 1;i<n;i++)
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int N, M, R, C, L; // 세로, 가로, 세로, 가로 시작, 시간
int board[51][51];
vector<vector<int>> pipe(8);
struct runner {
	int x,y,depth;
};
int BFS(int startX, int startY) {
	queue<runner> Q;
	Q.push({startX,startY,1});
	bool visit[51][51] = {0,};
	while (!Q.empty()) {
		int x = Q.front().x;
		int y = Q.front().y;
		int depth = Q.front().depth;
		int nowPipe = board[x][y];
		Q.pop();
		if (depth > L) continue;
		visit[x][y] = 1;


		for (auto elem : pipe[nowPipe]) {
			int nx = x + dx[elem];
			int ny = y + dy[elem];
			int nextPipe = board[nx][ny];
			if(nextPipe == 0) continue;
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if(visit[nx][ny] != 0) continue;
				if (elem == 0) {
					if (nextPipe == 1 || nextPipe == 2 || nextPipe == 5 || nextPipe == 6) {
						//visit[nx][ny] = 1;
						Q.push({nx,ny,depth+1});
					}
				}
				else if (elem == 1) {
					if (nextPipe == 1 || nextPipe == 3 || nextPipe == 6 || nextPipe == 7) {
						//visit[nx][ny] = 1;
						Q.push({ nx,ny,depth + 1 });
					}
				}
				else if (elem == 2) {
					if (nextPipe == 1 || nextPipe == 2 || nextPipe == 4 || nextPipe == 7) {
						//visit[nx][ny] = 1;
						Q.push({ nx,ny,depth + 1 });
					}
				}
				else if (elem == 3) {
					if (nextPipe == 1 || nextPipe == 3 || nextPipe == 4 || nextPipe == 5) {
						//visit[nx][ny] = 1;
						Q.push({ nx,ny,depth + 1 });
					}
				}
			}
		}
	}
	int count = 0;
	FOR(i, N) {
		FOR(j, M) {
			if(visit[i][j] == 1) count++;
		}
	}
	return count;
}

int main()
{
	pipe[1] = {0,1,2,3};
	pipe[2] = { 0,2};
	pipe[3] = { 1,3 };
	pipe[4] = { 0,1 };
	pipe[5] = { 1,2 };
	pipe[6] = { 3,2 };
	pipe[7] = { 0,3 };
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {	
		cin>>N>>M>>R>>C>>L;
		FOR(i, N) {
			FOR(j, M) {
				cin>>board[i][j];
			}
		}
		int ans = BFS(R,C);
		cout<<"#"<<t<<" "<<ans<<endl;
	}
}
