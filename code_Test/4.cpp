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
bool visit[1001];
vector<int> solution(string s) {
    vector<int> answer;
    cout<<s.length()<<endl;
    FOR(i,s.length()){
        int cnt =1;
        if(visit[i] == 1){
            continue;
        }
        visit[i] = 1;
        if(i == 0){
            for(int j = s.length()-1; j>=0;j--){
                if(s[i] != s[j] || visit[j] == 1){
                    break;
                }
                visit[j] = 1;
                cnt++;
            }
        }
        for(int j = i+1;j<s.length();j++){
            if(s[i] != s[j] || visit[j] == 1){
                break;
            }

            visit[j] = 1;
            cnt++;
        }
        //cout<<i<<" "<<cnt<<endl;
        answer.push_back(cnt);
    }
    sort(answer.begin(),answer.end());
    return answer;
}
int main(){
    solution("wwwww");
}
