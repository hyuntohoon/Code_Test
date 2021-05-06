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
#include <math.h>
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

int main(){
    buffer_except();
    vector<ll> A;
    vector<ll> B;
    vector<ll> C;
    vector<ll> D;
    int N;
    cin>>N;
    FOR(i, N){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }
    vector<ll> AB;
    vector<ll> CD;
    for(int i = 0;i<N;i++){
        for(int j=0;j<N;j++){
            ll ab = A[i]+B[j];
            ll cd = C[i]+D[j];
            AB.push_back(ab);
            CD.push_back(cd);
        }
    }
    sort(AB.begin(),AB.end());
    sort(CD.begin(),CD.end());
    /*
    for(auto elem:AB){
        cout<<elem<<" ";
    }
    cout<<endl<<endl;
    for(auto elem:CD){
        cout<<elem<<" ";
    }
    cout<<endl;*/
    ll cnt = 0;
    for(int i = 0;i<N*N;i++){
        ll T = AB[i]*-1;
        ll sum = upper_bound(CD.begin(), CD.end(),T) - lower_bound(CD.begin(), CD.end(),T);
        if(sum !=0){
            cnt+=sum;
        }
        
    }
    cout<<cnt<<endl;
    /*
    cout<<endl;
    ll cnt = 0;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            for(int k = 0;k<N;k++){
                for(int o = 0;o<N;o++){
                    ll sum = A[i]+B[j]+C[k]+D[o];
                    if(sum == 0){
                     //   cout<<A[i]<<" "<<B[j]<<" "<<C[k]<<" "<<D[o]<<endl;
                        cnt++;
                    }
                }
            }
        }
    }
    cout<<cnt<<endl;*/
}
