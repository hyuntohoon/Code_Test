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

int D[7];
ll a;
vector<pair<int,ll> > V;
void discount(int cnt, int end,vector<vector<int> > users, vector<int> emoticons){
    if(cnt ==end){
        a++;
        ll price_Sum = 0;
        int plus_Cnt = 0;
        FOR(j,users.size()){
            ll sum = 0;
            FOR(i,end){
                //cout<<(100-D[i])*emoticons[i]/100<<" ";
                //cout<<users[j][0]<<" "<<D[i]<<endl;
                if(users[j][0]<=D[i]){
                    //cout<<D[0]<<endl;
                    //cout<<users[j][0]<<" "<<D[i]<<endl;
                    ll oopp = (100-D[i])*emoticons[i]/100;
                    sum+=oopp; // 구매 이모티콘
                }
                //cout<<"sum"<<sum<<endl;
            }
            //cout<<endl;
            //cout<<sum;
            //cout<<"find : "<<sum<<" "<<users[j][1]<<endl;
            if(sum<users[j][1]){ // 사는 경우
                price_Sum+=sum;
            }
            else if(sum>=users[j][1]){ // 안 사는 경우
                plus_Cnt++;
            }
        }
        //cout<<plus_Cnt<<" "<<price_Sum<<endl;
        V.push_back(make_pair(plus_Cnt, price_Sum));
        return;
    }
    for(int i = 0;i<4;i++){
        if(i==0){
            D[cnt] = 10;
        }
        else if(i==1){
            D[cnt] = 20;
        }
        else if(i==2){
            D[cnt] = 30;
        }
        else{
            D[cnt] = 40;
        }
        discount(cnt+1,end, users, emoticons);
    }
}

vector<int> solution(vector<vector<int> > users, vector<int> emoticons) {
    vector<int> answer;
    int end = emoticons.size();
    discount(0, end, users, emoticons);
    sort(V.begin(),V.end());
    int b = V.size()-1;
    answer.push_back(V[b].first);
    answer.push_back(V[b].second);
    return answer;
}


int main(){
    vector<int> pp;
    pp.push_back(40);
    pp.push_back(10000);
    vector<int> aa;
    aa.push_back(25);
    aa.push_back(10000);
    vector<vector<int> > users;
    users.push_back(pp);
    users.push_back(aa);
    vector<int> emoticons;
    emoticons.push_back(7000);
    emoticons.push_back(9000);
    solution(users, emoticons);
}