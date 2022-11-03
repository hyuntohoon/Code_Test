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
#define FOR1(i,n) for(int i=1;i<n;i++)
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
typedef long long ll;
using namespace std;
ifstream ifs;
ofstream ofs;

int T, DP[5001][5001]; 
int SL[100], SR[100], tempLeft[100], tempRight[100];
int main(){
    ifs.open("color.inp");
    ofs.open("color.out");
	ifs>>T;
	while(T--){
		string S,T; 
        ifs>>S>>T; 
        S='0'+S; 
        T='0'+T;
		for(int i='A';i<='Z';i++) SL[i]=SR[i]=tempLeft[i]=tempRight[i]=0;
		for(int i=1;i<S.size();i++) FOR1(i,S.size()){SR[S[i]]=i; if(!SL[S[i]]) SL[S[i]]=i;}
		for(int i=1;i<T.size();i++) FOR1(i,T.size()){tempRight[T[i]]=i; if(!tempLeft[T[i]]) tempLeft[T[i]]=i;}
		FOR(i,S.size()){ 
            FOR(j,T.size()){
                DP[i][j]=123456789;
            }
        }
		DP[0][0]=0; 
		FOR(i,S.size()){ 
            FOR(j,T.size()){
                int T1 = 0, T2 = 0;
                if(SL[S[i+1]] == i+1 && (tempLeft[S[i+1]] == 0 || tempLeft[S[i+1]] > j)) T1 -= i+j+1;
                if(SR[S[i+1]] == i+1 && (tempRight[S[i+1]] == 0 || tempRight[S[i+1]] <= j)) T1 += i+j+1;
                DP[i+1][j] = min(DP[i+1][j], DP[i][j] + T1);
                if(tempLeft[T[j+1]] == j+1 && (SL[T[j+1]] == 0 || SL[T[j+1]] > i)) T2 -= i+j+1;
                if(tempRight[T[j+1]] == j+1 && (SR[T[j+1]]==0 || SR[T[j+1]] <= i)) T2 += i+j+1;
                DP[i][j+1] = min(DP[i][j+1], DP[i][j] + T2);
		    }
        }
		ofs<<DP[S.size()-1][T.size()-1]<<endl;
	}
}


