#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define FOR(i,n) for(int i = 0;i<n;i++)
#define FOR1(i,n) for(int i = 1;i<n;i++)
using namespace std;


int board[11][11];
int pBoard[11][11];
int N, M, C;
bool flag;
int ans = -1;

void DFS(int x, int y, int depth, int sum, int profit, vector<vector<bool>> &visit) {
	if (sum == 5 && depth == 2 && flag == 0) {
		//cout<<"dsdsds"<<endl;
	}
	if(sum>C) return;

	if(flag == 0) visit[x][y] = 1;
	if (depth == M) {
		if (profit == 74) {
			//cout<<"sads"<<endl;
		}
		ans = max(profit, ans);
		if (ans == 178) {
			//cout<<"ppiooi"<<endl;
		}
		if(flag == 0){
			flag = 1;
			FOR(i, N) {
				FOR(j, N) {
					if (i == 3 && j == 1) {
						//cout<<"dsds"<<endl;
					}
					if (visit[i][j] == 0) {
						DFS(i, j, 1, board[i][j], profit + pBoard[i][j], visit);
						DFS(i, j, 1, 0, profit, visit);
					}
				}
			}
			flag = 0;
		}
		
		return;
	}
	if(y+1<N){
		if (flag == 1) {
			if (visit[x][y + 1] == 0) {
				DFS(x, y + 1, depth + 1, sum + board[x][y + 1], profit + pBoard[x][y + 1], visit);
				DFS(x, y + 1, depth + 1, sum, profit, visit);
			}
		}
		else{
			DFS(x, y + 1, depth+1, sum + board[x][y+1], profit + pBoard[x][y+1], visit);
			DFS(x, y + 1, depth+1, sum, profit, visit);
		}
	}
}
int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {	
		ans = -1;	
		cin>>N>>M>>C;
		FOR(i, N) {
			FOR(j, N) {
				cin>>board[i][j];
				pBoard[i][j] = board[i][j]* board[i][j];
			}
		}
		FOR(i, N) {
			FOR(j, N) {
				flag = 0;
				vector<vector<bool>> visit(N,vector<bool>(N,0));
				if (i == 1 && j == 0) {
					//cout<<"sasa"<<endl;
				}
				DFS(i, j, 1, board[i][j], pBoard[i][j], visit);
				DFS(i,j,1,0,0, visit);	
			}
		}
		cout<<"#"<<t<<" "<<ans<<endl;
	}
}
