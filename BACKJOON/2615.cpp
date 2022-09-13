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

int board[19][19];
int check[19][19][4];
int dir[8][2] = {{1,0},{0,1},{1,1},{-1,1}};

int DFS(int y,int x, int k){
    check[y][x][k] = 1;
    int count = 1;
    int ny = y + dir[k][0];
    int nx = x + dir[k][1];
    if(board[y][x] == board[ny][nx]) count+=DFS(ny,nx,k);

    return count;
}

int main(){
    FOR(i,19){
        FOR(j,19){
            cin>>board[i][j];
        }
    }
    FOR(i,19){
        FOR(j,19){
            if(board[j][i] == 0) continue;
            FOR(k,4){
                if(check[j][i][k]) continue;
                if(DFS(j,i,k) == 5) {
                    cout<<board[j][i]<<endl<<j+1<<" "<<i+1<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<0<<endl;
    return 0;
}