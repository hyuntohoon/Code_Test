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
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000000 + 1
#define DIV 1000000009
#define RED 1
#define BLUE 0
#define endl "\n"
using namespace std;
typedef long long ll;
void buffer_except(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
int DP[1001][1001];
int arr[1001][1001];
int N, M;
int dx[3] = {1,1,0};
int dy[3] = {0,1,1};

bool range_check(int x,int y){
    if(x>=M || y>=N){
        return 0;
    }
    return 1;
}
int main(){
    buffer_except();
    cin>>N>>M;
    FOR(i,N){
        FOR(j,M){
            cin>>arr[i][j];
        }
    }
    FOR(i,N){
        FOR(j,M){
            int sum = max(DP[i-1][j],DP[i][j-1]);
            sum = max(DP[i-1][j-1],sum);
            DP[i][j] = sum + arr[i][j];
        }
    }
    cout<<DP[N-1][M-1]<<endl;
}
