#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FOR(i,N) for(int i = 0;i<N;i++)
#define FOR1(i,N) for(int i = 1;i<N;i++)
using namespace std;
vector<int> V;
vector<int> ans;
vector<vector<int>> DP;
int N;
int pel(int from, int to) {
	if (from >= to)return 1;
	if(DP[from][to] != -1) return DP[from][to];
	if (V[from] == V[to])return DP[from][to] = pel(from+1, to-1);
	else return DP[from][to] = 0;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);
	string S;
	cin >> S;

	N = S.size();
	FOR(i, N) {
		V.push_back(S[i]);
	}
	DP.assign(N, vector<int> (N,-1));
	ans.assign(N,987654321);
	FOR(i, N) DP[i][i] = true;
	FOR(i, N - 1) {
		if (V[i] == V[i + 1]) {
			DP[i][i + 1] = 1;
		}
	}
	int result = 0;
	FOR(i, N) {
		for(int j=i;j<N;j++){
			pel(i,j);
		}
	}
	for (int i = 0; i < N; i++) {	
			if (DP[0][i] == 1) {
				ans[i] = 0;
			}
			else {
				FOR(j,i){
					if(DP[j+1][i] == 1){
						ans[i] = min(ans[i], ans[j] +1);
				}
			}
		}
	}
	cout<< ans[N-1]+1<<endl;
}
