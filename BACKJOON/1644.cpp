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
int N;
vector<bool> arr;
vector<int> V;
int main(){
    buffer_except();
    cin>>N;
    arr.resize(N+1,true);
    for(int i =2;i<=sqrt(N);i++){
        if(arr[i] == 0){
            continue;
        }
        for(int j = i*i;j<=N; j+=i){
            arr[j] = 0;
        }
    }

    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (arr[i] != 0){
            V.push_back(i);
        }
    }
    int F=0;
    int E=0;
    int sum=0;
  
    while (1) {
            if (sum >= N) {
                sum -= V[F++];
            }
            else if (E == V.size()) {
                break;
            }
            else {
                sum += V[E++];
            }
            if (sum == N) cnt++;
        }
    
    cout<<cnt<<endl;
}
