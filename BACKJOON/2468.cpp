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
#define FOR2(i,n) for(int i=2;i<n;i++)
#define FORV(elem,V) for(auto elem : V)
#define MAX 1010
#define DIV 1000000009
#define DOWN 1
#define RIGHT 2
#define endl "\n"

using namespace std;
typedef long long ll;
void buffer_except(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool range_check(int x,int y,int N, int M){
    if(x>=0 && y>=0 &&x<N &&y<M){
        return 1;
    }
    return 0;
}

queue<pair<int, int>> Q;
int N;
int arr[101][101];
bool visit[101][101];
void BFS(int rain){
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        FOR(i,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(range_check(nx, ny, N, N) && arr[ny][nx] > rain && visit[ny][nx] == 0){
                visit[ny][nx] = 1;
                Q.push(make_pair(nx, ny));
            }
        }
    }
}

int main(){
    cin>>N;
    FOR(i,N){
        FOR(j,N){
            cin>>arr[i][j];
        }
    }
    int ans = 1;
    FOR1(k,101){
        int cnt = 0;
        memset(visit, 0, sizeof(visit));
        FOR(i,N){
            FOR(j,N){
                if(arr[i][j]>k && visit[i][j] == 0){
                    visit[i][j] = 1;
                    Q.push(make_pair(j, i));
                    BFS(k);
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout<<ans<<endl;
}
