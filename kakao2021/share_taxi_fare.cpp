#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <tuple>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<n;i++)
#define MAX 1000000 + 1
#define DIV 1000000009
#define DOWN 1
#define RIGHT 2
#define endl "\n"
#define has(a) (building.find(temp_Build[(a)])!=building.end())
using namespace std;
typedef long long ll;
void buffer_except(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
int N;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    int DP[201][201];
    N = n+1;

    FOR1(i,N){
        FOR(j,N){
            DP[i][j] = 987654321;
        }
    }
    for(auto elem : fares){
        int from = elem[0]; //에서
        int to = elem[1]; // 으로
        int f = elem[2]; // 얼마
        DP[from][to] = f; // 기본 가격 저장
        DP[to][from] = f; // 반대편도
    }
    FOR1(i,N){
        FOR1(j,N){
            FOR1(k,N){
                if(i == j || j == k || i == k) continue;
                DP[j][k] = min(DP[j][i]+DP[i][k], DP[j][k]); // 3중 for문의 이유 => 가장 처음의 for문이 중간점을 나타냄
            }                                                  // 나타냄의 자체 => 최솟값을 구하는 경우
        }
    }
    answer = DP[s][a] + DP[s][b];
    //cout<<"aaa: "<<DP[s][a]<<" "<<DP[s][b]<<endl;
    FOR1(i,N){
        DP[i][i] = 0;
    }
    FOR1(i,N){ // i => 중간점 a,b
        if(DP[i][a] == 987654321 || DP[i][b] == 987654321 || DP[s][i] == 987654321) continue;
        // 모든 경우를 돌아보며 최솟값 찾아보기
        answer = min(DP[i][a] + DP[i][b] + DP[s][i], answer);
    }
    return answer;
}

