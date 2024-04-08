#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<n;i++)
using ll = long long;
int ans=-1;
int dx[4] = {1, 1, -1 ,-1};
int dy[4] = {1, -1, -1, 1};
int N;
vector<vector<int>> board(21, vector<int>(21, 0));
vector<int> dist;
int startX,startY;
void go(int x, int y, int d) {
	int nx = x + dx[d];
	int ny = y + dy[d];
	if (d == 3 && nx == startX && ny == startY) {
		ans = max(ans,(int)dist.size());
		return;
	}
	if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
		if(find(dist.begin(), dist.end(), board[nx][ny]) != dist.end()) return;
		dist.push_back(board[nx][ny]);
		if(d == 3) go(nx,ny,3);
		else {
			go(nx,ny,d);
			go(nx,ny,d+1);
		}
	}
	else return;
	dist.pop_back();
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;

	for (int t = 1; t <= T; t++) {

		cin>>N;
		ans = -1;
		FOR(i, N) {
			FOR(j, N) {
				cin>>board[i][j];
			}
		}
		FOR(i, N-2) {
			FOR1(j, N-1) {
				dist.clear();
				dist.push_back(board[i][j]);
				startX = i;
				startY = j;
				go(i,j,0);
			}
		}
		cout<<"#"<<t<<" "<<ans<<endl;
	}
}
