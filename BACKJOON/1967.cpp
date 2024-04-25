#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define FOR(i,N) for(int i =0;i<N;i++)
#define FOR1(i,N) for(int i =1;i<N;i++)
using namespace std;

vector<bool> leaf;
vector<bool> visit;
vector<vector<pair<int, int>>> adj;
int ans = 0;
int root;
void go(int now, int length) {
	if (leaf[now] == 1  || now == root) {
		ans = max(ans, length);
	}

	for (auto elem : adj[now]) {
		if (visit[elem.first] == 0) {
			visit[elem.first] = 1;
			go(elem.first,length+elem.second);
			visit[elem.first] = 0;
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;
	leaf.assign(N+1, 1);
	adj.assign(N+1,{});
	visit.assign(N + 1, 0);
	int maxNode = -1;
	bool rootNode[10001] = {0,};
	FOR(i, N -1) {
		int P,temp,L;
		cin>>P>>temp>>L;
		adj[P].push_back({temp,L});
		adj[temp].push_back({ P,L });
		leaf[P] = 0;
		rootNode[temp] = 1;
		maxNode = max(maxNode, P);
		maxNode = max(maxNode, temp);
	}
	FOR1(i, maxNode + 1) {
		if (rootNode[i] == 0) {
			root =i;
		}
	}
	FOR1(i, maxNode+1) {
		if (leaf[i] == 1) {
			visit[i] = 1;
			go(i,0);
			visit[i] = 0;
		}
	}
	cout<<ans<<endl;
}
