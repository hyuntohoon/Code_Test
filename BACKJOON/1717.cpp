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
#define MAX 1000000 + 1
#define DIV 1000000009
#define RED 1
#define BLUE 0
#define endl "\n"
using namespace std;
typedef long long ll;
int arr[1000001];
int N, M;

int find(int x){
    if(arr[x] == x){    // 부모를 찾았을 때 루트를 리턴
        return x;
    }
    arr[x] = find(arr[x]);
    return arr[x];
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    arr[b] = a;
}
void buffer_except(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
int main(){
    buffer_except();
    for(int i = 0;i<1000001;i++){
        arr[i] = i;
    }

    cin>>N>>M;
    FOR(i,M){
        bool F;
        int A, B;
        cin>>F>>A>>B;
        if(F == 0){
            merge(A,B);
            /*
            if(A == B){
                continue;
            }
            if(arr[B] == -1){
                arr[B] = A;
            }
            else{
                int temp;
                temp = arr[B];
                while(true){
                    if(arr[temp] == -1){
                        arr[temp] = A;
                        break;
                    }
                    else{
                        temp = arr[temp];
                    }
                }
            }*/
        }
        else{
            if(find(A) == find(B)){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
            /*
            int temp_a = arr[A];
            int temp_b = arr[B];
            bool find = 0;
            while(true){
                if(temp_a == -1){
                    break;
                }
                else{
                    if(temp_a == B){
                        cout<<"YES"<<endl;
                        find = 1;
                        break;
                    }
                    temp_a = arr[temp_a];
                }
            }
            while(true){
                if(find == 1){
                    break;
                }
                if(temp_b == -1){
                    break;
                }
                else{
                    if(temp_b == A){
                        cout<<"YES"<<endl;
                        find = 1;
                        break;
                    }
                    temp_b = arr[temp_b];
                }
            }
            if(find == 0){
                cout<<"NO"<<endl;
            }
             */
        }
        
    }
    
}
