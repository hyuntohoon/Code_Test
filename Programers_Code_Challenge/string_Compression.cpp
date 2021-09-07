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
int end_Pivot = 0;
int compression(int leng, int start, string s){ // 압축
    //start ~ start+leng까지 끊기
    //for문에서 i+leng만큼 움직이며 비교
    string separate_s = "";
    end_Pivot = start+leng;
    if(start + leng > s.size()){
        return 0;
    }
    for(int i=start;i<start+leng;i++){
        separate_s+=s[i];
    }
    int cnt = 0;
    //cout<<"now sepa : "<<separate_s<<endl;
    for(int i=start+leng;i<s.size();i+=leng){
        //cout<<"i: "<<i<<endl;
        bool F = 1;
        FOR(j,leng){
            //cout<<separate_s[j]<<" "<<s[i+j]<<endl;
            if(separate_s[j] != s[i+j]){ // 틀리면 틀렸다, break
                F = 0;
                break;
            }
        }
        //cout<<"--------"<<endl;
        if(F == 1){
            cnt++;
            //cout<<cnt<<endl;
        }
        else if(F == 0){
            break;
        }
    }
    int compression_leng = 0;
    //cout<<cnt+1<<endl;
    if(cnt != 0){
        cnt++;
        if(cnt>9 && cnt<100){
            compression_leng = (cnt) * leng - leng - 2;
        }
        else if(cnt>99 && cnt<1000){
            compression_leng = (cnt) * leng - leng - 3;
        }
        else if(cnt == 1000){
            compression_leng = (cnt) * leng - leng - 4;
        }
        else if(cnt<10){
            if(leng == 1){
                compression_leng = (cnt) * leng - leng - 1;
            }
            else{
                compression_leng = (cnt) * leng - leng - 1;
            }
           // cout<<compression_leng<<endl;
        }
        
    }
   // cout<<"compression_leng : "<<compression_leng<<endl;
    end_Pivot = start+leng*(cnt);
    return compression_leng;
}
int solution(string s){
    //string s = "xxxxxxxxxxyyy";
    int leng = (int)s.size()/2;
    int answer = (int)s.size();
    for(int i = 1;i<=leng;i++){ // 압축길이 조절
        int origin_leng = (int)s.size();
        //FOR(j,s.size()){ // 시작 위치 조절
        for(int j =0;j<s.size();j+=i){
                        // 이 시작 위치는 길이에 의해 변동될 수 있으나
                        // for문에서 조절한다면 다른 경우에서 문제가 생길 수 있어서
                        // for문 자체에서 조절하지 않고, 함수 내에서 기저사례를 찾아 조절한다.
           // cout<<"start : "<<i<<" "<<j<<endl;
            int compression_leng = compression(i, j, s);
           // cout<<"COM : "<<compression_leng<<endl;
            if(compression_leng != 0){
              //  cout<<"PPP"<<endl;
                j = end_Pivot-i;
              //  cout<<"j : "<<j<<endl;
            }
           // cout<<"origin : "<<origin_leng<<" compression_leng : "<<compression_leng<<endl;
            origin_leng -= compression_leng;
            answer = min(answer, origin_leng);// 최소 길이와 비교
            if(j>s.size()){
                break;
            }
        }
    }
   // cout<<answer<<endl;
    return answer;
}
