#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
using namespace std;

int main(){
    int T;
    cin>>T;
    FOR(o,T){
        int N,M;
        int wall[16][16];
        cin>>N>>M;
        FOR(i,N){
            FOR(j,N){
                cin>>wall[i][j];
            }
        }
        int maxCatchFly=0;
        for(int i=0;i<N-M+1;i++){
            for(int j=0;j<N-M+1;j++){
                int catchFly = 0;
                for(int a = i;a<i+M;a++){
                    for(int b = j;b<j+M;b++){
                        catchFly+=wall[a][b];
                    }
                }
                maxCatchFly = max(catchFly, maxCatchFly);
            }
        }
        cout<<"#"<<o+1<<" "<<maxCatchFly<<endl;
    }
}