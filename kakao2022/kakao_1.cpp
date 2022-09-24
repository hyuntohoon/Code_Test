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
#include<sstream>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
#define endl "\n"
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
map<string, ll> M;

ll change_Time(string time){
    vector<int> answer;
    FOR(i,time.size()){
            if(time[i] == '.') time[i] = ' ';
    }
        ll num  = 0;
        ll num_Time = 0;
        stringstream stream;
        stream.str(time);
        int check = 0;
        while(stream >> num){
            if(check == 0){
                num_Time+=num*10000;
            }
            if(check ==1){
                num_Time+=num*100;
            }
            if(check == 2){
                num_Time+=num;
            }
            check++;
        }
    return num_Time;
}

void change_Terms(char terms, ll month){
    //cout<<terms<<" "<<month<<endl;
    string T = "";
    T+=terms;
    ll num_Month = month * 100;
    //cout<<"oopp:"<<num_Month<<endl;
    M[T] = num_Month;
}
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    ll now_Time = change_Time(today);
    //cout<<now_Time<<endl;
    FOR(i,terms.size()){
        string T = terms[i];
        char a = T[0]; 
        ll num  = 0;
        string month = "";

        
        if(T.size() == 3){
            char aa = T[2];
            month+=aa;
        }
        else if(T.size() == 4){
            char aa = T[2];
            month+=aa;
            aa=T[3];
            month+=aa;
        }
        else{
            char aa = T[2];
            month+=aa;
            aa=T[3];
            month+=aa;
            aa=T[4];
            month+=aa;
        }
        num =stoll(month);
        change_Terms(a,num);
    }
    FOR(i,privacies.size()){
        char a = privacies[i][11];
        ll P = change_Time(privacies[i]);
        string A ="";
        A+=a;
        P+=M[A];
        ll P_Month = P%10000;
        P-=P_Month;
        P_Month += M[A];
        if(P_Month>1300){
            ll P_Year;
            if(P_Month%1200 == 0){
                P_Year = (P_Month/1200)-1;
                P_Month = (P_Month%100)+1200;
            }
            else{
                P_Year = P_Month/1200;
                P_Month = P_Month%1200;
            }
            P+=P_Year;
            P+=P_Month;
        }

        if(now_Time>=P){
            answer.push_back(i+1);
        }
    }

    return answer;
}

int main(){
    string today ="2021.11.02";
    vector<string> terms, privacies;
    terms.push_back("B 12");
    privacies.push_back("2021.05.02 B");
    solution(today,terms,privacies);
}