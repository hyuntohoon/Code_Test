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
int DP[1000+10];
int arr[1000+10];
int N;

int main(){
    buffer_except();
    cin>>N;
    FOR(i,N){
        cin>>arr[i];
        DP[i] = 2e9;
    }
    DP[0] = 0;
    if(N == 1){
        cout<<0<<endl;
        return 0;
    }
    for(int i =1;i<N;i++){
        for(int j = 0;j<=i;j++){
            if(j+arr[j]>=i)
            {
                DP[i] = min(DP[i],DP[j]+1);
            }
        }
    }
    if(DP[N-1] == 2e9){
        cout<<-1<<endl;
    }
    else{
        cout<<DP[N-1]<<endl;
    }
}
