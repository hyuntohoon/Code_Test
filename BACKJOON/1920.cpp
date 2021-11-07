#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <tuple>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<n;i++)
#define FORV(elem,V) for(auto elem : V)
#define MAX 1010
#define DIV 1000000009
#define DOWN 1
#define RIGHT 2
#define endl "\n"

using namespace std;
typedef long long ll;
void buffer_except(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main(){
    int N, M;
    map<int,bool> map;
    scanf("%d", &N);
    FOR(i,N){
        int temp;
        scanf("%d", &temp);
        map[temp] = 1;
    }
    scanf("%d", &M);
    FOR(i,M){
        int temp;
        scanf("%d", &temp);
        if(map[temp]){
            cout<<"1"<<endl;
        }
        else{
            cout<<"0"<<endl;
        }
    }
}
