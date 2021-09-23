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
#define MAX 1000000 + 1
#define DIV 1000000009
#define DOWN 1
#define RIGHT 2
#define endl "\n"
#define has(a) (building.find(temp_Build[(a)])!=building.end())
using namespace std;
typedef long long ll;
void buffer_except(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
int arr[8];
int Number;
int answer = 9;

void start(int count, int now){
    if(count>=answer){
        //cout<<"count"<<endl;
        return;
    }
    if(now == Number){
        answer = count;
        return;
    }
    FOR(i,8){
        int nN = arr[i];
        int cnt_Plus = count + i + 1;
        start(cnt_Plus, now+nN);
        start(cnt_Plus, now-nN);
        start(cnt_Plus, now*nN);
        start(cnt_Plus, now/nN);
    }
}
int solution(int N, int number) {
    Number = number;
    arr[0] = N;
    arr[1] = N * 11;
    arr[2] = N * 111;
    arr[3] = N * 1111;
    arr[4] = N * 11111;
    arr[5] = N * 111111;
    arr[6] = N * 1111111;
    arr[7] = N * 11111111;
    start(0, 0);
    if(answer == 9){
        answer = -1;
    }
    //cout<<answer<<endl;
    return answer;
}
int main(){
    solution(8, 5800);
}
