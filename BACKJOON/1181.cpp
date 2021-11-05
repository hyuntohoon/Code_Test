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
    set<pair<int,string>> S;
    int N;
    cin>>N;
    FOR(i,N){
        string temp;
        cin>>temp;
        S.insert(make_pair(temp.size(),temp));
    }
    //sort(S.begin(),S.end());
    cout<<endl<<endl;
    for(auto elem : S){
        cout<<elem.second<<endl;
    }

}
