#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define FOR(i,N) for(int i =0;i<N;i++)
#define FOR1(i,N) for(int i =1;i<N;i++)
using namespace std;
vector<int> root;
vector<int> visit;

int find(int x) {
	if (root[x] == x) {
		return x;
	}
	else {
		return root[x] = find(root[x]);
	}
}

void merge(int x, int y) {
	int rootX = root[x];
	int rootY = root[y];
	if (!visit[x]) {
		rootY = rootX;
	}
	else {
		root[x] = y;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, L;
	cin>>N>>L;
	root.assign(L+1,0);
	visit.assign(L+1,0);
	FOR1(i, L+1) {
		root[i] = i;
	}
	FOR(i, N) {
		int a, b;
		cin>>a>>b;
		a = find(a);
		b = find(b);
		if (visit[a] == 0) {
			visit[a] = 1;
			merge(a,b);
			cout << "LADICA\n";
		}
		else if (visit[b] == 0) {
			visit[b] = 1;
			merge(a, b);
			cout << "LADICA\n";
		}
		else{
			merge(a,b);
			cout << "SMECE\n";
		}
	}
}
