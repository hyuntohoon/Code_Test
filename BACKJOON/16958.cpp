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
int N,T;
int s,x,y;
int M;
int A,B;
int arr[1000+1][1000+1];
struct city{
    int s;
    int x;
    int y;
    city(int s, int x, int y):s(s),x(x),y(y){}
};
vector<city> C;

void swift(int A, int B){
    if(C[A].s == 1 && C[B].s == 1){
        arr[A][B] = min(arr[A][B], T);
    }
    cout<<arr[A][B]<<endl;
}
int main(){
    buffer_except();
    
    cin>>N>>T;
    FOR(i,N){
        cin>>s>>x>>y;
        C.push_back(city(s,x,y));
    }
    FOR(i,N){
        FOR(j,N){
            if(i==j) continue;
            int dis = abs(C[i].x - C[j].x) + abs(C[i].y - C[j].y);
            if(C[i].s == 1 && C[j].s == 1){
                if(dis > T) dis = T;
            }
            arr[i][j] = dis;
        }
    }
    FOR(o,N){   // 중간
        FOR(i,N){   // 시작
            FOR(j,N){   // 도착
                if(i==j) continue;
                arr[i][j] = min(arr[i][j], arr[i][o]+arr[o][j]);
            }
        }
    }
    cin>>M;
    FOR(i,M){
        cin>>A>>B;
        cout<<arr[A-1][B-1];
    }
}
