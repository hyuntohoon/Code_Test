#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include<stdio.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool range_check(int x,int y,int N, int M){
    if(x>=0 && y>=0 &&x<M &&y<N){
        return 1;
    }
    return 0;
}

queue <pair<pair<int,int>,vector<char> > > Q; // x y
char C[21][21];
int N,M;
int max_Gift;

void go(int x, int y, int L, bool gift_Map[]){ // x y set 
    max_Gift = max(max_Gift,L);
    FOR(i,4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(range_check(nx,ny,N,M)){
            if(gift_Map[C[ny][nx]-65] == 0){
                gift_Map[C[ny][nx]-65] = 1;
                go(nx,ny,L+1,gift_Map);
                gift_Map[C[ny][nx]-65] = 0;
            }
        }
    }
}

void buffer_except(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
int main(){
    buffer_except();
    int T;
    cin>>T;
    int now = 1;
    while(T--){
        bool gift_Map[26];
        memset(gift_Map,0,sizeof(gift_Map));
        cin>>N>>M; // y,x
        max_Gift = 0;
        FOR(i,N){
            FOR(j,M){
                cin>>C[i][j];
            }
        }
        gift_Map[C[0][0]-65] = 1;
        go(0,0,1,gift_Map);
        printf("#%d %d\n",now,max_Gift);
        now++;
    }
    return 0;
}