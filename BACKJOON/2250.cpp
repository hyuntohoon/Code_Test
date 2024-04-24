#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,N) for(int i = 0;i<N;i++)
#define FOR1(i,N) for(int i = 1;i<N;i++)
using namespace std;

vector<pair<int, int>> graph;
vector<vector<int>> V;
vector<int> visit;
int rootNode, nowCol = 1;

void go(int now, int level) {
	if (now == -1) return;
	go(graph[now].first, level + 1);

	if (V.size() <= level) V.resize(level + 1);
	V[level].push_back(nowCol++);
	go(graph[now].second, level + 1);
}

int main() {
	int N;
	cin >> N;
	graph.assign(N + 1, {});
	visit.assign(N + 1, 0);
	FOR1(i, N + 1) {
		int P, L, R;
		cin >> P >> L >> R;
		graph[P] = { L, R };
		if (L != -1) visit[L]++;
		if (R != -1) visit[R]++;
	}

	FOR1(i, N + 1) {
		if (visit[i] == 0) {
			rootNode = i;
			break;
		}
	}
	go(rootNode, 1);

	int ansWidth = -1, ansLevel = 0;
	FOR1(i, V.size()) {
		if (!V[i].empty()) {
			sort(V[i].begin(), V[i].end());
			int nowWidth = V[i].back() - V[i].front() + 1;
			if (nowWidth > ansWidth) {
				ansWidth = nowWidth;
				ansLevel = i;
			}
		}
	}
	cout << ansLevel << " " << ansWidth << endl;
}
