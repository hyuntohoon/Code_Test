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
ifstream ifs;
ofstream ofs;
int N;

int main(){
    N = 10;
    int a = 0;
    int DP[301][21];
    DP[1][1] = 1;
    FOR(i,N+1){ // N까지
        DP[i][1] = 1;
        if(i>20){ 
            DP[i][20] = 1;
        }
        else{
             DP[i][i] = 1;
        }
        FOR(j,i){ // 현재 숫자의 K까지
        if(j==20) break;
        if(j==1 ) continue; 
        DP[i][j] = 0;
        DP[i][j] = DP[i-1][j-1];
        //cout<<i<<" "<<j<<" : "<<DP[i][j]<<" "<<endl;
            
            FOR(o,(i/2)+1){
                if(j-o == 0) break;
                cout<<"---------------"<<endl;
                cout<<i<<" "<<j<<" "<<o<<" "<<i-o<<" "<<j-o<<endl;
                cout<<"---------------"<<endl;
                //DP[i][j] += DP[i-1][o] + DP[i-o][j-o];
                //cout<<o<<" "<<i-o<<endl;
                //DP[i][j] = DP[i-o][j-o];
                
                FOR(m,o+1){
                    cout<<o<<" "<<m<<" "<<i-o<<" "<<j-m<<endl;
                    //DP[i][j] += DP[o][m] * DP[i-o][j-m];
                }
                //cout<<i<<" "<<j<<" : "<<DP[i][j]<<" "<<endl;
           }
        }
    }
}
