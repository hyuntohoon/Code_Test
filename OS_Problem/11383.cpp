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
#include <stdio.h>
#include <fstream>
#include <sstream>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
typedef long long ll;
using namespace std;

int main(){
    vector <string> N_S(10),M_S(10);
    stringstream stream;
    int N,M;
    cin>>N>>M;
    FOR(i,N){
        string S;
        cin>>S;
        string temp_S ="";
        FOR(j,S.size()){
            temp_S+=S[j];
            temp_S+=S[j];
        }
        N_S[i] = temp_S;
    }
    FOR(i,M){
        string S;
        cin>>S;
        if(S != N_S[i]){
            cout<<"Not Eyfa";
            return 0;
        }
    }
    cout<<"Eyfa";
    return 0;
}