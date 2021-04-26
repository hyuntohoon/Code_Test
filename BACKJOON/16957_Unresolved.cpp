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
int arr[501][501];
int cnt[501][501];
int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = {1,1,1,0,0,-1,-1,-1};
int R,C;
bool range_check(int x, int y){
    if(x>=C || y>=R || x<0 ||y<0){
        return 0;
    }
    return 1;
}
void chess(int x, int y){ // 현재위치
    int M = arr[y][x];
    int N =-1;
    FOR(i,8){
        int nx = x + dx[i];
        int ny = y + dy[i];
    
        if(range_check(nx, ny)){
            //cout<<"M: "<<M<<" arr : "<<arr[ny][nx]<<endl;
            if(M>arr[ny][nx]){
                M = arr[ny][nx];
                N = i;
            }
        }
    }
    if(N == -1){
        cnt[y][x]++;
        return;
    }
    
    //cout<<N<<endl;
    int nx = x + dx[N];
    int ny = y + dy[N];
    chess(nx, ny);
   // cout<<"cnt["<<ny<<"]["<<nx<<"] : "<<cnt[ny][nx]<<endl;
}
int main(){
    buffer_except();
    cin>>R>>C;
    FOR(i,R){
        FOR(j,C){
            cin>>arr[i][j];
        }
    }
    
    FOR(i,R){
        FOR(j,C){
            //cout<<"x y : "<<j<<i<<endl;
            chess(j, i);
        }
    }
    FOR(i,R){
        FOR(j,C){
            cout<<cnt[i][j]<<" ";
        }
        cout<<endl;
    }
}
