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

struct status{
    int x;
    int y;
    int rowColumn;
    int value;
    
    status(int x, int y, int rowColumn, int value):x(x),y(y),rowColumn(rowColumn),value(value){}
};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool range_check(int x, int y, int N){
    if(x>=0 && y >=0 && x<N && y<N){
        return 1;
    }
    return 0;
}
queue<status> race_Track;
int main(){
    vector<vector<int>> board;
    vector<vector<int>> value_Map;
    value_Map.resize(board.size(), vector<int>(board.size(),987654321));
    race_Track.push(status(0,0,-1,0));
    int answer;
    while(!race_Track.empty()){
        //cout<<"hi"<<endl;
        int x = race_Track.front().x;
        int y = race_Track.front().y;
        int value = race_Track.front().value;
        int rowColumn = race_Track.front().rowColumn;
        race_Track.pop();
        
        FOR(i,4){ // i == 0,1 => 0 | i == 3,4 => 1
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(range_check(nx, ny, board.size())){
                if(board[ny][nx] == 0){
                    int nvalue;
                    if (rowColumn == -1 || rowColumn == i){
                        nvalue = value + 100;
                    }
                    else {
                        nvalue = value + 600;
                    }
                    if(value_Map[ny][nx]>=nvalue){
                        value_Map[ny][nx] = nvalue;
                        race_Track.push(status(nx,ny,i,nvalue));
                    }
                }
            }
        }
    }
    answer = value_Map[board.size()-1][board.size()-1];
    return answer;
}
