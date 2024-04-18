#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
#define FOR(i,N) for(int i =0;i<N;i++)
using ll = long long;
using namespace std;

ll DP[51][51][51][51];

ll memo(int N, int A, int B, int C) {
	if (N == 0){
		if(A == 0 && B == 0 && C == 0) {
		return 1;
		}	
		else {
			return 0;
		}
	}
	ll &temp = DP[N][A][B][C];
	if(DP[N][A][B][C] != -1){
		return DP[N][A][B][C];
	}
	temp = 0;
	temp += memo(N - 1, A - 1, B, C);
	temp += memo(N - 1, A, B-1, C);
	temp += memo(N - 1, A, B, C-1);
	temp += memo(N - 1, A - 1, B-1, C);
	temp += memo(N - 1, A , B-1, C-1);
	temp += memo(N - 1, A - 1, B, C-1);
	temp += memo(N - 1, A - 1, B-1, C-1);
	temp %= 1000000007;
	return temp;
}
int main() {
	int S;
	cin>>S;
	int A,B,C;
	cin>>A>>B>>C;
	memset(DP, -1, sizeof(DP));
	cout<<memo(S,A,B,C)<<endl;
	
}
