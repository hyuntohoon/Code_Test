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

bool state_Check(int x, int y, vector<vector<int>> key, vector<vector<int>> lock){
    int lock_Input = 0;
    FOR(i,lock.size()){
        FOR(j,lock.size()){
            if(lock[i][j] == 0) lock_Input++;
        }
    }
    int key_Input = 0;
    FOR(i,key.size()){
        FOR(j,key.size()){
            if(i+y>=lock.size() || j+x >= lock.size()) continue;
            if(key[i][j] == 1 && lock[i+y][j+x] == 1) break;
            if(key[i][j] == 0 && lock[i+y][j+x] == 0) break;
            if(key[i][j] == 1 && lock[i+y][j+x] == 0) key_Input++;
        }
    }
    if(key_Input == lock_Input) return true;
    return false;
}

bool rotate(int x, int y, vector<vector<int>> key, vector<vector<int>> lock){
    FOR(o,4){
        vector<vector<int>> temp_Key = key;
        int temp_x = (int)key.size()-1;
        int temp_y = 0;
        FOR(i,key.size()){
            temp_y = 0;
            FOR(j,key.size()){
                temp_Key[temp_y][temp_x] = key[i][j];
                temp_y++;
            }
            temp_x--;
        }
        key = temp_Key;
        if(state_Check(x, y, key, lock)) return true;
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    for(int i = ((int)key.size()-1) * -1; i<(int)lock.size()-1;i++){
        for(int j = ((int)key.size()-1) * -1;j<(int)lock.size()-1;j++){
            if(rotate(j, i, key, lock)) return true;
        }
    }
    return false;
}