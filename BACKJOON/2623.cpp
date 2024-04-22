#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> adjacencyList(N + 1);
	vector<int> indegree(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int numRules;
		cin >> numRules;
		int start;
		cin >> start;
		for (int j = 1; j < numRules; j++) {
			int next;
			cin >> next;
			adjacencyList[start].push_back(next);
			indegree[next]++;
			start = next;
		}
	}

	queue<int> Q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			Q.push(i);
		}
	}

	vector<int> result;
	while (!Q.empty()) {
		int node = Q.front(); Q.pop();
		result.push_back(node);
		for (int neighbor : adjacencyList[node]) {
			indegree[neighbor]--;
			if (indegree[neighbor] == 0) {
				Q.push(neighbor);
			}
		}
	}



	if (result.size() != N) {
		cout << "0" << endl;
	}
	else {
		for (int elem : result) {
			cout << elem << " ";
		}
		cout << endl;
	}
}
