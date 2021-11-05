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
int T;
int N,M,K;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int be[51][51];
bool visit[51][51];
int cnt = 0;
bool range_check(int x,int y,int N, int M){
    if(x>=0 && y>=0 &&x<N &&y<M){
        return 1;
    }
    return 0;
}
vector<pair<int, int>> V;
void BFS(int a,int b){
    queue<pair<int , int>> Q;
    Q.push(make_pair(a, b));
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        FOR(i,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(range_check(nx, ny, N, M) && visit[ny][nx] == 0 && be[ny][nx] == 1){
                visit[ny][nx] = 1;
                //cout<<"dnsajdnaskd"<<ny<<" "<<nx<<endl;
                Q.push(make_pair(nx,ny));
            }
        }
    }
    cnt++;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&N,&M,&K);
        memset(be, 0, sizeof(be));
        memset(visit, 0, sizeof(visit));
        V.clear();
        cnt = 0;
        FOR(i,K){
            int x,y;
            scanf("%d %d",&x,&y);
            be[y][x] = 1;
            V.push_back(make_pair(x, y));
        }
        for(auto elem : V){
            int nx = elem.first;
            int ny = elem.second;
            if(visit[ny][nx] == 0 ){
                BFS(nx,ny);
            }
        }
        cout<<cnt<<endl;
        
    }
}