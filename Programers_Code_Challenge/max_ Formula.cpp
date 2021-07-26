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

string expression = "50*6-3*2";
string temp = "";
vector<ll> number;
vector<ll> temp_number;
vector<char> oper;
vector<char> temp_oper;

void calculate(char c, int n){
   
    ll temp = temp_number[n];

    if(c == '*'){
        temp *= temp_number[n+1];
    }
    
    else if(c == '+'){
        temp += temp_number[n+1];
    }
    else if(c == '-'){
        temp -= temp_number[n+1];
    }

    temp_number[n] = temp;
    temp_number.erase(temp_number.begin() + n + 1);
    temp_oper.erase(temp_oper.begin() + n);
}
int main(){
    ll answer = 0;
    for(int i = 0;i<expression.size();i++){
        if(expression[i] == '-' || expression[i] == '*' || expression[i] =='+'){
            number.push_back(stoll(temp));
            temp = "";
            oper.push_back(expression[i]);
        }
        else{
            temp+=expression[i];
        }
    }
    number.push_back(stoll(temp));
    
    vector<int> Y; // 0 => *, 1 => +, 2 => -
    Y.push_back(0);
    Y.push_back(1);
    Y.push_back(2);
    //cout<<"size : "<<temp_oper.size()<<endl;
    do{
        temp_number = number;
        temp_oper = oper;
        //cout<<"size : "<<temp_oper.size()<<endl;
        for(auto elem : Y){
            
            if(elem == 0){
                for(int i = 0; i < temp_oper.size(); i++){
                    if(temp_oper[i] == '*'){
                        calculate(temp_oper[i], i);
                        i--;
                    }
                }
            }
            else if(elem == 1){
                for(int i = 0; i < temp_oper.size(); i++){
                    if(temp_oper[i] == '+'){
                        calculate(temp_oper[i], i);
                        i--;
                    }
                }
            }
            else if(elem == 2){
                for(int i = 0; i < temp_oper.size(); i++){
                    if(temp_oper[i] == '-'){
                        calculate(temp_oper[i], i);
                        i--;
                    }
                }
            }
        }
        //cout<<endl;
        for(auto elem2 : temp_number){
            answer = max(abs(elem2), answer);
        }
        
    }
   while(next_permutation(Y.begin(), Y.end()));
    cout<<answer;
}
