#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FOR(i,N) for(int i = 0;i<N;i++)
#define FOR1(i,N) for(int i = 1;i<N;i++)
using namespace std;

int main() {
	string A = " ";
	string B = " ";
	string tempA, tempB;
	cin>>tempA>>tempB;
	A += tempA;
	B += tempB;
	vector<vector<int>> DP(A.size(), vector<int>(B.size(), 0));
	FOR1(i, A.size()) {
		FOR1(j, B.size()) {
			if (A[i] == B[j]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}
	cout<<DP[A.size()-1][B.size()-1]<<endl<<endl;
}
