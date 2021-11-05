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
    string N;
    cin>>N;
    priority_queue<int> PQ;
    FOR(i,N.size()){
        int temp = (int)N[i] - 48;
        //cout<<temp<<" ";
        PQ.push(temp);
    }
    string ans = "";
    while(!PQ.empty()){
        int a = PQ.top();
        cout<<a;
        PQ.pop();
    }
    cout<<ans<<endl;
}

