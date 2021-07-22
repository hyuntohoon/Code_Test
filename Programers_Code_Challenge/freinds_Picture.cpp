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

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.


bool condition(string picture, string now_S){
    char F = now_S[0];
    char S = now_S[2];
    char B = now_S[3];
    int dist = now_S[4] - '0' +1;
    //cout<<picture<<endl;
    int F_S_dist = abs((int)picture.find(F) - (int)picture.find(S));
    //cout<<F<<" "<<S<<" "<<B<<" "<<dist<<" "<<F_S_dist<<endl;
    if(B == '='){
        if(F_S_dist == dist){
            return true;
        }
    }
    else if(B == '<'){
        if(F_S_dist < dist){
            return true;
        }
    }
    else if(B == '>'){
        if(F_S_dist > dist){
            return true;
        }
    }
    return false;
}
int solution(int n, vector<string> data) {
    vector<char> V;
    V.push_back('A');
    V.push_back('C');
    V.push_back('F');
    V.push_back('J');
    V.push_back('M');
    V.push_back('N');
    V.push_back('R');
    V.push_back('T');
    int cnt = 0;
    do{
        string picture = "";
        for(auto elem:V){
            picture+=elem;
        }
        bool check = true;
        for(int i = 0;i<data.size();i++){
            if(condition(picture, data[i]) == false){
                check = false;
                break;
            }
        }
        if(check == true){
            cnt++;
        }
        
        //cout<<picture<<endl;
    }
    while(next_permutation(V.begin(),V.end()));
    return cnt;
}
