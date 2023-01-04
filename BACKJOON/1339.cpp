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
using namespace std;

int main(){
    int T;
    cin>>T;
    string S[11];
    set<int> alpha_Set;
    vector<int> V;

   FOR(i,T){
       cin>>S[i];
   }
   FOR(j,T){
    FOR(i,S[j].length()){
        alpha_Set.insert(S[j][i]);
    }
   }
   for(auto elem : alpha_Set){
    V.push_back((char)elem);
   }
   int ans = 0;
do{
    int sum =0;
    int start = 9;
    map<string ,int> M;
    FOR(i,V.size()){
        //cout<<(char)V[i]<<" : "<<start - i<<endl;
        string temp = "";
        temp+=(char)V[i];
        M[temp] = start - i;
    }
   FOR(i,T){
        string temp = "";
        FOR(j,S[i].length()){
            string now_Alpha = "";
            now_Alpha += S[i][j];
            string A = to_string(M[now_Alpha]);
            temp += A;
        }
        sum+=stoi(temp);
    }
    //cout<<sum<<endl;
    ans = max(ans,sum);

//cout<<"--------------------"<<endl;
}while(next_permutation(V.begin(),V.end()));
cout<<ans<<endl;
}