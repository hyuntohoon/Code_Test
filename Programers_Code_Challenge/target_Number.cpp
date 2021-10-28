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
vector<int> V;
vector<int> N;
int answer = 0;
int T;
void go(double sum, int index){
    if(index == N.size()){
        if(sum == T){
            answer++;
        }
        return;
    }
    go(sum+N[index], index+1);
    go(sum-N[index], index+1);
}
int solution(vector<int> numbers, int target) {
    T = target;
    N = numbers;
    go(0,0);
    cout<<answer;
    return answer;
}