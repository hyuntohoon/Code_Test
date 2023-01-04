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

bool a = 0;
void find_Number(long long to_Number, long long N){
    //cout<<"start ------"<<endl;
    long long now_Number = 1;
    long long X,Y = 1;
    int shape = 1; // x증가, y증가, x감소, y감소
    if(now_Number+N-1>=to_Number) { //해당 숫자보다 작은 경우
        X = to_Number;
        cout<<"X : "<<X<<" Y : "<<Y<<endl;
        if(a == 0){X1 = X;Y1 = Y;}
        else{X2 = X;Y2 =Y;}
        return;
    }
    now_Number = N;
    X = now_Number;
    long long step = N-1; // 이번 차례의 걸음 수
    bool check = 0;
    while(now_Number<to_Number){
        //cout<<now_Number<<" "<<to_Number<<endl;
        //cout<<"step: "<<step<<endl;
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
        cout<<"find: "<<now_Number<<" "<<X<<" "<<Y<<" "<<shape<<endl;
        if(now_Number>to_Number) break;
        if(check == 0) check = 1;
        else {check = 0; step--;}
    }
    //cout<<"end :"<<now_Number<<" "<<to_Number<<endl;
    /* 개별로 가기*/
    if(now_Number>to_Number){
        now_Number-=step;
        long long cnt = to_Number-now_Number;
        //cout<<"cnt"<<cnt<<endl;
        //cout<<"step"<<step<<endl;
        
        shape--;
        if(shape == -1) shape = 3;
        //cout<<"shape"<<shape<<endl;
        if(shape == 0){ //3
            X -= step;
            X += cnt;
            //cout<<"qqaa X : "<<X<<" Y : "<<Y<<endl;
        }
        else if(shape == 1){ //2
            Y -= step;
            Y += cnt;
        }
        else if(shape == 2){ //1
            X += step;
            X -= cnt;
        }
        else{ // 0
            Y += step;
            Y -= cnt;
        }
    }

    cout<<"X : "<<X<<" Y : "<<Y<<endl;
    if(a == 0){X1 = X;Y1 = Y;}
    else{X2 = X;Y2 =Y;}
    return;
}
int main(){
    ifs.open("2.inp");
    ofs.open("snaill.out");
    int T;
    ifs>>T;
    FOR(i,T){
        a = 0;
        long long N,A,B;
        ifs>>N>>A>>B;
        cout<<"start: "<<N<<" "<<A<<" "<<B<<endl;
        find_Number(A, N);
        //cout<<"end ------"<<endl;
        a = 1;
        find_Number(B, N);
        //cout<<abs(point_A.first-point_B.first)<<endl;
        //cout<<abs(point_A.second-point_B.second)<<endl;
        //cout<<"ans: "<<X1<<" "<<X2<<" "<<Y1<<" "<<Y2<<endl;
        if(abs(X1-X2) == abs(Y1-Y2)){
            //cout<<"YES"<<endl;
            ofs<<"YES"<<endl;
        }else{
            //cout<<"NO"<<endl;
            ofs<<"NO"<<endl;
        }
    }
    return 0;
}