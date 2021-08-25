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
string make_Correct(string u, string v){
    int F = 0;
    bool correct = 1;
    FOR(i,u.size()){
        if(u[i] == '('){
            F++;
        }
        else{
            F--;
        }
        //cout<<"F : "<<F<<endl;
        if(F < 0){
            correct = 0;
        }
    }
    if(F== 0 && correct == 1){
        cout<<"cout : "<<u+v<<endl;
        return u+v;
    }
    string temp_v = "(";
    temp_v+=v;
    temp_v+=")";
    //cout<<"correct_v : "<<temp_v<<endl;
    u.erase(u.begin());
    u.erase(u.end()-1);
    FOR(i,u.size()){
        if(u[i] == '('){
            u[i] = ')';
        }
        else{
            u[i] = '(';
        }
    }
    temp_v+=u;
    //cout<<"change_u : "<<u<<endl;
    cout<<"correct_u : "<<temp_v<<endl;
    return temp_v;
}
string separate_String(string w){
    cout<<w<<endl;
    int F = 0; //flag
    bool correct = 1;
    string u;
    string v;
    FOR(i,w.size()){
        if(w[i] == '('){
            F++;
        }
        else{
            F--;
        }
        //cout<<"F : "<<F<<endl;
        if(F < 0){
            correct = 0;
        }
        //cout<<"uncorrect : "<<uncorrect<<endl;
        if(F == 0){
            u = w.substr(0,i+1);
            cout<<"u : "<<u<<endl;
            v = w.substr(i+1,w.size());
            cout<<"v : "<<v<<endl;
            break;
        }
    }
    //cout<<endl;
    //cout<<uncorrect<<endl;
    if(v == ""){
        //cout<<"v_test"<<endl;
    }
    if(v == "" && correct == 1){ // 올바른지까지 확인
        //cout<<"end_separate"<<endl;
        return u;
    }
    v = separate_String(v);
    //cout<<"correct_v : "<<v<<endl;
    w.clear();
    w = "";
    cout<<u<<" + "<<v<<endl;
    w += make_Correct(u, v);
    return w;
}
string solution(string p) {
    string answer = separate_String(p);
    return answer;
}