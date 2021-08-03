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
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000000 + 1
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

vector<int> solution(vector<string> gems) {
    set<string> S(gems.begin(), gems.end());
    map<string, int> M;
    deque<string> DQ;
    vector<int> answer(2);
    int len = 987654321 , start = 0, end=0;
  
    while(true){
        int i;
        for(i = end;i<gems.size();i++){
            M[gems[i]]++;
            if(M.size() == S.size()){
                end = i;
                break;
            }
        }
        if(i == gems.size()){
            break;
        }
        for(i = start; i<gems.size();i++){
            if(M[gems[i]] == 1){
                start = i;
                break;
            }
            else M[gems[i]]--;
        }
        
        if(end-start<len){
            answer[0] = start + 1;
            answer[1] = end + 1;
            len = end - start;
        }
        
        M.erase(gems[start]);
        start++;
        end++;
        
    }
    return answer;
}