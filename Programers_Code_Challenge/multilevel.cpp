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
map<string, int> M_Sum;
map<string, string> M_Par;
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    
    M_Sum["Center"] = 0;
    int i = 0;
    for(auto elem : enroll){
        M_Sum[elem] = 0;
        M_Par[elem] = referral[i];
        if(M_Par[elem] == "-"){
            M_Par[elem] = "Center";
        }
        i++;
    }
    
    queue<pair<string, int>> Q;
    i=0;
    for(auto elem : seller){
        Q.push(make_pair(elem, amount[i]*100));
        i++;
    }
    while(!Q.empty()){
        // 두가지 부모가 있거나 없거나 있으면 push
        string now_Seller = Q.front().first;
        int now_Amount = Q.front().second;
        Q.pop();
        cout<<"SUM : "<<now_Seller<<" "<<now_Amount -(now_Amount/10)<<endl;
        M_Sum[now_Seller] += now_Amount -(now_Amount/10);
        if(now_Amount/10<1){
            continue;
        }
        if(M_Par[now_Seller] == "Center"){ // root
            M_Sum["Center"] += now_Amount / 10;
        }
        else{ // not root
            //cout<<M_Par[now_Seller]<<" "<<now_Amount /10<<endl;
            Q.push(make_pair(M_Par[now_Seller], now_Amount /10));
        }
    }
    vector<int> answer;
    for(auto elem : enroll){
        answer.push_back(M_Sum[elem]);
        cout<<M_Sum[elem]<<" ";
    }
    return answer;
}

int main(){
    vector<string> enroll = {"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"};
    vector<string> referral = {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"};
    vector<string> seller = {"young", "john", "tod", "emily", "mary"};
    vector<int> amount = {12, 4, 2, 5, 10};
    solution(enroll, referral, seller, amount);
}