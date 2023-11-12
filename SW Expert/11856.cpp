#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
using namespace std;

int main(){
    int arr[91];
    for(int i =65;i<91;i++){
        arr[i] = 0;
    }
    int T;
    cin>>T;
    FOR(i,T){
        string S;
        int answer = 0;
        cin>>S;
        FOR(j,4){
            int temp = S[j];
            arr[temp]++;
            if(arr[temp] == 2 )answer++;
        }
        if(answer==2){
            printf("#%d Yes\n", i+1);
            continue;
        }
        printf("#%d No\n", i+1);
    }
}