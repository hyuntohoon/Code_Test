#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define FOR(i,N) for(int i =0;i<N;i++)
#define FOR1(i,N) for(int i =1;i<N;i++)
using namespace std;
int main() {
	int T;
	cin>>T;
	FOR(t, T) {
	int N;
	cin>>N;
	vector<int> coin(N);
	FOR(i, N) {
	cin>>coin[i];
	}
	int target;
	cin>>target;
	vector<int> DP(target+1,0);
	DP[0] = 1;
	for (int i = 0; i < N; i++) {
		for(int j=coin[i];j<=target;j++){
			DP[j] = DP[j] + DP[j-coin[i]];
		}
	}
	cout<<DP[target]<<endl;
	}
}
