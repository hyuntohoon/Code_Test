#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<n;i++)
using ll = long long;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1, 0, 0};
int main() {
	int R,C,T;
	vector<vector<int>> board(51,vector<int>(51,0));
	pair<int,int> topClean, downClean;
	bool flag = 0;
	cin>>R>>C>>T;
	FOR(i, R) {
		FOR(j, C) {
			cin>>board[i][j];
			if (flag == 0 && board[i][j] == -1) {
				topClean = {i,j};
				flag = 1;
			}
			else if(board[i][j] == -1 && flag == 1) {
				downClean = {i,j};
			}
		}
	}
	while (T--) {
		vector<vector<int>> tempBoard(51, vector<int>(51, 0));
		FOR(i, R) {
			FOR(j, C) {
				if (board[i][j] > 0) {
					int nowSum = board[i][j];
					int dustCnt = 0;
					FOR(k, 4) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if ((ny == 0 && nx == topClean.first) || (ny == 0 && nx == downClean.first)) continue;
						if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
							tempBoard[nx][ny] += board[i][j] / 5;
							dustCnt++;						
						}
					}
					nowSum -= board[i][j]/5 * dustCnt;
					tempBoard[i][j] += nowSum;
				}
			}
		}
		board = tempBoard;
		int x = topClean.first-1;
		int y = topClean.second;
		for (int i = x; i > 0; i--) {
			board[i][y] = board[i-1][y];
		}
		x = 0;
		for (int i = 0; i < C-1; i++) {
			board[x][i] = board[x][i+1];
		}
		y = C-1;
		for (int i = 0; i < topClean.first; i++) {
				board[i][y] = board[i+1][y];
		}
		x = topClean.first;
		for (int i = y; i > 0; i--) {
			board[x][i] = board[x][i-1];
		}
		board[x][topClean.second+1] = 0;
		// top
		x = downClean.first+1;
		y = downClean.second;
		for (int i = x; i < R-1; i++) {
			board[i][y] = board[i+1][y];
		}
		x = R-1;
		for (int i = 0; i < C - 1; i++) {
			board[x][i] = board[x][i+1];
		}
		y = C-1;
		for (int i = x; i > downClean.first; i--) {
			board[i][y] = board[i-1][y];
		}
		x = downClean.first;
		for (int i = y; i > 0; i--) {
			board[x][i] = board[x][i-1];
		}
		board[x][downClean.second+1] = 0;
	}
	int ans = 0;
	FOR(i, R) {
		FOR(j, C) {
			ans += board[i][j];
		}
	}
	cout<<ans;
}
