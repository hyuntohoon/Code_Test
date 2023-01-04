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
#include <sstream>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
typedef long long ll;
using namespace std;

int dist[201][201]; // 값
int dist_Dir[201][201]; // 방향 우 좌 위 아
int board[201][201];
int N,M; // N == y , M == x
int dx[2] = {1,0};
int dy[2] = {0,1};
bool range_check(int x,int y,int N, int M){
    if(x>=0 && y>=0 &&x<N &&y<M){
        return 1;
    }
    return 0;
}

int go(){
    queue <pair<int,int> > Q;
    Q.push(make_pair(0,0));
    int a = 0;
    while(!Q.empty()){
        a++;
        if(a>10000000){
            return -1;
        }
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();
        //cout<<x<<" "<<y<<endl;
        if(y == N-1 && x == M-1) {
            return dist[y][x];
        }

        FOR(i,2){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int n_Dist = dist[y][x]+board[ny][nx];
            //cout<<dist[y][x]<<" "<<board[ny][nx]<<endl;
            if(range_check(nx,ny,M,N)){
                if(board[ny][nx] != -1){
                    if(n_Dist < dist[ny][nx]){
                        Q.push(make_pair(ny,nx));
                        dist[ny][nx] = n_Dist;
                        //cout<<ny<<" "<<nx<<" "<<n_Dist<<endl;
                        dist_Dir[ny][nx] = i;
                    }
                    else if(n_Dist == dist[ny][nx]){ // 같은 비용일 때 오른쪽이 우선
                        //cout<<ny<<" "<<nx<<endl;
                        if(i == 0){
                            //Q.push(make_pair(ny,nx));
                            dist_Dir[ny][nx] = i;
                        }
                    }
                }
            }
        }
    }
    return -1;
}
stack <pair<int, int> > S;
void dist_Print(){
    queue <pair<int, int> > Q;
    S.push(make_pair(N-1,M-1));
    Q.push(make_pair(N-1,M-1));
    while(!Q.empty()){
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();
        if(y== 0 && x == 0) return;
        if(dist_Dir[y][x] == 0){
            S.push(make_pair(y,x-1));
            Q.push(make_pair(y,x-1));
        }
        if(dist_Dir[y][x] == 1){
            S.push(make_pair(y-1,x));
            Q.push(make_pair(y-1,x));
        }
    }
}
int main(){
    ifstream ifs;
    ofstream ofs;
    ifs.open("gridpath.inp");
    ofs.open("gridpath.out");
    ifs>>N>>M;
    FOR(i,201){
        FOR(j,201){
            dist[i][j] = 987654321;
        }
    }
    FOR(i,N){
        FOR(j,M){
            int a;
            ifs>>a;
            board[i][j] = a;
        }
    }
    dist[0][0] = board[0][0];
    int result = go();
    if(result == -1) {
        ofs<<"No path.";
        return 0;
    }
    ofs<<result<<endl;
    dist_Print();
    while(!S.empty()){
        int y = S.top().first;
        int x = S.top().second;
        ofs<<"("<<y<<" "<<x<<")"<<endl;
        S.pop();
    }
}