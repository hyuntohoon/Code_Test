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
using namespace std;

void findOne(string S){
    if(S.find("110") < 10000000){
        S.erase(S.find("110"), 3);
    }
}
int findZero(string S){
    for(int i = (int)S.length()-1;i>-1;i--){
        //cout<<i<<" "<<S[i]<<endl;
        
        if(S[i] == '0'){
            //cout<<"find"<<endl;
           // cout<<i+1<<endl;
            return i+1;
        }
    }
    return -1;
}
vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(auto elem : s){
        int count = 0;
        string tempElem = "";
        while(true){
            if(elem.find("110") > 10000000){
                break;
            }
           // cout<<elem.find("110")<<" ";
            elem.erase(elem.find("110"), 3);
            tempElem+="110";
            //cout<<"elem"<<elem<<endl;
            count++;
        }
        int countTemp = count;

            //cout<<"L"<<elem.length()<<endl;
            int B = findZero(elem) ;
            
            //tempElem+=elem;
            if(B != -1){ // find zero
                elem.insert(B, tempElem);
                //cout<<elem<<endl;
            }
            else{
                tempElem+=elem;
                elem = tempElem;
            }
            cout<<elem<<endl;
        answer.push_back(elem);
    }
    return answer;
    // 제일 작은 수 만들기
    
}