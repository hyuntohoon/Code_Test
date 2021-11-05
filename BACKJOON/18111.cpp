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

int arr[501][501];
map<int,int> MAP;
int main(){
    int N,M,temp_B;
    int ans_Second = 987654321;
    int ans_Height = 0;
    cin>>N>>M>>temp_B;
    FOR(i,N){
        FOR(j,M){
            cin>>arr[i][j];
        }
    }
    FOR(k,257){
        int second = 0;
        int height = k;
        bool restart = 0;
        int B = temp_B;
        FOR(i,N){
            if(restart == 1){
                break;
            }
            FOR(j,M){
                if(restart == 1){
                    break;
                }
                if(arr[i][j]>=height){
                    second += ((arr[i][j]-height)*2);
                    B+=arr[i][j]-height;
                }
                else{
                        B-=(height-arr[i][j]);
                        second += height-arr[i][j];
                
                }
            }
        }
        if(B<0){
            continue;
        }
        if(second < ans_Second){
            ans_Second = second;
            ans_Height = height;
        }
        else if(second == ans_Second){
                ans_Height = height;
        }
        //cout<<second<<" "<<height<<endl;
    }
    cout<<ans_Second<<" "<<ans_Height<<endl;
}
