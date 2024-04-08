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

struct microbe {
	int x,y,cnt,dir;
};
int N, M, K;
int dx[5] = {0,-1,1,0,0};
int dy[5] ={0,0,0,-1,1};
void move(vector<microbe> &microV) {
	FOR(i, microV.size()) {
		int x = microV[i].x;
		int y = microV[i].y;
		int cnt = microV[i].cnt;
		int dir = microV[i].dir;

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		
		microV[i].x = nx;
		microV[i].y = ny;
	}
}

void contact(vector<microbe> &microV) {
	FOR(i, microV.size()) {
		int x = microV[i].x;
		int y = microV[i].y;
		int cnt = microV[i].cnt;
		int dir = microV[i].dir;

		if (x == 0 || y == 0 || x == N-1 || y == N-1) {
			microV[i].cnt /=2;
			if(dir == 1) microV[i].dir = 2;
			else if (dir == 2) microV[i].dir = 1;
			else if (dir == 3) microV[i].dir = 4;
			else if (dir == 4) microV[i].dir = 3;
		}
	}
}

vector<microbe> sum(vector<microbe> &microV) {
	vector<microbe> newMicroV;
	vector<pair<int,int>> order;
	vector<vector<int>> maxVal(N,vector<int>(N,0));
	vector<vector<int>> maxDir(N, vector<int>(N, 0));
	vector<vector<int>> sumBoard(N, vector<int>(N, 0));
	FOR(i, microV.size()) {
		int x = microV[i].x;
		int y = microV[i].y;
		int cnt = microV[i].cnt;
		int dir = microV[i].dir;
		if (maxVal[x][y] < cnt) { // 크면 맥스 크기, 맥스 방향 따라가기
			maxVal[x][y] = cnt;
			maxDir[x][y] = dir;
		}
		sumBoard[x][y] += cnt;
	}
	FOR(i, N) {
		FOR(j,N){
			if (sumBoard[i][j] != 0) {
				newMicroV.push_back({i,j,sumBoard[i][j],maxDir[i][j]});
			}
		}
	}
	return newMicroV;
}
vector<microbe> checkGio(vector<microbe> &microV) {
	contact(microV);
	return sum(microV);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;

	for (int t = 1; t <= T; t++) {
		vector<microbe> microV;
		cin>>N>>M>>K;
		FOR(i, K) {
			int x,y,cnt,dir;
			cin>>x>>y>>cnt>>dir;
			microV.push_back({x,y,cnt,dir});
		}
		while (M--) {
			move(microV);
			microV = checkGio(microV);
		}
		int ans=0;
		for (auto elem : microV) {
			ans += elem.cnt;
		}
		cout<<"#"<<t<<" "<<ans<<endl;
	}
}
