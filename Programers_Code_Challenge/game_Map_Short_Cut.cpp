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
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000000 + 1
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
int dy[4] = {0,0,-1,1};
bool range_check(int x, int y,int N, int M){
    if(x>=0 && y >=0 && x<M && y<N){
        return 1;
    }
    return 0;
}
struct map_State{
    int x;
    int y;
    int cost;
    map_State(int x, int y, int cost):x(x),y(y),cost(cost){}
};

int solution(vector<vector<int>> maps)
{
    int n = maps.size(); // 세로
    int m = maps[0].size(); // 가로
    queue<map_State> Q;
    int arr[100][100];
    FOR(i,100){
        FOR(j,100){
            arr[i][j] = 987654321;
        }
    }
    arr[0][0] = 1;
    Q.push(map_State(0,0,1));
    while(!Q.empty()){
        int x = Q.front().x;
        int y = Q.front().y;
        int cost = Q.front().cost;
        Q.pop();
        FOR(i,4){
            int nx = x + dx[i];
            int ny = y+ dy[i];
            int ncost = cost + 1;
            if(range_check(nx,ny,n,m) && maps[ny][nx] == 1){
                if(arr[ny][nx]>ncost){
                    arr[ny][nx] = ncost;
                    Q.push(map_State(nx,ny,ncost));
                }
            }
        }
    }
    int answer = arr[n-1][m-1];
    if (answer == 987654321){
        return -1;
    }
    return answer;
}