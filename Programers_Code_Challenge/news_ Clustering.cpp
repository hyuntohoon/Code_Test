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

using namespace std;

bool check(char a){
    if('A' <= a && a <= 'Z'){
        return 1;
    }
    if('a' <= a && a <= 'z'){
        return 1;
    }
    return 0;
}

int solution(string str1, string str2) {
     map<string,int> A;
    map<string,int> B;
    float uni = 0;
    for(int i =0;i<str1.size()-1;i++){
        if(!check(str1[i]) || !check(str1[i+1])) continue;
        uni++;
        string temp = "";
        temp+=tolower(str1[i]);
        temp+=tolower(str1[i+1]);
        if(A.find(temp) != A.end()){
            A[temp]++;
        }
        else{
            A.insert(make_pair(temp, 1));
        }
    }
    for(int i =0;i<str2.size()-1;i++){
        if(!check(str2[i]) || !check(str2[i+1])) continue;
        uni++;
        string temp = "";
        temp+=tolower(str2[i]);
        temp+=tolower(str2[i+1]);
        if(B.find(temp) != B.end()){
            B[temp]++;
        }
        else{
            B.insert(make_pair(temp, 1));
        }
    }
    float intersection = 0;
    for(auto elem : A){
        int temp = 0;
        if(B.find(elem.first) != B.end()){
            temp = min(B[elem.first], elem.second);
            intersection+=temp;
        }
    }
    uni-=intersection;
    int answer = (int)((intersection/uni)*65536);
    if(intersection == 0 && uni == 0){
        return 65536;
    }
    else if (intersection == 0 || uni == 0){
        return 0;
    }
    return answer;
}