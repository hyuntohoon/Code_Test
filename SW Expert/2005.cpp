#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
using namespace std;

int main(){
    int pascalTriangle[11][11];
    FOR(i,11){
        FOR(j,11){
            pascalTriangle[i][j] = 0;
        }
    }
    pascalTriangle[1][1] = 1;

    for(int i = 2;i<11;i++){
        for(int j=1;j<i+1;j++){
            pascalTriangle[i][j] = pascalTriangle[i-1][j] + pascalTriangle[i-1][j-1];
        }
    }
    int T;
    cin>>T;
    FOR(o,T){
        int N;
        cin>>N;
        cout<<"#"<<o+1<<endl;
        for(int i = 1;i<N+1;i++){
            for(int j=1;j<i+1;j++){
                cout<<pascalTriangle[i][j]<<" ";
            }
            cout<<endl;
        }
    
    }
}

