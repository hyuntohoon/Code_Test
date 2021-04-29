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
int N, M;
int ans =0;
int arr[10001];
bool F;
void sum(int s, int e){
    int sum = 0;
    for(int i = s;i<=e;i++){
        sum+=arr[i];
        if(sum>M){
            F=1;
            //cout<<sum<<endl;
            return;
        }
    }
    //cout<<s<<" "<<e<<" "<<M<<" "<<sum<<endl;
    if(sum == M){
        ans++;
        return;
    }
    return;
}
int main(){

    cin>>N>>M;
    FOR(i,N){
        cin>>arr[i];
    }
    int l=0,h=0,sum=0;
    while(true){
        if(sum>=M) sum-=arr[l++];
        else if (h == N) break;
        else sum +=arr[h++];
        if(sum == M) ans++;
    }
    cout<<ans<<endl;
}
