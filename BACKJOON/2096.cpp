#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
#define FOR(i,N) for(int i =0;i<N;i++)
using namespace std;

int main() {
	int N;
	cin>>N;
	vector<int> DP(3, 0);
	vector<int> MDP(3, 0);;
	cin>> DP[0] >> DP[1] >> DP[2];
	MDP = DP;
	vector<int> tempDP(3,0);
	vector<int> tempMDP(3, 0);
	int temp[3];
	for (int i = 1; i < N; i++) {
		cin >> temp[0]>>temp[1]>>temp[2];
		tempDP[0] = max(DP[0],DP[1]) + temp[0];
		tempDP[1] = max(max(DP[0], DP[1]),DP[2]) + temp[1];
		tempDP[2] = max(DP[1], DP[2]) + temp[2];
		DP = tempDP;
		tempMDP[0] = min(MDP[0], MDP[1]) + temp[0];
		tempMDP[1] = min(min(MDP[0], MDP[1]), MDP[2]) + temp[1];
		tempMDP[2] = min(MDP[1], MDP[2]) + temp[2];
		MDP = tempMDP;
	}
	cout<<max(max(DP[0],DP[1]),DP[2])<<" "<< min(min(MDP[0], MDP[1]), MDP[2]) <<endl;
}
