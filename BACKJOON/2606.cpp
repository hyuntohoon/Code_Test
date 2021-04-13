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
int N,M;
int arr[101];

int find(int x){
    if(arr[x] == x){
        return x;
    }
    
    return arr[x] = find(arr[x]);
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        arr[b] = a;
    }
}
int main(){
    buffer_except();

    cin>>N>>M;
    vector<pair<int, int>> V;
    for(int i = 1;i<=N;i++){
        arr[i] = i;
    }
    FOR(i,M){
        int A,B;
        cin>>A>>B;
        merge(A,B);
    }
    
    int cnt = 0;
    
    for(int i = 2;i<=N;i++){
        if(find(1) == find(i)){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
