#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
struct swim {
	int x,y,time;
	swim(int x, int y, int time): x(x),y(y),time(time){}
};
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int main() {
	int T;
	cin>>T;
	for(int t = 1;t<=T;t++){
		int N;
		cin>>N;
		int board[16][16];
		bool visit[16][16];
		int tempBoard[16][16];
		FOR(i, N) {
			FOR(j, N) {
				cin>>board[i][j];
				visit[i][j] = 0;
				tempBoard[i][j] = 0;
			}
		}
		pair <int,int> startPoint;
		pair <int, int> endPoint;
		int tempX, tempY;
		cin>>tempX>>tempY;
		startPoint = {tempX,tempY};
		cin >> tempX >> tempY;
		endPoint = { tempX,tempY };
		queue<swim> Q;
		Q.push(swim(startPoint.first,startPoint.second,0));

		int minTime = 987654321;
		while (!Q.empty()) {
			int x = Q.front().x;
			int y = Q.front().y;
			int nowTime = Q.front().time;
			tempBoard[x][y] = nowTime;
			visit[x][y] = 1;
			Q.pop();
			if (x == endPoint.first && y == endPoint.second) {
				minTime = min(minTime, nowTime);
			}
			FOR(k, 4) {
				int nx = x +dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && ny >= 0 && nx < N && ny < N && visit[nx][ny] == 0) {
					if (board[nx][ny] == 0) {
						Q.push(swim(nx, ny, nowTime + 1));
					}
					else if (board[nx][ny] == 2) {
						if(nowTime%3 == 0) Q.push(swim(nx,ny,nowTime+3));
						if (nowTime % 3 == 1) Q.push(swim(nx, ny, nowTime + 2));
						if (nowTime % 3 == 2) Q.push(swim(nx, ny, nowTime +1));
					}
				}
			}
		}
		if (minTime == 987654321) {
			cout << "#" << t << " " << -1 << endl;
		}
		else{
			cout<<"#"<<t<<" "<<minTime<<endl;
		}
	}
}
