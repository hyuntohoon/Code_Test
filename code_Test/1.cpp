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
int MAP[4];
vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int Max_Value = 1;
    for(auto elem : arr){
        MAP[elem]++;
        Max_Value = max(Max_Value, MAP[elem]);
    }
    FOR1(i,4){
        answer.push_back(Max_Value-MAP[i]);
    }
    for(auto elem : answer){
        cout<<elem<<" ";
    }
    return answer;
}