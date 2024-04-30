#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define FOR(i,N) for(int i =0;i<N;i++)
#define FOR1(i,N) for(int i =1;i<N;i++)
using namespace std;
vector<int> root;
vector<int> rootSize;
bool visit[100001];
int find(int x) {
	if (x == root[x]) {
		return x;
	}
	else {
		return root[x] = find(root[x]);
	}
}
void merge(int x, int y) {
	int rootX = find(x);
	int rootY = find(y);
	if (rootX != rootY) {
		if (rootSize[rootX] < rootSize[rootY]) {
			swap(rootX, rootY);
		}
		root[rootY] = rootX;
		rootSize[rootX] += rootSize[rootY];
	}
}
int main() {
	int N,M,Q;
	cin>>N>>M>>Q;

	root.assign(N+1,0);
	rootSize.assign(N+1,1);
	vector<int> order(Q);
	vector<pair<int,int>> connect(M+1);
	FOR1(i, N + 1) {
		root[i] = i;
	}
	FOR1(i, M+1) {
		int a,b;
		cin>>a>>b;
		connect[i] = {a,b};
	}
	FOR(i, Q) {
		cin>>order[i];
		visit[order[i]] = 1;
	}
	FOR1(i, M+1) {
		if (visit[i] == 0) {
			merge(connect[i].first,connect[i].second);
		}
	}
	reverse(order.begin(),order.end());
	long long result =0;
	for (auto elem : order) {
		int a = find(connect[elem].first);
		int b = find(connect[elem].second);
		if(a !=b){
			result += rootSize[a] * rootSize[b];
			merge(a,b);
		}
	}
	cout<<result<<endl;
}
