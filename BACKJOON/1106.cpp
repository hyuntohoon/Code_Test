#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define FOR(i,N) for(int i = 0;i<N;i++)
#define FOR1(i,N) for(int i = 1;i<N;i++)
using ll = long long;
using namespace std;

int main() {
	int C,N;
	cin>>C>>N;
	vector<int> weight(21);
	vector<int> price(21);
	vector<int> DP(100001,0);
	FOR(i, N) {
		cin>> weight[i] >>price[i];
	}
	FOR(i, weight.size()) {
		for (int w= 1;w< 100001;w++) {
			if(w-weight[i] >= 0){
				DP[w] = max(DP[w],DP[w-weight[i]] +price[i]);
			}
		}
	}
	FOR(i, 100001) {
		if (DP[i] >= C) {
			cout<<i<<endl;
			return 0;
		}
	}
}
