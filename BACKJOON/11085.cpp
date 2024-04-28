#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,N) for(int i = 0;i<N;i++)
#define FOR1(i,N) for(int i = 1;i<N;i++)
using namespace std;
struct edge {
	int start, end, cost;
};

vector<int> root;
vector<int> R;
vector<edge> edges;

//찾기 함수
int find(int x) {
	if (root[x] == x) { //부모인 경우
		return x;
	}
	else {
		return find(root[x]);
	}

}
//merge 함수
bool merge(int x, int y) {
	int rootX = find(x);
	int rootY = find(y);
	if (rootX == rootY) return false;
	root[rootY] = rootX;
	return true;
}

int main() {
	int p, w;
	int c, v;
	cin >> p >> w >> c >> v;
	root.assign(p + 1, 0);
	R.assign(p + 1, 0);
	FOR(i, p + 1) {
		root[i] = i;
	}
	FOR(i, w) {
		int s, e, cost;
		cin >> s >> e >> cost;
		edges.push_back({ s,e,cost });
	}
	sort(edges.begin(), edges.end(), [](const edge& a, const edge& b) {
		return a.cost > b.cost; });
	for (auto elem : edges) {
		int a = elem.start;
		int b = elem.end;
		int cost = elem.cost;
		if (find(a) != find(b)) merge(a, b);
		if (find(c) == find(v)) {
			cout << cost;
			return 0;
		}
	}
}
