#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
struct computer {
	int from, to, cost;
	computer(int from, int to, int cost): from(from), to(to), cost(cost){}
};

struct graph {
	int V, E;
	vector<computer> edges;
	graph(int V, int E) {
		this->V = V;
		this->E = E;
	}
	void addEdge(int from, int to, int cost) {
		edges.push_back({from,to,cost});
	}
};
int find(vector<int>& parent, int i) {
	if(parent[i] == -1) return i;
	return find(parent, parent[i]);
}

void Union(vector<int>& parent, int x, int y) {
	int xset = find(parent, x);
	int yset = find(parent, y);
	if (xset != yset) {
		parent[xset] = yset;
	}
}

void KruskalMST(graph& graph) {
	vector<computer> result;
	sort(graph.edges.begin(), graph.edges.end(), [](computer a, computer b) {
		return a.cost<b.cost;
	});
	vector<int> parent(graph.V+1, -1);
	int ans = 0;
	for (auto e : graph.edges) {
		int x = find(parent, e.from);
		int y = find(parent, e.to);

		if (x != y) {
			ans += e.cost;
			Union(parent, x, y);
		}
	}

	cout<<ans;
}
int main() {
	int N, M;
	cin>>N>>M;
	graph G(N,M);
	FOR(i, M) {
		int from,to, cost;
		cin>>from>>to>>cost;
		G.addEdge(from,to,cost);
	}
	KruskalMST(G);
}
