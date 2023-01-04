#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include<stdio.h>
#include<fstream>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
using namespace std;

vector<vector<string> > places;
vector<int> answer;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool range_check(int x,int y,int N, int M){
    if(x>=0 && y>=0 &&x<N &&y<M){
        return 1;
    }
    return 0;
}


bool BFS(int y, int x, vector<string> R){
    queue <pair<pair<int, int>,int> > Q; // x,y,count
    vector <vector<bool> >V(5,vector<bool>(5,false));
    Q.push(make_pair(make_pair(x,y),0));
    V[y][x] = true;
    while(!Q.empty()){
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int count = Q.front().second;
        Q.pop();
        if(count == 2) continue;
        FOR(i,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(range_check(nx,ny,5,5) && (!V[ny][nx])){
                if(R[ny][nx] == 'O'){
                    Q.push(make_pair(make_pair(nx,ny),count+1));
                }
                else if(R[ny][nx] =='P'){
                    return false;
                }
            }
        }
    }
    return true;
}

int find_P(vector<string> R){
    vector <pair<int,int> > P;
    FOR(i,R.size()){
        FOR(j,R[i].size()){
            if(R[i][j] == 'P'){
                if(BFS(i,j, R) == 0){
                    return 0;
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string> > places) {
    FOR(i,places.size()){
        answer.push_back(find_P(places[i]));
    }
    return answer;
}