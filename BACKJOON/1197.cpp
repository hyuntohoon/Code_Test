#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
using ll = long long;
struct edge {
	int from,to, cost;
};

struct Graph {
	int V, E;
	vector<edge> edges;
	Graph(int V, int E) {
		this ->V = V;
		this ->E = E;
	}
	void addEdge(int from, int to, int cost) {
		edges.push_back({ from, to, cost });
	}
};
int find(vector<int> &parent, int i) {
	if (parent[i] != i)
		parent[i] = find(parent, parent[i]); // 경로 압축
	return parent[i];
}

void Union(vector<int> &parent, int x, int y) {
	int xset = find(parent, x);
	int yset = find(parent, y);
	if (xset != yset) {
		parent[xset] = yset;
	}
}

void kruskalMST(Graph &graph) {
	vector<edge> result;
	sort(graph.edges.begin(), graph.edges.end(), [](edge a, edge b) {
		return a.cost<b.cost;
	});
	vector<int> parent(graph.V+1);
	for (int i = 0; i < graph.V; i++) {
		parent[i] = i;
	}

	ll ans = 0;
	for (auto e : graph.edges) {
		int x = find(parent, e.from);
		int y = find(parent, e.to);
		if (x != y) {
			result.push_back(e);
			ans += e.cost;
			Union(parent, x,y);
		}
	}
	
	cout<<ans<<endl;
}

int main() {
	int V,E;
	cin>>V>>E;
	Graph G(V,E);
	FOR(i, E) {
		int from, to, cost;
		cin>>from>>to>>cost;
		G.addEdge(from,to,cost);
	}
	kruskalMST(G);
}
