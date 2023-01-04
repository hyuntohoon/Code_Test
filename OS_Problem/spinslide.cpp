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
int N,M;
int T;
ifstream ifs;
ofstream ofs;
char board[101][101];
char rotate_Board[101][101];
char slide_Board[101][101];
void rotate(){
    FOR(i,N){
        FOR(j,N){
            int to = N-i-1;
            rotate_Board[j][to] = board[i][j];
            //cout<<j<<" "<<to<<"|"<<i<<" "<<j<<endl;
        }
    }
    /*
    FOR(i,N){
        FOR(j,N){
            cout<<rotate_Board[i][j];
        }
        cout<<endl;
    }*/ 
}
void slide(){
    FOR(i,N){
        int count = 0;
        for(int j = N-1;j>-1;j--){
            board[j][i] = '.';
            char now_C = rotate_Board[j][i];
            if(now_C == '.'){
                count++;
            }
            else{
                board[j+count][i] = now_C;
            }
        }
    }
    /*
    FOR(i,N){
        FOR(j,N){
            cout<<slide_Board[i][j];
        }
        cout<<endl;
    }
    */
}


void running(){
    FOR(i,M){
        rotate();
        slide();
    }
     FOR(i,N){
        FOR(j,N){
            ofs<<board[i][j];
        }
        ofs<<endl;
    }
    ofs<<endl;
}
void input_Set(){
    ifs>>N>>M;
    FOR(i,N){
        FOR(j,N){
            ifs>>board[i][j];
        }
    }
    running();
}

int main(){
    ifs.open("spinslide.inp");
    ofs.open("spinslide.out");
    ifs>>T;
    FOR(i,T){
        ofs<<"Case #"<<i+1<<":"<<endl;
        input_Set();
    }
    ifs.close();
    ofs.close();
    return 0;
}
