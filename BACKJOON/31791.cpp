#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define FOR(i,N) for(int i = 0;i<N;i++)
#define FOR1(i,N) for(int i = 1;i<N;i++)
using ll = long long;
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int N, M;
bool place[1001][1001];
bool visit[1001][1001];
bool checkRange(int x, int y) {
	if (x >= 0 && y >= 0 && x < N && y < M) {
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	//pq에 들어갈 곳 시작점, 현재 dist
	int T, BT, X, B;
	cin >> T >> BT >> X >> B;
	vector<pair<int,int>> virus;

	vector<vector<int>> cost(1001,vector<int> (1001,987654321));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	FOR(i, N) {
		string temp;
		cin >> temp;
		FOR(j, M) {
			if (temp[j] == '*') {
				virus.push_back({i,j});
				cost[i][j] = 0;
				pq.push({0,{i,j}});
			}
			else if (temp[j] == '#') {
				place[i][j] = 1;
			}
		}
	}
	while (!pq.empty()) {
		int nowCost = pq.top().first;
		pair<int,int> nowPoint = pq.top().second;
		int x = nowPoint.first;
		int y = nowPoint.second;
		pq.pop();
		if(visit[x][y] == 1) continue;
		visit[x][y] = 1;
		FOR(i, 4) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (checkRange(nx, ny) && visit[nx][ny] == 0) {
				int tempCost = nowCost+1;
				if (place[nx][ny] == 1) tempCost+=BT;
				if(tempCost>T) continue;
				if (cost[nx][ny] > tempCost) {
					cost[nx][ny] = tempCost;
					pq.push({tempCost,{nx,ny}});
				}
			}
		}
	}
	bool flag = 0;
	FOR(i, N) {
		FOR(j, M) {
			if (cost[i][j] == 987654321) {
				flag = 1;
				cout<<i+1<<" "<<j+1<<"\n";
			}
		}
	}
	if(flag ==0) cout<<-1;
	// 건물의 경우 지연 시간을 dij로 계산하기
	// 예를 들어 x,y 좌표를 기준으로 pq에 들어갔다면
	// top은 시작점, 그리고 dist값 4방을 기준으로
	// 다음 위치 + 1 + dist값과 dij 값 비교 후 작다면 pq에 push
}

