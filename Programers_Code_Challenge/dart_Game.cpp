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
bool sang_Check(char a){
    if(a == '*' || a == '#'){
       return 1;
    }
    return 0;
}
int number_Check(char a, char b){
    string T ="";
    if(a == '1' && b == '0'){ // 10
        return 4;
    }
    if(48<=(int)a && (int)a<58){
        return 1;
    }
    else if(a == '*'){
        return 2;
     }
    else if(a == '#'){
        return 3;
    }
    else{
        return 0;
    }
}
int section_check(char a){
    if(a == 'S'){
        return 1;
    }
    else if(a == 'D'){
        return 2;
    }
    else{
        return 3;
    }
}
int main(){
    string dartResult = "10S10S10S";
    int dart_Value[3] = {0,0,0};
    int now_Dart =0; // now
    for(int i=0;i<dartResult.size();i++){
        char now_Dart_Value =dartResult[i];
        int F = number_Check(now_Dart_Value, dartResult[i+1]);
        cout<<now_Dart_Value<<" "<<F<<endl;
        if(F == 0){ //char
            int section = section_check(now_Dart_Value);
            dart_Value[now_Dart] = pow(dart_Value[now_Dart],section);
            now_Dart++;
        }
        else if(F == 1){ // num
            dart_Value[now_Dart] = (int)now_Dart_Value-48;
        }
        else if(F == 2){ // *
            if(now_Dart-2 < 0){
                dart_Value[now_Dart-1] *=2;
            }
            else{
                dart_Value[now_Dart-2] *=2;
                dart_Value[now_Dart-1] *=2;
            }
        }
        else if(F == 3){ // #
            dart_Value[now_Dart-1] *=-1;
        }
        else if(F==4){ //
            dart_Value[now_Dart] = 10;
            i++;
        }
    }
    int answer = 0;
    FOR(i,3){
        cout<<dart_Value[i]<<" ";
        answer+=dart_Value[i];
    }
    cout<<endl<<answer<<endl;
}
