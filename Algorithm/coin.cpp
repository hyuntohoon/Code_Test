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

int DP[101][101][101];


void go(int a, int b, int c){
    if(DP[a][b][c] == 0){
        bool check_Now = 0;
        FOR(i,3){ // a
            vector <int> V;
            int now_A = a-i-1;
            if(now_A < 0) break;
            V.push_back(now_A);
            V.push_back(b);
            V.push_back(c);
            sort(V.begin(),V.end());
            int now_DP = DP[V[0]][V[1]][V[2]];
            if(now_DP == 0) {
                go(V[0],V[1],V[2]);
            }
            now_DP = DP[V[0]][V[1]][V[2]];
            if(now_DP == 1){
                DP[a][b][c] = 2;
                return;
            }
        }
         FOR(i,3){ // b
             vector <int> V;
            int now_B = b-i-1;
            if(now_B < 0) break;
            V.push_back(now_B);
            V.push_back(a);
            V.push_back(c);
            sort(V.begin(),V.end());   
            int now_DP = DP[V[0]][V[1]][V[2]];
            if(now_DP == 0) {
                go(V[0],V[1],V[2]);
            }
            now_DP = DP[V[0]][V[1]][V[2]];   
            if(now_DP == 1){
                DP[a][b][c] = 2;
                return;
            }
        }
         FOR(i,3){ // c 
            vector <int> V;
            int now_C= c-i-1;
            if(now_C < 0) break;
            V.push_back(now_C);
            V.push_back(b);
            V.push_back(a);
            sort(V.begin(),V.end());
            int now_DP = DP[V[0]][V[1]][V[2]];
            if(now_DP == 0) {
                go(V[0],V[1],V[2]);
            }
            now_DP = DP[V[0]][V[1]][V[2]];
            if(now_DP == 1){
                DP[a][b][c] = 2;
                return;
            }
        } 
    }
    else{
        return;
    }
    if(DP[a][b][c] == 0)  DP[a][b][c] = 1;;
}
// 1 패배 2 승리
int main(){
    ifstream ifs;
    ofstream ofs;
    ifs.open("coin.inp");
    ofs.open("coin.out");
    DP[0][0][1] = 1;
    int T;
    ifs>>T; 
    FOR(i,T){
        vector <int> V;
        FOR(j,3){
            int a;
            ifs>>a;
            V.push_back(a);
        }
        ofs<<"("<<V[0]<<" "<<V[1]<<" "<<V[2]<<") : ";
        sort(V.begin(), V.end());
        go(V[0],V[1],V[2]);
        if(DP[V[0]][V[1]][V[2]] == 2) ofs<<"1"<<endl;
        else ofs<<"-1"<<endl;
    }
}