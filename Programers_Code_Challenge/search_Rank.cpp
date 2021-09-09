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
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string temp;
    vector<int> info_DB[3][2][2][2]; // a b c d
    vector<int> quert_DB[3][2][2][2];
    int a,b,c,d;
    FOR(i,info.size()){
        if(info[i].find("cpp") != string::npos) a=0;
        else if(info[i].find("java") != string::npos) a=1;
        else if(info[i].find("python") != string::npos) a=2;
                
        if(info[i].find("backend") != string::npos) b=0;
        else if(info[i].find("frontend") != string::npos) b=1;
                
        if(info[i].find("junior") != string::npos) c=0;
        else if(info[i].find("senior") != string::npos) c=1;
                
        if(info[i].find("chicken") != string::npos) d=0;
        else if(info[i].find("pizza") != string::npos) d=1;
        FOR(j,info[i].size()){
            if(48 <= info[i][j] && info[i][j]<=57){
                info[i].erase(info[i].begin(), info[i].begin()+j);
                int v = stoi(info[i]);
                //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" :"<<v<<endl;
                info_DB[a][b][c][d].push_back(v);
                break;
            }
        }
    }
    int as, ae, bs,be, cs, ce, ds, de;
    
    FOR(i,query.size()){
        
        if(query[i].find("cpp") != string::npos) {as = 0; ae =0;}
        else if(query[i].find("java") != string::npos) {as = 1; ae =1;}
        else if(query[i].find("python") != string::npos) {as = 2; ae =2;}
        else {as = 0; ae =2;}
                // 밑에 다 else 집어넣기
        if(query[i].find("backend") != string::npos) {bs = 0; be =0;}
        else if(query[i].find("frontend") != string::npos) {bs = 1; be = 1;}
        else {bs=0; be=1;}
        
        if(query[i].find("junior") != string::npos) {cs = 0; ce = 0;}
        else if(query[i].find("senior") != string::npos) {cs = 1; ce = 1;}
        else {cs = 0; ce = 1;}
                
        if(query[i].find("chicken") != string::npos) {ds = 0; de = 0;}
        else if(query[i].find("pizza") != string::npos) {ds = 1; de = 1;}
        else {ds = 0; de = 1;}
        
        int value = 0;
        
        FOR(j,query[i].size()){
            if(48 <= query[i][j] && query[i][j]<=57){
                query[i].erase(query[i].begin(), query[i].begin()+j);
                int v = stoi(query[i]);
                value = v;
                break;
            }
        }
        //cout<<value<<endl;
        int cnt = 0;
        //cout<<as<<" "<<ae<<" "<<bs<<" "<<be<<" "<<cs<<" "<<ce<<" "<<ds<<" "<<de<<endl;
        for(int q = as;q<=ae;q++){
            for(int w =bs; w<=be;w++){
                for(int o = cs;o<=ce;o++){
                    for(int p = ds;p<=de;p++){
                        //cout<<q<<" "<<w<<" "<<o<<" "<<p<<endl;
                        for(auto elem :info_DB[q][w][o][p]){
                            //cout<<"elem : "<<elem<<endl;
                            if(elem>=value) cnt++;
                        }
                    }
                }
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}