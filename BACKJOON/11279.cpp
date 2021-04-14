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
#define MAX 1000000 + 1
#define DIV 1000000009
#define RED 1
#define BLUE 0
#define endl "\n"
using namespace std;
typedef long long ll;

void buffer_except(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
bool desc(int a, int b){ return a < b; }


int main(){
    buffer_except();
    priority_queue<int> Q;

    int N;
    cin>>N;
    FOR(i,N){
        int temp;
        cin>>temp;
        if(temp == 0){
            if(Q.size() == 0){
                cout<<"0"<<endl;
            }
            else{
               
                cout<<Q.top()<<endl;
                Q.pop();
            }
        }
        else{
            Q.push(temp);
        }
    }
}

