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
#define MAX 1001
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

string solution(double time, vector<vector<string>> plans) {
    string answer = "";
    for(auto elem : plans){
        string where = elem[0];
        string start = elem[1];
        string end = elem[2];
        double T = time;
        double start_H;
        double end_H;
        if(start.length() == 3){
            if(start[1] == 'A'){
                start_H = stoi(start.substr(0,1));
            }
            else{ // P
                start_H = stoi(start.substr(0,1));
                start_H+=12;
            }
        }
        else{ // 4
            if(start[2] == 'A'){
                start_H = stoi(start.substr(0,2));
            }
            else{ // P
                start_H = stoi(start.substr(0,2));
                start_H+=12;
            }
        }
        if(end.length() == 3){
            if(end[1] == 'A'){
                end_H = stoi(end.substr(0,1));
            }
            else{ // P
                end_H = stoi(end.substr(0,1));
                end_H+=12;
            }
        }
        else{ // 4
            if(end[2] == 'A'){
                end_H = stoi(end.substr(0,2));
            }
            else{ // P
                end_H = stoi(end.substr(0,2));
                end_H+=12;
            }
        }
        cout<<start_H<<" "<<end_H<<endl;
        if(18-start_H>T){
            continue;
        }
        T-=18-start_H;
        cout<<T<<endl;
        if(end_H-13>T){
            continue;
        }
        cout<<end_H-13<<endl;
        answer = where;
        cout<<answer<<endl;
    }
    return answer;
}

int main(){
    int i = 1;
    cout<<(i>1.1)<<endl;
    solution(3, {{"홍콩", "11PM", "9AM"},{"엘에이", "3PM", "1PM"}});
}
