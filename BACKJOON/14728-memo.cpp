#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,N) for(int i = 0;i<N;i++)
#define FOR1(i,N) for(int i = 1;i<N;i++)
using namespace std;

int main() {
	int N, T;
	cin >> N >> T;
	vector<int> weights(N + 1);
	vector<int> values(N + 1);
	vector<int> DP(T + 1,0);
	FOR(i, N) {
		cin >> weights[i] >> values[i];
	}
	for (int i = 0; i < N; i++) {
		for (int w = T; w >= weights[i]; w--) {
			DP[w] = max(DP[w],DP[w-weights[i]] + values[i]);
		}
	}
	cout<<DP[T]<<endl;
}
