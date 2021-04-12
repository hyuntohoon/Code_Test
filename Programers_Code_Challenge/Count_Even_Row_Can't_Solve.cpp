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
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 300 + 1
#define DIV 1000000009
#define RED 1
#define BLUE 0
#define endl "\n"
using namespace std;
typedef long long ll;

vector<vector<int>> a = {{1,0,0,1,1},{0,0,0,0,0},{1,1,0,0,0},{0,0,0,0,1}};
vector<vector<int>> A(400);
int arr_R[MAX];
int arr_C[MAX];
int answer;
int R_S; // a.size
int C_S; // a[0].size
//a.size = R, a[0] = C.size
void ROW(int R, int cnt, int S){
    if(R == C_S){
        FOR(i,R_S){
            FOR(j,C_S){
                if(A[i][j] == 1){
                    arr_C[i]++;
                }
            }
            if(arr_C[i] % 2 == 1){
                memset(arr_C, 0, sizeof(arr_C));
                return;
            }
        }
        answer++;
        memset(arr_C, 0, sizeof(arr_C));
        return;
    }
    
    if(cnt == arr_R[R]){
        ROW(R+1,0,0);
        return;
    }
    for(int i=S;i<R_S;i++){
        A[i][R] = 1;
        ROW(R,cnt+1,i+1);
        A[i][R] = 0;
    }
}
int main(){
    R_S = a.size();
    C_S = a[0].size();
    FOR(i,R_S){
        FOR(j,C_S){
            if(a[i][j] == 1){
                arr_R[j]++;
            }
            A[i].push_back(0);
        }
    }
    
    ROW(0,0,0);
    cout<<answer<<endl;
   // cout<<OOO<<endl;
}
