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
using namespace std;
ofstream ofs;
ifstream ifs;

int main(){
    int T;
    ifs.open("stairs.inp");
    ofs.open("stairs.out");
    ifs>>T;

    FOR(i,T){
      int M,F,N;
        ifs>>M>>F>>N;
        int first_Step = M-F;
        int count = 1;
        int A = (N-first_Step) / (M-1);
        count += A;
        N = (N-first_Step) % (M-1);
        if(N == 0 && F == M) {
            ofs<<count-1<<endl; 
            continue;
            }
        if(F<=N){ // 시작 계단을 다시 찾아야 하는 경우
            count++;
        }
        ofs<<count<<endl;
    }
    ifs.close();
    ofs.close();
}