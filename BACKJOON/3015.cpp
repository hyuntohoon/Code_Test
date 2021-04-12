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
#define MAX 100000+1
#define DIV 1000000009
#define RED 1
#define BLUE 0
#define endl "\n"
using namespace std;
typedef long long ll;

stack<pair<int,int>> S;

int main(){
    int N;
    int temp;
    cin>>N;
    ll result = 0;
    FOR(i,N){
        cin>>temp;
        while(!S.empty() && S.top().first<temp){
            result += S.top().second;
            S.pop();
        }
        if(S.empty()){
            S.push(make_pair(temp, 1));
        }
        else{
            if(S.top().first == temp){
                pair<int, int> P = S.top();
                S.pop();
                result +=P.second;
                if(!S.empty()){
                    result++;
                }
                P.second++;
                S.push(P);
            }
            else{
                S.push(make_pair(temp, 1));
                result++;
            }
        }
        
    }
    cout<<result<<endl;
}