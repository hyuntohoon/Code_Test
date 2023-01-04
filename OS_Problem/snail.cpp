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
using namespace std;

ifstream ifs;
ofstream ofs;
long long X1,X2,Y1,Y2;
    // x증가, y증가, x감소, y감소
bool a = 0;
void find_Number(long long A, long long B, long long N, long long now_Number, long long shape, int step, long long X, long long Y, bool check){
    long long to_Number = A;
    if(now_Number+N-1>=to_Number && a== 0) { //해당 숫자보다 작은 경우
        X = to_Number;
        if(a == 0){
        X1 = X;
        Y1 = Y;     
        a = 1;   
        find_Number(B,B,N,now_Number,shape,step,1,1,check);
        }
        else{X2 = X;Y2 =Y;}
        return;
    }
    if(a == 0){
        now_Number = N;
        X = now_Number;
    }
    if(now_Number == 1){
        now_Number = N;
        X = now_Number;
    }
    while(now_Number<to_Number){
        if(shape == 0){ 
            X += step;
            now_Number+=step;
            shape =1;
        }
        else if(shape == 1){
            Y += step;
            now_Number+=step;
            shape = 2;
        }
        else if(shape == 2){
            X -= step;
            now_Number+=step;
            shape = 3;
        }
        else{ // shape == 3
            Y -= step;
            now_Number+=step;
            shape = 0;
        }
        if(now_Number>to_Number) break;
        if(check == 0) check = 1;
        else {check = 0; step--;}
    }
    long long ans_X = X, ans_Y = Y;
    if(now_Number>to_Number){
        now_Number-=step;
        long long cnt = to_Number-now_Number;
        shape--;
        if(shape == -1) shape = 3;
        if(shape == 0){ //3
            ans_X -= step;
            X -= step;
            ans_X += cnt;
        }
        else if(shape == 1){ //2
            ans_Y -= step;
            Y -= step;
            ans_Y += cnt;
        }
        else if(shape == 2){ //1
            ans_X += step;
            X += step;
            ans_X -= cnt;
        }
        else{ // 0
            ans_Y += step;
            Y +=step;
            ans_Y -= cnt;
        }
    }
    if(a == 0){
    X1 = ans_X;
    Y1 = ans_Y;     
    a = 1;   
    find_Number(B,B,N,now_Number,shape,step,X,Y, check);
    }
    else{X2 = ans_X;Y2 = ans_Y;}
    return;
}
int main(){
    ifs.open("snail.inp");
    ofs.open("snail.out");
    int T;
    ifs>>T;
    FOR(i,T){
        long long N,A,B;
        ifs>>N>>A>>B;
        long long temp = A;
        if(A>B){
            A = B;
            B = temp;
        }
        a=0;
        find_Number(A, B, N, 1, 1, N-1, 1, 1, 0);

        if(abs(X1-X2) == abs(Y1-Y2)){
            ofs<<"YES"<<endl;
        }else{
            ofs<<"NO"<<endl;
        }
    }
    return 0;
}