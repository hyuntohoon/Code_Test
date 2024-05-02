#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FOR(i,N) for(int i = 0;i<N;i++)
#define FOR1(i,N) for(int i = 1;i<N;i++)
using namespace std;
vector<int> V;
vector<vector<int>> DP;

bool pel(int from, int to) {
	if (from >= to)return true;
	if(DP[from][to] != -1) return DP[from][to];
	if (V[from] == V[to])return DP[from][to] = pel(from+1, to-1);
	else return DP[from][to] == 0;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);
	int N;
	cin >> N;
	V.assign(N,0);
	DP.assign(N, vector<int> (N,-1));
	FOR(i, N) {
		cin>>V[i];
	}
	FOR(i, N) DP[i][i] = true;
	FOR(i, N - 1) {
		if (V[i] == V[i + 1]) {
			DP[i][i + 1] = 1;
		}
	}
	int M;
	cin>>M;
	FOR(i, M) {
		int from, to;
		cin>>from>>to;
		cout<<pel(from-1, to-1)<<"\n";
	}
}
