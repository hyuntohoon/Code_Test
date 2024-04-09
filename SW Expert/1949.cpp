#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define FOR(i,n) for(int i = 0;i<n;i++)
#define FOR1(i,n) for(int i = 1;i<n;i++)
using namespace std;

struct course {
	int x, y, num;
	bool F;
	int preVal;
};
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1, 0,0};
int N, K;
int board[10][10];
int ans;
void BFS(pair <int,int> P) {
	queue<course> Q;
	Q.push({P.first, P.second,1,0,-1});
	bool visit[10][10] = {0,};
	while (!Q.empty()) {
		int x = Q.front().x;
		int y = Q.front().y;
		visit[x][y] = 1;
		int num = Q.front().num;
		bool F = Q.front().F;
		int preVal = Q.front().preVal;
		//cout<<x<<" "<<y<<" "<<num<<" "<<F<<endl;
		ans = max(ans, num);
		Q.pop();
		FOR(k,4) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				//cout<<board[x][y]<<" "<<board[nx][ny]<<endl;
				if (board[nx][ny] < board[x][y]) {
					visit[nx][ny] = 1;
					Q.push({nx,ny,num+1,F,preVal});
				}
				//else {
				//	if (F == 0 && board[nx][ny] - K < preVal) {
					//	visit[nx][ny] = 1;
					//	Q.push({nx,ny,num+1,1,board[x][y]});
				//	}
				//}
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {

		cin>>N>>K;
		int top =0;
		FOR(i, N) {
			FOR(j, N) {
				cin>>board[i][j];
				top = max(board[i][j],top);
			}
		}
		ans = -1;
		vector<pair<int,int>> tops;
		FOR(i, N) {
			FOR(j, N) {
				if(board[i][j] == top) tops.push_back({i,j});
			}
		}
		FOR(i, N) {
			FOR(j, N) {
				FOR1(a, K+1) {
					board[i][j]-=a;
					for (auto elem : tops) {
						BFS(elem);
					}
					board[i][j]+=a;
				}
			}
		}
		for (auto elem : tops) {
			BFS(elem);
		}
		cout<<"#"<<t<<" "<<ans<<endl;
	}
}
