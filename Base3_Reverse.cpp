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
#include <cmath>
using namespace std;

int solution(int n) {
    int Q, R; // 몫, 나머지
    vector <int> V;
    Q = n;
    while(true){
        if(Q == 0){
            break;
        }
           R = Q%3;
        Q = Q/3;
        V.push_back(R);
    }
    vector<int>::iterator iter;
    int L = V.size();
    int P =0;
    int sum=0;
    while(L--){
        iter = V.end()-1;
        int a = pow(3,P);
        sum+= a*(*iter);
        P++;
        V.pop_back();
    }
    int answer = 0;
    answer = sum;
    return answer;
}