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
#define FORV(elem,V) for(auto elem : V)
#define MAX 1010
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
struct TRIE{ // 구조체 TRIE 생성
    //bool Finish;
    TRIE *Node[26]; // 26개의 노드 생성, 각 노드마다 26개의 길이 있기 때문에
    TRIE(){ // 생성자 초기화, 만들 때 마다 끝인 지점이 있는지 없는지 확인
        //Finish = false; // 시작은 0
        FOR(i,26){
            Node[i] = 0; // 모든 노드 초기화
        }
    }
    void Insert(const char *Str)
    {
        if (*Str == '\0')
        {
            //Finish = true;
            return;
        }

        int Cur = *Str - 'a';
        if (!Node[Cur]) Node[Cur] = new TRIE;
        Node[Cur]->Insert(Str + 1);
    }
    bool Find(const char *Str)
    {
        if (*Str == '\0')
        {
            //if (Finish == true) return true;
            return true;
        }
        int Cur = *Str - 'a';
        if (!Node[Cur]) return false;
        return Node[Cur]->Find(Str + 1);
    }

};



int main(){
    int N, M;
char temp[501];
    buffer_except();
    scanf("%d%d",&N,&M);
    TRIE Root;
    vector<string> S;
    FOR(i,N){
        scanf("%s",&temp);
        Root.Insert(temp);
    }
    int cnt = 0;
    FOR(j,M){
        scanf("%s",&temp);
        cnt+=Root.Find(temp);
    }
    cout<<cnt<<endl;
}