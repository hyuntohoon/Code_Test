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

int main(){
    int n = 6;
    vector<int> arr1 = {46, 33, 33 ,22, 31, 50};
    vector<int> arr2 = {27 ,56, 19, 14, 14, 10};
    vector<int> bir1;
    vector<int> bir2;
    for(int i =n-1;i>=0;i--){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int j =0;j<arr1.size();j++){
        for(int i = n-1;i>=0;i--){
            int now_B = pow(2,i);
            cout<<"compare : "<<"arr : "<<arr1[j]<<" B : "<<now_B<<endl;
            //제일 큰 수 보다 큰경우
            if(arr1[j]<now_B){
                bir1.push_back(0);
            }
            else{
                bir1.push_back(1);
                arr1[j]-=now_B;
            }
        }
    }
    for(int j =0;j<arr2.size();j++){
        for(int i = n-1;i>=0;i--){
            int now_B = pow(2,i);
            if(arr2[j]<now_B){
                bir2.push_back(0);
            }
            else{
                bir2.push_back(1);
                arr2[j]-=now_B;
            }
        }
    }
    int i = 0;
    for(auto elem : bir1){
        if(i==5){
            cout<<endl;
            i=0;
        }
        cout<<elem<<" ";
        i++;
    }
    cout<<endl<<endl;
    i=0;
    for(auto elem : bir2){
        if(i==5){
            cout<<endl;
            i=0;
        }
        cout<<elem<<" ";
        i++;
    }
    cout<<endl;
    vector<string> answer;
    string temp="";
    int j =0;
    FOR(i,pow(n,2)+1){
        if(j==n){
            j=0;
            answer.push_back(temp);
            temp = "";
        }
        if(bir1[i] == 1 || bir2[i] == 1){
            temp+='#';
        }
        else{
            temp+=' ';
        }
        j++;
    }
    for(auto elem : answer){
        cout<<elem<<endl;
    }
    cout<<endl;
}
