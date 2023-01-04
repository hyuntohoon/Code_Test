#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include<stdio.h>
#include<fstream>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
typedef long long ll;
using namespace std;

int main(){
    ll M;
    cin>>M;
    ll answer = 1;
    int check = 0;
    FOR(i,M){
        ll f,e,S;
        cin>>f>>e>>S;
        check+=S;
        answer = answer*e/f;
    }
    cout<<check%2<<" "<<answer<<endl;
}