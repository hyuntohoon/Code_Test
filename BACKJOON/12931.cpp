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
int N;
int A[51];
int B[51];
int ans = 987654321;

int main(){
    buffer_except();
    cin>>N;
    FOR(i,N){
        cin>>B[i];
    }
    int cnt=0;
    while(true){
        bool F=0;
        bool FF = 0;
        FOR(i,N){
            if(B[i] !=0){
                F= 1;
            }
            if(B[i]%2 == 1){
                FF=1;
                B[i]--;
                cnt++;
            }
        }
        if(F == 0){
            break;
        }
       
        if(FF == 0){
            FOR(i,N){
                B[i]/=2;
            }
            cnt++;
        }
    }
    cout<<cnt<<endl;
}