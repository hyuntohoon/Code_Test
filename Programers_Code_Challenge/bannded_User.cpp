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

int main(){
    
    vector<string> user_id;
    /*
    user_id.push_back("frodo");
    user_id.push_back("fradi");
    user_id.push_back("crodo");
    user_id.push_back("abc123");
    user_id.push_back("frodoc");
     */
    vector<int> order;
    for(int i=0;i<user_id.size();i++){
        order.push_back(i);
    }
    vector<string> banned_id;
    /*
    banned_id.push_back("fr*d*");
    banned_id.push_back("*rodo");
    banned_id.push_back("******");
    banned_id.push_back("******");
     */
    int answer = 0;
    set<vector<string>> S;
    do{
        bool F = 0;
        for(int i = 0;i<banned_id.size();i++){
            string now_id = user_id[order[i]];
            /*
            cout<<now_id<<" "<<banned_id[i]<<endl;
            cout<<now_id.size()<<" "<<banned_id[i].size()<<endl;*/
            if(now_id.size() == banned_id[i].size()){
                for(int j = 0;j<now_id.size();j++){
                    //cout<<now_id[j]<<" "<<banned_id[i][j]<<endl;
                    if(now_id[j] == banned_id[i][j]){
                        F = 1;
                    }
                    else if(banned_id[i][j] == '*'){
                        F = 1;
                    }
                    else{
                        F = 0;
                        break;
                    }
                }
            }
            else{
                F=0;
            }
            if(F == 0){
                break;
            }
        }
        if(F == 1){
            cout<<"----------------"<<endl;
            vector<string> V;
            for(int i = 0;i<banned_id.size();i++){
                cout<<user_id[order[i]]<<" "<<banned_id[i]<<endl;
                V.push_back(user_id[order[i]]);
            }
            sort(V.begin(), V.end());
            S.insert(V);
            cout<<"----------------"<<endl;
        }
        //cout<<endl;
        /*
        cout<<endl;
        for(auto elem : banned_id){
            cout<<elem<<" ";
        }
        cout<<endl;
        cout<<endl;*/
    }while(next_permutation(order.begin(),order.end()));
    answer = (int)S.size();
    cout<<answer<<endl;

}
/*
 순서와 상관 없이 제재 아이디가 중복인 경우 찾기 !!!
 */
