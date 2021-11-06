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

string solution(vector<string> log) {
    string answer = "";
    int sum_M = 0;
    for(int i = 0;i<log.size();i++){
        string temp_H ="";
        string temp_M ="";
        temp_H += log[i][0];
        temp_H += log[i][1];
        temp_M += log[i][3];
        temp_M += log[i][4];
        int start_H = stoi(temp_H);
        int start_M = stoi(temp_M);
        /*
        cout<<temp_H<<" "<<temp_M<<endl;
         */
        //cout<<start_H<<" "<<start_M<<endl;
        
        temp_H.clear();
        temp_M.clear();
        temp_H += log[i+1][0];
        temp_H += log[i+1][1];
        temp_M += log[i+1][3];
        temp_M += log[i+1][4];
        //cout<<temp_H<<" "<<temp_M<<endl;
        int stop_H = stoi(temp_H);
        int stop_M = stoi(temp_M);

        //cout<<stop_H<<" "<<stop_M<<endl;
        int result_H = stop_H - start_H;
        int result_M = stop_M - start_M;
        result_H*=60;
        int result = result_H + result_M;
        if(result > 105){
            result = 105;
        }
        if(result < 5){
            result = 0;
            result_M = 0;
        }
        cout<<result<<endl;
        sum_M+=result;
        /*
        if(result >= 60){
            result -= 60;
            result_H = 1;
            result_M = result;
        }*/
        
        /*
        temp_H = to_string(result_H);
        temp_M = to_string(result_M);
        
        if(temp_H.size() == 1){
            temp_H+="0";
            reverse(temp_H.begin(), temp_H.end());
        }
        if(temp_M.size() == 1){
            temp_M+="0";
            reverse(temp_M.begin(), temp_M.end());
        }*/
        i++;
    }
    string temp_H = to_string(sum_M/60);
    string temp_M = to_string(sum_M%60);
    if(temp_H.size() == 1){
        temp_H+="0";
        reverse(temp_H.begin(), temp_H.end());
    }
    if(temp_M.size() == 1){
        temp_M+="0";
        reverse(temp_M.begin(), temp_M.end());
    }
    answer+=temp_H;
    answer+=":";
    answer+=temp_M;
    cout<<answer<<endl;
    return answer;
}