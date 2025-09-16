#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define FOR(i,N) for(int i =0;i<N;i++)
using ll = long long;
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int DP[501][501];
bool visit[501][501];
int N;
int go(int x, int y, vector<vector<int>> &board) {
	if(DP[x][y] != 0 ) return DP[x][y];
	DP[x][y] = 1;
	FOR(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx>=0 && ny >=0 && nx<N && ny < N) {
			if (board[nx][ny] > board[x][y]) {
				DP[x][y] = max(DP[x][y], go(nx,ny, board)+1);
			}
		}
	}
	return DP[x][y];
}

int main(){

	cin>>N;
	vector<vector<int>> board(N, vector<int>(N));
	FOR(i, N) {
		FOR(j, N) {
			cin>>board[i][j];
		}
	}
	int ans = -1;
	FOR(i, N) {
		FOR(j, N) {
			ans = max(ans,go(i,j,board));
		}
	}
	cout<<ans<<endl;
}