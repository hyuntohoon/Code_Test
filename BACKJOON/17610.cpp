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
#define FOR2(i,n) for(int i=2;i<n;i++)
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
vector<int> V;

int K, N;
bool visit[2600001];
bool use[14];
void DFS(int now, int sum){

    if(now == K){
        if(sum>=0) visit[sum] = 1;
        //cout<<sum<<endl;
        return;
    }
        DFS(now+1,sum);
        DFS(now+1,sum+V[now]);
        DFS(now+1,sum-V[now]);
        
    
}
int main(){
    cin>>K;
    FOR(i,K){
        int temp;
        cin>>temp;
        N+=temp;
        visit[temp] = 1;
        V.push_back(temp);
    }
    DFS(0,0);
    int ans = 0;
    FOR1(i,N){
        if(visit[i] == 0){
            ans++;
        }
    }
    cout<<ans<<endl;
}
