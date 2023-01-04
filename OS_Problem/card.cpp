#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include<stdio.h>
#include<fstream>
#include<sstream>
#include<cstring>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
#define endl "\n"
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
ifstream ifs;
ofstream ofs;

int T, N, arr[1001], DP[1001][1001];

int go(int L, int R, int now) {
	if (L > R) {
        return 0;
    }
	if (DP[L][R]) {
        return DP[L][R];
    }
	if (now % 2) {
	   return DP[L][R] = max(arr[L] + go(L + 1, R, now + 1), arr[R] + go(L, R - 1, now + 1));
    }
	else{
	   return DP[L][R] = min(go(L + 1, R, now + 1), go(L, R - 1, now + 1));
    }
}

int main() {
	
    ifs.open("card.inp");
    ofs.open("card.out");
	ifs >> T;
	while(T--){
		ifs >> N;
		FOR(i,N){
            ifs >> arr[i];
        }
		go(0, N - 1, 1);
		ofs << DP[0][N - 1] << endl;
		memset(DP, 0, sizeof(DP));
	}
	return 0;
}