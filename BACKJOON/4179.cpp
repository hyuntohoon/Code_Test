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

char board[1001][1001];
int fire_Board[1001][1001];
bool V[1001][1001];
int N, M;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
pair<int, int> M_Start;
queue <pair<int, int> > fire;

bool range_check(int x,int y,int N, int M){
    if(x>=0 && y>=0 &&x<N &&y<M){
        return 1;
    }
    return 0;
}

void fire_Move(){
    while(!fire.empty()){
        int x = fire.front().first;
        int y = fire.front().second;
        fire.pop();
        FOR(i,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(range_check(nx,ny,M,N)){
                if(board[ny][nx] == '.'){
                    if(fire_Board[ny][nx] > fire_Board[y][x] +1){
                        fire_Board[ny][nx] = fire_Board[y][x]+1;
                        fire.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }
}

void man_Move(){
    queue <pair<pair<int, int>,int> > man;
    man.push(make_pair(M_Start,0));
    while(!man.empty()){
        int x = man.front().first.first;
        int y = man.front().first.second;
        int now_Cnt = man.front().second;
        man.pop();
        FOR(i,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!range_check(nx,ny,M,N)){
                cout<<now_Cnt+1<<endl;
                return;
            }
            if(range_check(nx,ny,M,N)){
                if(board[ny][nx] == '.' && V[ny][nx] == 0){
                    //cout<<ny<<" "<<nx<<" "<<now_Cnt<<" "<<fire_Board[ny][nx]<<endl;
                    if(now_Cnt + 1 < fire_Board[ny][nx]){
                        V[ny][nx] = 1;
                        man.push(make_pair(make_pair(nx,ny),now_Cnt+1));
                    }
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return;
}
int main(){
    ifstream ifs;
    //ifs.open("3.inp");
    cin>>N>>M;
    FOR(i,N){
        FOR(j,M){
            fire_Board[i][j] = 987654321;
            cin>>board[i][j];
            if(board[i][j] == 'J'){
                board[i][j] = '.';
                M_Start = make_pair(j,i); // x,y
                V[i][j] = 1;
            }
            if(board[i][j] == 'F'){
                board[i][j] = '.';
                fire.push(make_pair(j,i));
                fire_Board[i][j] = 0;
            }
        }
    }
    fire_Move();
    man_Move();

}
