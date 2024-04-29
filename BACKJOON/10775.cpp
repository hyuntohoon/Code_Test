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
	int rootX = find(x);
	int rootY = find(y);
	if(rootX > rootY) swap(rootX,rootY);
	root[rootY] = rootX;
}
int main() {
	int G,P;
	cin>>G>>P;
	root.assign(G+1,0);
	FOR1(i, G + 1) {
		root[i] = i;
	}
	int result = 0;
	FOR(i, P) {
		int temp;
		cin>>temp;
		temp = find(temp);
		if(temp == 0) break;
		merge(temp,temp-1);
		result++;
	}
	cout<<result;
}
