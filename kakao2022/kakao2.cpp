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

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int end_Point = deliveries.size()-1;
    while(true){
        int M = -1;
        int now_C = cap;
        bool check =0;
        bool CC = 0;
        for(int i = end_Point;i>-1;i--){
            if(deliveries[i] != 0){
                //cout<<i<<" "<<deliveries[i]<<endl;
                M = max(M,i);
                check = 1;
                CC = 1;
            }
            if(pickups[i] != 0){
                //cout<<i<<" "<<pickups[i]<<endl;
                M = max(M,i);
                check = 1;
                if(CC == 1) break;
            }
        }
        if(check ==0){
            break;
        }
        //cout<<M<<endl;
        int now_P = cap;
        bool C = 0;
        for(int i = end_Point;i>-1;i--){
            //cout<<"del: "<<deliveries[i]<<" "<<now_C<<endl;
            if(deliveries[i] != 0){ //배달끝
                if(deliveries[i] > now_C){
                    deliveries[i]-=now_C;
                    now_C = 0;
                    C=1;
                    end_Point = max(end_Point,i);
                }
                else{ // 더 배달해야하는경우
                    now_C-= deliveries[i];
                    deliveries[i] = 0;
                }
            }
            if(pickups[i] > now_P){
                    pickups[i]-=now_P;
                    now_P = 0;
                    end_Point = max(end_Point,i);                    
                    if(C==1) break;
                }
                else{ // 더 해야수거하는경우
                    now_P-= pickups[i];
                    pickups[i] = 0;
                }
        }
        //cout<<M<<endl;
        answer+=((M+1)*2);
    }
    //cout<<answer<<endl;
    return answer;
}

int main(){
    vector<int> deliveries;
    vector<int> pickups;
    deliveries.push_back(1);
    deliveries.push_back(0);
    deliveries.push_back(3);
    deliveries.push_back(1);
    deliveries.push_back(2);
    pickups.push_back(0);
    pickups.push_back(3);
    pickups.push_back(0);
    pickups.push_back(4);
    pickups.push_back(0);
    solution(4,5,deliveries,pickups);
}