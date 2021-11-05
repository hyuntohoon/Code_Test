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
#include <string>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <tuple>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<n;i++)
#define FOR2(i,n) for(int i=2;i<n;i++)
#define FORV(elem,V) for(auto elem : V)
#define MAX 1010
#define DIV 1000000009
#define DOWN 1
#define RIGHT 2
#define endl "\n"

using namespace std;
typedef long long ll;
void buffer_except(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main(){
    int N;
    int A, B;
    cin>>N>>A>>B;
    int cnt = 0;
    while(true){
        cnt++;
        if(A/2 + A%2 == B/2 + B%2){
            //cout<<A/2 + A%2<<" "<<B/2 + B%2<<endl;
            //cnt++;
            cout<<cnt<<endl;
            return 0;
        }

        A = A/2 + A%2;
        B = B/2 + B%2;
        //cout<<cnt<<" "<<A<<" "<<B<<endl;
    }
}