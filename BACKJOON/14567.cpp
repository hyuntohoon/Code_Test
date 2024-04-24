#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define FOR(i,N) for(int i = 0;i<N;i++)
#define FOR1(i,N) for(int i = 1;i<N;i++)
using namespace std;

int main() {
	// A는 B를 이수해야 들을 수 있다.
	int N, M;
	cin >> N >> M;
	vector<vector<int>> adj(N + 1);
	vector<int> indegree(N+1,0);
	FOR(i, M) {
		int A, B;
		cin >> A >> B;
		adj[A].push_back(B);
		indegree[B]++;
	}
	queue<int> Q;
	vector<int> result(N+1,1);
	FOR1(i, N + 1) {
		if (indegree[i] == 0) {
			Q.push(i);
		}
	}

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (auto elem : adj[now]) {
			indegree[elem]--;
			result[elem] = max(result[elem], result[now] + 1);
			// 현재 노드까지 도달 하는 최대 시간 => result[elem]
			// now노드를 거쳐 elem 노드로 한 단계 더 가는 것 => result[now] + 1
			if (indegree[elem] == 0) Q.push(elem);
		}
	}
	FOR1(i, N + 1) {
		cout << result[i] << " ";
	}
}
