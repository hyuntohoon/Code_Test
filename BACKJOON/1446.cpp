#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define FOR(i,N) for(int i = 0;i<N;i++)
#define FOR1(i,N) for(int i = 1;i<N;i++)
using ll = long long;
using namespace std;


int main() {
	int N,D;
	cin>>N>>D;
	vector<pair<int,int>> V[10001];
	vector<int> dij(10001,987654321);
	FOR(i, D) {
		V[i].push_back({i+1,1});
	}
	FOR(i, N) {
		int from, to, dist;
		cin>>from>>to>>dist;
		V[from].push_back({to,dist});
	}
	dij[0] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,0});
	while (!pq.empty()) {
		int from = pq.top().first;
		int dist = pq.top().second;
		pq.pop();
		for (auto elem : V[from]) {
			int to = elem.first;
			int dist = elem.second;
			if (dij[to] > dij[from] + dist) {
				dij[to] =dij[from] + dist;
				pq.push({to,dist});
			}
		}
	}
	cout<<dij[D]<<endl;
}
