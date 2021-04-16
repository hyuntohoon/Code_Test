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
bool desc(int a, int b){ return a < b; }


int dx[3] = {1, 1, 0};
int dy[3] = {0, 1, 1};
int arr[16+1][16+1];
vector<pair<pair<int,int>, int>> V;
int cnt;
int N;
bool range_check(int x, int y){
    if(x>=N || y>=N || x<0 || y<0){
        return 0;
    }
    return 1;
}
void DFS(int x, int y, int S){
    if(x == N-1 && y == N-1){
        cnt++;
        return;
    }

    if(S == 0){
        for(int i =0;i<2;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(range_check(nx, ny) && arr[ny][nx] == 0){
                if(i == 1){
                    if(arr[ny-1][nx] == 0 && arr[ny][nx-1] == 0){
                        DFS(nx,ny,i);
                    }
                }
                else{
                    DFS(nx,ny,i);
                }
            }
        }
    }
    if(S == 1){
        for(int i =0;i<3;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(range_check(nx, ny) && arr[ny][nx] == 0){
                if(i == 1){
                    if(arr[ny-1][nx] == 0 && arr[ny][nx-1] == 0){
                        DFS(nx,ny,i);
                    }
                }
                else{
                    DFS(nx,ny,i);
                }
            }
        }
    }
    if(S == 2){
        for(int i =1;i<3;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(range_check(nx, ny) && arr[ny][nx] == 0){
                if(i == 1){
                    if(arr[ny-1][nx] == 0 && arr[ny][nx-1] == 0){
                        DFS(nx,ny,i);
                    }
                }
                else{
                    DFS(nx,ny,i);
                }
            }
        }
    }
    
}

int main(){
    buffer_except();
    cin>>N;
    FOR(i,N){
        FOR(j,N){
            cin>>arr[i][j];
        }
    }
    DFS(1,0,0);
    cout<<cnt<<endl;
}