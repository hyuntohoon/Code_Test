#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
using namespace std;

int main(){
    FOR(i,10){
        cin>>T;
        int arr[100][100];
        int seroMax = 0;
        int garoMax = 0;
        FOR(S,100){
            int garo = 0;
            FOR(G,100){
                cin>>arr[S][G];
                garo+=arr[S][G];
                if(G == 99){
                    garoMax = max(garo, garoMax);
                }
            }
        }
        FOR(G,100){
            int sero =0;
            FOR(S,100){
                sero += arr[S][G];
            }
            seroMax = max(sero, seroMax);
        }
        int a = 0;
        int b = 0;
        int axisA = 0;
        int axisB = 0;
        FOR(j, 100){
            axisA += arr[j][j];
            axisB += arr[j][99-j];
        }
        int answer = 0;
        answer = max(garoMax, seroMax);
        answer = max(answer, axisB);
        answer = max(answer, axisA);
        printf("#%d %d\n",T,answer);
    }

}