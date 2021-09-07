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
#define MAX 1000000 + 1
#define DIV 1000000009
#define DOWN 1
#define RIGHT 2
#define endl "\n"
#define has(a) (building.find(temp_Build[(a)])!=building.end())
using namespace std;
typedef long long ll;
void buffer_except(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int N;
vector<vector<int>> board;

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,-1,1};

struct block{   // 구조체를 움직이며 문제를 품
                // 또한 구조체 내 함수 생성하여 연속되게 구성
    int x1, y1, x2, y2;
    block(int x1,int y1,int x2,int y2):x1(x1),y1(y1),x2(x2),y2(y2){}
    
    bool is_Vaild(){ // 유효성 확인
        return x1>=0 && y1>=0 && x2>=0 && y2>=0 && x1<N && y1<N && x2<N && y2<N && !board[y1][x1] && !board[y2][x2];
    }
    
    block move(int d){ // 움직인 block 그대로 return
        return block(x1+dx[d],y1+dy[d],x2+dx[d],y2+dy[d]);
    }
    
    pair<block,block> rotate(int d){ // 가능한 block이 두개씩이므로 pair로 return
                                        // 여기서 특수한 조건 => 어떠한 방향으로 평행 이동할 수 있는 로봇은
                                        // 한 축을 기준으로(총 두 축) 그 방향으로 회전할 수 있다.
                                        // 그래서 move된 block => is_Vaild == true면 rotate 가능
        return {block(x1,y1,x1+dx[d],y1+dy[d]),block(x2,y2,x2+dx[d],y2+dy[d])};
    }
    
    bool isFinished(){ // 끝난지 확인
        return y1==N-1&&x1==N-1 || y2==N-1&&x2==N-1;
    }
};

bool operator < (block a, block b){ // 연산자 확장 위해 => 오버라이딩
    return tie(a.x1, a.y1, a.x2, a.y2) < tie(b.x1, b.y1, b.x2, b.y2);
}

bool operator == (block a, block b){ // 연산자 확장 위해 => 오버라이딩
     return tie(a.x1, a.y1, a.x2, a.y2)==tie(b.x1, b.y1, b.x2, b.y2)
    || tie(a.x1, a.y1, a.x2, a.y2)==tie(b.x2, b.y2, b.x1, b.y1);
}

map<block, int> dist;
queue<block> Q;

vector<block> get_Move(block& b){
    vector<block> blo;
    FOR(i,4){
        blo.push_back(b.move(i));
    }
    return blo;
}

vector<block> get_Rotate(block& b){
    vector<block> blo;
    FOR(i,4){
        if(b.move(i).is_Vaild()){
            pair<block,block> dBlo = b.rotate(i);
            blo.push_back(dBlo.first);
            blo.push_back(dBlo.second);
        }
    }
    return blo;
}

int BFS(){
    Q.push(block(0,0,1,0));
    dist[block(0,0,1,0)] = 0;
    while(!Q.empty()){
        block cur = Q.front();
        Q.pop();
        
        int cur_Dist = dist[cur];
        if(cur.isFinished()) return cur_Dist;
        vector<block> next[2] = {get_Move(cur), get_Rotate(cur)}; // block구조체를 리턴하는 함수를
                                                        // block구조체를 받는 벡터 2차 배열에 받는다.
                                                        // 0 => 가능 move, 1=> 가능 rotate
                        
        FOR(i,2){
            for(block bb:next[i]){
                if(dist.find(bb) == dist.end() && bb.is_Vaild()){
                    dist[bb] = cur_Dist + 1;
                    Q.push(bb);
                }
            }
        }
    }
    return -1;
}
int solution(vector<vector<int>> b) {
    board = b;
    N = (int) board.size();
    int answer = BFS();
    return answer;
}