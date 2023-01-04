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
#define endl "\n"
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N;
ifstream ifs;
ofstream ofs;

int main(){
    ifs.open("grid.inp");
    ofs.open("grid.out");
    int T;
    ifs>>T;
    FOR(i,T){
        int N,M,K;
        int NM;
        ifs>>N>>M>>K;
        NM = N*M; // 칠해야하는 값
        /**/
        int sum_N = 0; // 가로열의 덧셈
        int sum_M = 0; // 세로열의 덧셈
        int sel_N = N * 2; // 가로 선택의 최솟값
        int sel_M = M * 2; // 세로 선택의 최솟값
        int trash_N = 0; // 가로열 선택시 버려야되는 값 
        int trash_M = 0; // 세로열 선택시 버려야되는 값
        FOR(j,K){
            int a;
            ifs>>a;
            /*가로와 세로 모든 경우 탐색을 위해 모두 따로 더해서 저장 */
            sum_N += a; 
            sum_M += a;

            if(sel_N>a) sum_N-=a;  // 가로 선택시 최소 2열 이상 칠할 수 없는 경우 빼기
            else trash_N  += a%(sel_N/2); // 낱개로 칠할 수 없기 때문에 쓰레기 값 빼기

            if(sel_M>a) sum_M-=a; // 세로 선택시 최소 2열 이상 칠할 수 없는 경우 빼기
            else trash_M += a%(sel_M/2); // 낱개로 칠할 수 없기 때문에 쓰레기 값 빼기
        }

        sum_N-=trash_N; // 총 합계 - 쓰레기 값 = 색칠 가능한 값  
        sum_M-=trash_M; // ..
        if(NM > sum_N && NM > sum_M) {ofs<<"No"<<endl;} // 가로와 세로 모든 경우 알짜 값이 모든 경우를 칠할 수 없는지 확인
        else ofs<<"Yes"<<endl;
    }
}