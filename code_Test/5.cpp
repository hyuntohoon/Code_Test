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
#define FOR2(i,n) for(int i=2;i<n;i++)
#define FORV(elem,V) for(auto elem : V)
#define MAX 1001
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
int map_number[MAX][MAX];
vector<vector<int>> solution(int rows, int columns) {
    vector<vector<int>> answer;
    int N = rows; // y
    int M = columns; // x
    int now_Number = 1;
    int x = 0;
    int y = 0;
    int zero = N*M;
    while(true){
        if(map_number[y][x]%2 == now_Number%2 && map_number[y][x] != 0){
            break;
        }
        if(map_number[y][x] == 0){
            zero--;
        }
        map_number[y][x] = now_Number;
        if(zero == 0){
            break;
        }
        if(now_Number % 2 == 1){
            x++;
            if(x>=M){
                x = 0;
            }
        }
        else{
            y++;
            if(y>=N){
                y = 0;
            }
        }
        now_Number++;
    }
    FOR(i,N){
        vector<int> V;
        FOR(j,M){
            V.push_back(map_number[i][j]);
        }
        answer.push_back(V);
    }
    
    return answer;
}