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
#define MAX 100000
#define DIV 1000000009
#define RED 1
#define BLUE 0
typedef long long ll;
using namespace std;
    int N,M;
    int temp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    vector<int> V(N);
    FOR(i,N){
        cin>>V[i];
    }
    sort(V.begin(), V.end());
    cin>>M;
    bool ans;
    FOR(i,M){
        cin>>temp;
        ans = binary_search(V.begin(), V.end(), temp);
        cout<<ans<<" ";
    }
}
