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
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000000 + 1
#define DIV 1000000009
#define RED 1
#define BLUE 0
#define endl "\n"
using namespace std;
typedef long long ll;

void buffer_except(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
bool desc(int a, int b){ return a < b; }


int main(){
    buffer_except();
    int N,M;
    cin>>N>>M;
    string temp;
    vector<string> R,RS;
    set<string> S;
    FOR(i,N){
        cin>>temp;
        S.insert(temp);
    }
   // cout<<find(R.begin(),R.end(),1);
   // int cnt=0;
    FOR(i,M){
        cin>>temp;
        
        if(S.find(temp) != S.end()){
            R.push_back(temp);
        }
        
    }
    sort(R.begin(),R.end());
    
    cout<<R.size()<<endl;
    for(auto elem:R){
        cout<<elem<<endl;
    }
}