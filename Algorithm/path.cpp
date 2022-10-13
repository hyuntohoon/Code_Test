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
#include<sstream>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
#define endl "\n"
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std:fill( (T*)array, (T*)(array+N), val);
}


int M,N,K; // 세로, 가로
bool k_Board[102][102]; // 0 = x 1 = o
int cnt_K[102][102][250]; // y x k
int cost_Board[102][102][2]; // y x 0 =우 1 = 위
int dist[102][102][210]; // k마다 저장
int now_Cost[102][102][210]; // y x k
//int K_Cnt[210];
int dx[2] = {0, 1};
int dy[2] = {1, 0};
bool range_check(int x,int y,int N, int M){
    if(x>=0 && y>=0 &&x<N &&y<M){
        return 1;
    }
    return 0;
}

void bfs(){
    queue<pair<pair<int,int>, int > > Q; // x,y,k
    Q.push(make_pair(make_pair(0,0),0));
    now_Cost[0][0][0] = 0;
    while(!Q.empty()){
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int k = Q.front().second;
        //if(x == N-1 && y == M-1) {K_Cnt[k]++;K_Cnt[k] %=100000;}
        Q.pop();
        FOR(i,2){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nk = k;
            if(range_check(nx,ny,N,M)){
                //cout<<y<<" "<<x<<" "<<k<<endl;
                //cout<<ny<<" "<<nx<<" "<<k<<endl;
                int this_Cost = now_Cost[y][x][k] + cost_Board[ny][nx][i];
                //cout<<"this "<<this_Cost<<endl;
                if(k_Board[ny][nx] == 1) nk++; // find k
                if(now_Cost[ny][nx][nk]>this_Cost){ // 적은 경우 찾기
                    //cout<<"hi"<<endl;
                    now_Cost[ny][nx][nk] = this_Cost;
                    dist[ny][nx][nk] = i; // 해당 좌표는 i를 통해서 왔습니다.
                    //cout<<ny<<" "<<nx<<" "<<k<<endl;
                Q.push(make_pair(make_pair(nx,ny),nk));
                }
            }
        }
    }
};

int main(){
    int C;
    ifstream ifs;
    ofstream ofs;
    ifs.open("path.inp");
    ofs.open("path.out");
    ifs>>C;
    int T =1;
    while(C--){
        ofs<<"Test Case No:"<<T<<endl;
        T++;
        
        Fill(k_Board, 0);
        Fill(cost_Board, 0);
        Fill(cnt_K, 0);
        Fill(dist, -1);
        Fill(now_Cost, 123456789);
        
        ifs>>M>>N>>K;
        FOR(i,K){
            now_Cost[0][0][i] = 0;
        }
        FOR(i,K){
            int x,y;
            ifs>>y>>x;
            k_Board[y][x] = 1;
        }
        FOR(i,M){
            for(int j=1;j<N;j++){
                int temp;
                ifs>>temp;
                cost_Board[i][j][1] = temp;
            }
        }
        for(int i = 1;i<M;i++){
            FOR(j,N){
                int temp;
                ifs>>temp;
                cost_Board[i][j][0] = temp;
            }
        }
        bfs();
        
        int count[101][101][201];
        Fill(count, 0);
        int arr_K = 1;
        count[0][0][0] = 1;
        FOR(i,M){
            FOR(j,N){
                if(j==0 && i ==0) continue;
                if(i == 0){ // 위 안 더하기
                    FOR(o,K+1){
                        count[i][j][o]=count[i][j-1][o];
                    }
                    //*count[i][j] = *count[i][j-1]
                }
                else if(j == 0){ // 옆 안 더하기
                    FOR(o,K+1){
                        count[i][j][o]=count[i-1][j][o];
                    }
                    //*count[i][j] = *count[i-1][j];
                }
                else{
                    FOR(o,K+1){
                        count[i][j][o] = count[i-1][j][o];
                        count[i][j][o] += (count[i][j-1][o]%100000);
                    }
                }
                if(k_Board[i][j]==1){
                    for(int o = K;o>0;o--){
                        count[i][j][o] = count[i][j][o-1];
                    }
                    count[i][j][0] = 0;
                }
            }
        }
        /*
        FOR(i,M){
            FOR(j,N){
                FOR(o,K+1){
                    cout<<count[i][j][o];
                }
                cout<<" ";
            }
            cout<<endl;
        }*/
        FOR(i,K+1){
            int x = N-1;
            int y = M-1;
            int k = i;
            //cout<<"K : "<<k<<" "<<K_Cnt[i]<<" least: "<<now_Cost[y][x][k]<<endl;
            if(now_Cost[y][x][k] == 123456789) continue;
            ofs<<"k:"<<k<<" count:"<<count[M-1][N-1][i]%100000<<" cost:"<<now_Cost[y][x][k]<<endl;
            //cout<<"K : "<<k<<" "<<K_Cnt[i]<<" least: "<<now_Cost[y][x][k]<<endl;
            bool check = 0;
            stack<pair<int,int> > S;
            while(true){
                int a;
                if(dist[y][x][k] ==1){a =0;}
                else a =1;
                S.push(make_pair(y,x));
                //cout<<"("<<y<<", "<<x<<") K:"<<k<<endl;
                if(x == 0 && y == 0){
                    break;
                }
                
                //cout<<dist[y][x][k]<<endl;
                if(dist[y][x][k] == 0) y--;
                else x--;
                if(check == 1){
                    check = 0;
                    k--;
                }
                if(k_Board[y][x] == 1) {
                    check = 1;
                }
            }
            while(!S.empty()){
                int y = S.top().first;
                int x = S.top().second;
                S.pop();
                ofs<<"("<<y<<","<<x<<")";
                if(S.size() != 0){
                    ofs<<"->";
                }
            }
            ofs<<endl;
        }
        ofs<<endl;
    }
}