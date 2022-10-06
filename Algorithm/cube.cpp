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
#define FOR(i,n) for(int i=1;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
using namespace std;
int N,M;
int T;
ifstream ifs;
ofstream ofs;

int DP[202][202][202];
int main(){
    ifs.open("cube.inp");
    ofs.open("cube.out");
    FOR(W,201){
        FOR(L,201){
            FOR(H,201){
                if(DP[W][L][H] == 0){
                    //cout<<"now_DP:"<<DP[W][L][H]<<endl;
                    if (W == 1){
                        DP[W][L][H] = L * H;
                    }
                    else if(H == 1){
                        DP[W][L][H] = W * L;
                    }
					else if(L == 1){
                        DP[W][L][H] = W * H;
                    }
					else if(W % H == 0 && L % H == 0){
                        DP[W][L][H] = (W/H)*(L/H);
                    }
					else if(W % L == 0 && H % L == 0){
                        DP[W][L][H] = (W/L)*(H/L);
                    }
					else if(L % W == 0 && H % W == 0){
                        DP[W][L][H] = (L/W)*(H/W);
                    }
					else {
						DP[W][L][H] = 987654321;
                      //cout<<DP[W][L][H]<<endl;
						for(int i = 1; i <= W / 2; i++){
							DP[W][L][H] = min(DP[W][L][H], DP[i][L][H] + DP[W-i][L][H]);
                        }
						for(int i = 1; i <= L / 2; i++){
							DP[W][L][H] = min(DP[W][L][H], DP[W][i][H] + DP[W][L-i][H]);
                        }
						for(int i = 1; i <= H / 2; i++){
							DP[W][L][H] = min(DP[W][L][H], DP[W][L][i] + DP[W][L][H-i]);
                        }
					}
                    //cout<<DP[W][L][H]<<endl;
                    DP[W][H][L]=DP[L][W][H]=DP[L][H][W]=DP[H][L][W]=DP[H][W][L]=DP[W][L][H];
                }
            }
        }
    }
    int T;
     ifs>>T;
     while(T--){
         int W,L,H;
         ifs>>W>>L>>H;
         ofs<<DP[W][L][H]<<endl;
     }
}