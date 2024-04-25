#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define FOR(i,N) for(int i =0;i<N;i++)
#define FOR1(i,N) for(int i =1;i<N;i++)
using namespace std;

vector<int> leaf;
vector<bool> visit;
vector<vector<pair<int, int>>> adj;
int ans = 0;
int maxNode = 0;
void go(int now, int length) {
	if (ans < length) {
		maxNode = now;
		ans = length;
	}
	visit[now] = 1;

	for (auto elem : adj[now]) {
		if (visit[elem.first] == 0) {
			go(elem.first,length+elem.second);
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;
	leaf.assign(N+1, 0);
	adj.assign(N+1,{});
	visit.assign(N + 1, 0);

	FOR(i, N) {
		int P,temp,L;
		cin>>P;
		while(true){
			cin>>temp;
			if(temp == -1) break;
			cin>>L;
			adj[P].push_back({temp,L});
			//adj[temp].push_back({ P,L });
			leaf[temp]++;

			maxNode = max(maxNode, P);
			maxNode = max(maxNode, temp);
		}
	}
	go(1,0);
	visit.assign(N + 1, 0);
	go(maxNode,0);
	cout<<ans<<endl;
}
