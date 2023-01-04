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
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <cstring>

#define FOR(i,n) for(int i=1;i<=n;i++)
#define FOR1(i,n) for(int i=0;i<=n;i++)
using namespace std;



int DP[MAX][MAX][2 * MAX][2];
const int PPO = 987654321;
const int MAX = 100 + 5;
int T, M, N, L, G;
int DO[MAX][MAX];
int RI[MAX][MAX];

ifstream ifs;
ofstream ofs;

bool check(int y, int x) {
	if (y <= 0 || y > M || x <= 0 || x > N)
		return false;
	return true;
}
int main() {

    ifs.open("drive.inp");
    ofs.open("drive.out");
	ifs >> T;


	while (T--) {
		ifs >> M >> N >> L >> G;


        memset(DP, 0x3f, sizeof(DP)); // 
        DP[1][1][0][0] = DP[1][1][0][1] = 0;
		FOR(i,M) { 
			for (int j = 1; j < N; j++) { 
				ifs >> RI[i][j];
			}
		}
		for (int i = 1; i < M; i++) {
			FOR(j,N) { 
				ifs >> DO[i][j];
			}
		}
		FOR(i,M) {  //
			FOR(j,N) {
				for (int k = 0; k < 2 * max(M,N); k++) {
					if (i + 1 <= M) {
						DP[i + 1][j][k][0] = min(DP[i + 1][j][k][0], DP[i][j][k][0] + DO[i][j]);
						DP[i + 1][j][k + 1][0] = min(DP[i + 1][j][k + 1][0], DP[i][j][k][1] + DO[i][j]);




					}
					if (j + 1 <= N) {
						DP[i][j + 1][k][1] = min(DP[i][j + 1][k][1], DP[i][j][k][1] + RI[i][j]);
						DP[i][j + 1][k + 1][1] = min(DP[i][j + 1][k + 1][1], DP[i][j][k][0] + RI[i][j]);
					}
				}
			}
		}
		int BBP = PPO;
		for (int i = 0; i <= 2 * max(M,N); i++) { // 
			if (DP[M][N][i][0] <= G) BBP = min(BBP, (M + N - 2) * L + i);
			if (DP[M][N][i][1] <= G) BBP = min(BBP, (M + N - 2) * L + i);
		}
		if (BBP == PPO) ofs<<-1<<endl;
		else ofs<<BBP<<endl;
	}
	return 0;
}
