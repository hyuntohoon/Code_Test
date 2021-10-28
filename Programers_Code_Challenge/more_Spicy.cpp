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
using namespace std;

priority_queue<int,vector<int>,greater<int>> PQ;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(auto elem : scoville){
        PQ.push(elem);
    }
    while(1){
        if(PQ.top() >= K){
            break;
        }
    
        if(PQ.size() == 1){
            answer = -1;
            break;
        }
        answer++;
        int F = PQ.top();
        PQ.pop();
        int S = PQ.top();
        PQ.pop();
        PQ.push(F+S*2);
    }
    //cout<<answer<<endl;
    return answer;
}