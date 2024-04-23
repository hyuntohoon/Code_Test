#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define FOR(i,N) for(int i = 1;i<=N;i++)
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> bulidingTime(N+1);
	vector<int> result(N + 1);
	vector<int> indegree(N+1);
	vector<vector<int>> adj(N+1);

	queue<int>Q;
	FOR(i, N) {
		cin >> bulidingTime[i];
		int temp;
		while (true) {
			cin >> temp;
			if (temp == -1) break;
			adj[temp].push_back(i);
			indegree[i]++;
		}
		if (indegree[i] == 0) {
			result[i] = bulidingTime[i];
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int now = Q.front();
		
		Q.pop();
		for(auto elem : adj[now]) {
			indegree[elem]--;
			result[elem] = max(result[elem], result[now] + bulidingTime[elem]);
			if (indegree[elem] == 0) {
				Q.push(elem);
			}
		}
	}
	FOR(i, N) {
		cout << result[i]<< endl;
	}
}
