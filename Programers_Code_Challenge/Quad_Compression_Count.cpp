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
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 100001
#define DIV 1000000009
#define RED 1
#define BLUE 0
#define endl "\n"
typedef long long ll;
using namespace std;
vector <vector<int>> V;

void go(int n, int x, int y, vector<int> &answer){
    bool Z, O;
    Z = O = true;
    
    for(int i = y; i < y + n; i++){
        for(int j = x; j < x + n; j++){
            if(V[i][j] == 1) Z = false;
            if(V[i][j] == 0) O = false;
        }
    }
    
    if(Z == 1){
        answer[0]++;
        return;
    }
    if(O == 1){
        answer[1]++;
        return;
    }
    go(n/2, x, y, answer);
    go(n/2, x + (n/2), y, answer);
    go(n/2, x, y + (n/2), answer);
    go(n/2, x + (n/2), y + (n/2), answer);
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    V = arr;
    go(arr.size(), 0, 0, answer);
    return answer;
}