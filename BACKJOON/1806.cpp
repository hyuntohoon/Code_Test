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
int N, S;
int arr[100001];
int h,l;

int main(){
    cin>>N>>S;
    FOR(i,N){
        cin>>arr[i];
    }
    int sum=0;
    int ans = 987654321;
    while(true){
        //cout<<l<<" "<<h<<" "<<sum<<endl;
        if(sum>=S){
            ans = min(h-l,ans);
            sum-=arr[l++];
        }
        else if(sum<S){
            sum+=arr[h++];
        }
        if(h>N){
            break;
        }
    }
    if(ans == 987654321){
        cout<<0<<endl;
        return 0;
    }
    cout<<ans<<endl;
}