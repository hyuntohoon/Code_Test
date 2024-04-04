#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<n;i++)
using ll = long long;
int startX, startY;
int goalX, goalY;

struct swim {
	int x,y,time;
};
int dx[4] = {0,0,1,-1};
int dy[4] = { 1,-1,0,0};
int N;
int BFS(vector<vector<int>> &V) {
	queue<swim> Q;
	Q.push({startX,startY,0});
	bool visit[16][16];
	FOR(i, N) {
		FOR(j, N)visit[i][j] = 0;
	}

	while (!Q.empty()) {
		int x = Q.front().x;
		int y = Q.front().y;
		visit[x][y] = 1;
		int time = Q.front().time;
		if (x == goalX && y == goalY) return time;
		Q.pop();
		FOR(k,4) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && ny >= 0&& nx < N && ny < N) {
				if (V[nx][ny] == 0 && visit[nx][ny] ==0) {
					visit[nx][ny] = 1;
					Q.push({nx,ny,time+1});
				}
			}
		}
	}
	return -1;
}

int main() {
	int T;
	cin>>T;
	FOR1(t, T+1) {
		cin>>N;
		vector<vector<int>> V(16,vector<int>(16,0));
		FOR(i, N) {
			FOR(j, N) {
				cin>>V[i][j];
			}
		}
		cin>>startX>>startY;
		cin>>goalX>>goalY;
		int ans = -1;
		cout<<"#"<<t<<" "<<BFS(V)<<endl;
	}
}
