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


int main(){
    ifs.open("card.inp");
    ofs.open("card.out");
    int T;
    ifs>>T;
    while(T--){
        int card[1001];
        int DP[1001];
        int dist[1001];
        int DP_ex4[1001];
        FOR(i,1001) {DP_ex4[i] = -987654321;dist[i] = -1;}
        int N;
        ifs>>N;
        FOR(i,N){
            ifs>>card[i];
        }
        DP[0] = card[0];
        DP[1] = card[1];
        DP[2] = card[2];
        if(DP[0]>DP[1]){
            DP[3] = DP[0] + card[3];
            dist[3] = 0;
        }
        else{
            DP[3] = DP[1] + card[3];
            dist[3] = 1;
        }
        DP_ex4[3] = card[0]+card[3];
        for(int i = 4;i<N;i++){
            DP[i] = 0;
            int now_Max;
            if(DP[i-4] > DP[i-3]){
                now_Max = DP[i-4];
                dist[i] = i-4;
            }
            else{
                now_Max = DP[i-3];
                dist[i] = i-3;
            }
            DP_ex4[i] = now_Max+card[i];
            if(dist[i-2] != i-4 ){ // i-2가 i-4를 선택하지 않은 경우
                if(DP[i-2]>now_Max){
                    now_Max = DP[i-2];
                    dist[i] = i-2;
                }
            }
            if(DP_ex4[i-2]>now_Max){
                now_Max = DP_ex4[i-2];
                dist[i] = i-2;
            }
            DP[i] += now_Max + card[i];
        }
        ofs<<DP[N-1]<<endl;
    }
}

