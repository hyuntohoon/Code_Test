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
#define MAX 300 + 1
#define DIV 1000000009
#define RED 1
#define BLUE 0
#define endl "\n"
using namespace std;
typedef long long ll;

vector<int> Segment_Tree;
int Arr[5] = {1,2,3,4,5};
int Make_Segment_Tree(int Node, int Start, int End){
    if(Start == End) return Segment_Tree[Node] = Arr[Start];
    
    int mid = (Start + End) / 2;
    int Left_Node = Make_Segment_Tree(Node*2, Start, mid);
    int Right_Node = Make_Segment_Tree(Node*2+1, mid+1, End);
    Segment_Tree[Node] = Left_Node + Right_Node;
    
    return Segment_Tree[Node];
}

int sum(int Node, int Start, int End, int Left, int Right){
    if(Left>End || Right < Start ) return 0;// 구간이 겹치지 않은 경우
    if(Left<=Start && Right>=End) return Segment_Tree[Node];// 구간이 완전히 겹친 경우
    // 구간이 선택적으로 겹친 경우
    int Mid = (Start + End)/2;
    int Left_Result = sum(Node*2, Start, Mid, Left, Right);
    int Right_Result = sum(Node*2+1, Mid+1, End, Left, Right);
    
    
    
    return Left_Result+Right_Result;
}

int main(){
    int N = 5;
    int Tree_H = ceil(log2(N));
    int Tree_S = (1<<(Tree_H + 1));
    Segment_Tree.resize(Tree_S);
    Make_Segment_Tree(1,0,4);
    cout<<sum(1,1,5,1,5)<<endl;
}
