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
typedef long long ll;

ifstream ifs;
ofstream ofs;

int depth_Array[1001];
void go(int depth, int S, int E, vector <int> V){
    int max = *max_element(V.begin()+S, V.begin()+E);
    int max_Index = max_element(V.begin()+S, V.begin()+E) - V.begin();
    int left_Start = S;
    int left_End = max_Index;
    int right_Start = max_Index+1;
    int right_End = E;

    depth_Array[max_Index] = depth;

    if(V[S] != max) { go(depth+1, left_Start, left_End,V);}
    if(V[E-1] != max) { go(depth+1, right_Start, right_End,V);}

}
int main(){
    fill_n(depth_Array, 1001, -1); 
    ifs.open("permutation.inp");
    ofs.open("permutation.out");
    int T, n;
    ifs>>T;
    FOR(i,T){
        ifs>>n;
        vector <int> V;
        FOR(j,n){
            int temp;
            ifs>>temp;
            V.push_back(temp);
        }
        go(0,0,V.end()-V.begin(),V);
        FOR(j,n){
            ofs<<depth_Array[j]<<" ";
        }
        ofs<<endl;
    }
}