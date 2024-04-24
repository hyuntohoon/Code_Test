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
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
using namespace std;

int board[501][501];
int visit[501][501];
int N, M;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int DP[501][501];

bool range_check(int x,int y,int N, int M){
    if(x>=0 && y>=0 &&x<N &&y<M){
        return 1;
    }
    return 0;
}

int DFS(int x, int y){
    if(x == M-1 && y == N-1) {
        return 1;
        }
    if(DP[y][x] != -1) return DP[y][x];
    DP[y][x] = 0;
    FOR(i,4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(range_check(nx,ny,M,N)){
            if(board[ny][nx] < board[y][x]){
                DP[y][x] = DP[y][x] + DFS(nx, ny);
            }
        }
    }
    return DP[y][x];
}
int main(){
    cin>>N>>M;
    FOR(i,N){
        FOR(j,M){
            cin>>board[i][j];
            DP[i][j] = -1;
        }
    }
    cout<<DFS(0,0)<<endl;
}
