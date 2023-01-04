#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include<stdio.h>
#include<fstream>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
using namespace std;
set <int> T;
stack <int> S; // 위치, 값

void table_Set(int n){
    FOR(i,n){
        T.insert(i);
    }
}
void cmd_Ex(int k, vector<string> cmd){
    int X;
    auto it = T.find(k);
    FOR(i,cmd.size()){
        string now_Cmd = cmd[i];
        if(now_Cmd[0] == 'U'){
            X = stoi(now_Cmd.substr(2));
            while(X--){
                it = prev(it);
            }
        }
        else if(now_Cmd[0] == 'D'){
            X = stoi(now_Cmd.substr(2));
            while(X--){
                it = next(it);
            }
        }
        else if(now_Cmd[0] == 'C'){
            //cout<<"pivot : "<<pivot<<endl;
            S.push(*it);
            it = T.erase(it);
            if(it == T.end()) it=prev(it);
        }
        else{
            //cout<<"pivot : "<<pivot<<endl;
            //cout<<S.top().first<<" "<<S.top().second<<endl;
            T.insert(S.top());
            S.pop();
        }
        //cout<<*it<<endl;
        /*
        FOR(j,T.size()){
            cout<<T[j]<<" ";
        }
        cout<<endl;
        cout<<"now_pivot : "<<pivot<<endl;
        */
    }
}
string answer_Find(int n){
    string answer(n,'X');
    for(int i : T){
        answer[i] = 'O';
    }
    return answer;
}
string solution(int n, int k, vector<string> cmd) {
    table_Set(n);
    cmd_Ex(k,cmd);
    return answer_Find(n);
}


int main(){
    vector<string> cmd;
    cmd.push_back("D 2");
    cmd.push_back("C");
    cmd.push_back("U 3");
    cmd.push_back("C");
    cmd.push_back("D 4");
    cmd.push_back("C");
    cmd.push_back("U 2");
    cmd.push_back("Z");
    cmd.push_back("Z");
    cmd.push_back("U 1");
    cmd.push_back("C");
    solution(8,2,cmd);
}