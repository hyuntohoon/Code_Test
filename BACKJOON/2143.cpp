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
vector<ll> A_Sum;
vector<ll> B_Sum;
int main(){
    buffer_except();

    int A[1001];
    int N;
    int T;
    cin>>T;
    cin>>N;
    FOR(i,N){
        cin>>A[i];
    }
    for(int i =0;i<N;i++){
        ll sum = A[i];
        A_Sum.push_back(sum);
        for(int j=i+1;j<N;j++){
            sum+=A[j];
            A_Sum.push_back(sum);
        }
    }
    int B[1001];
    cin>>N;
    FOR(i,N){
        cin>>B[i];
    }
    for(int i =0;i<N;i++){
        ll sum = B[i];
        B_Sum.push_back(sum);
        for(int j=i+1;j<N;j++){
            sum+=B[j];
            B_Sum.push_back(sum);
        }
    }
    sort(A_Sum.begin(), A_Sum.end());
    sort(B_Sum.begin(), B_Sum.end());
    ll result = 0;
    for (auto item : A_Sum) {
        
        int temp = T - item;
        auto lower = lower_bound(B_Sum.begin(), B_Sum.end(), temp);
        auto upper = upper_bound(B_Sum.begin(), B_Sum.end(), temp);
    
        result += (upper - lower);
    }
    cout<<result<<endl;

}