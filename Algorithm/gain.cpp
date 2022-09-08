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
    int T;
    ifs.open("gain.inp");
    ofs.open("gain.out");
    ifs>>T;
    FOR(i,T){
        ifs>>N;
        vector <int> V;
        FOR(j,N){
            int a;
            ifs>>a;
            V.push_back(a);
        }
        sort(V.begin(),V.end());
        ofs<<V[N-1]+V[N-2]-V[0]-V[1]<<endl;
        
    }
}