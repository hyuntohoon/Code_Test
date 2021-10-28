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
#define MAX 1000000 + 1
#define DIV 1000000009
#define DOWN 1
#define RIGHT 2
#define endl "\n"
#define has(a) (building.find(temp_Build[(a)])!=building.end())
using namespace std;
typedef long long ll;
void buffer_except(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

stack<char> STACK;
int solution(string s)
{
    STACK.push(s[0]);
    for(int i = 1;i<s.size();i++){
        if(STACK.empty()){
           // cout<<"hi"<<endl;
            STACK.push(s[i]);
            continue;
        }
        if(STACK.top() == s[i]){
            STACK.pop();
        }
        else{
            STACK.push(s[i]);
        }
    }
    if(STACK.empty()){
        return 1;
    }
    else{
        return 0;
    }
}