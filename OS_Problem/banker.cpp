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
ifstream ifs;
ofstream ofs;

int N,M; // N => 프로세스 개수, M => 자원의 종류
int Availble[51]; //가용 자원
int Need[51][51];
int Max[51][51];
int Alloc[51][51];
int start_Availble[51];
vector <pair<int, vector<int> > > request_Stack;

bool is_Safe(int now_Process, vector<int> request){
    int A_Availble[51];
    int A_Need[51][51];
    int A_Alloc[51][51];
    copy(Availble,Availble+51,A_Availble);
    copy(&Need[0][0],&Need[0][0]+51*51,&A_Need[0][0]);
    copy(&Alloc[0][0],&Alloc[0][0]+51*51,&A_Alloc[0][0]);
   /* 
    cout<<"now_All : ";
    FOR(i,M) cout<<A_Alloc[now_Process][i]<<" ";
    cout<<endl;
    cout<<"now_Av : ";
    FOR(i,M) cout<<A_Availble[i]<<" ";
    cout<<endl<<endl;
    */
    FOR(i,M){
        A_Availble[i] -= request[i];
        if(A_Availble[i] < 0){ //마이너스 값이 되면 리턴 
            return 0;
        }
        A_Alloc[now_Process][i] += request[i];
        A_Need[now_Process][i] = Max[now_Process][i] - A_Alloc[now_Process][i];
    }
    /*
    cout<<"now_All : ";
    FOR(i,M) cout<<A_Alloc[now_Process][i]<<" ";
    cout<<endl;
    cout<<"now_Need : ";
    FOR(i,M) cout<<A_Need[now_Process][i]<<" ";
    cout<<endl;
    */

    while(true){
        bool is_Work = 0;
        FOR(i,N){
            bool check_Safe = 0;
            //cout<<"compare : "<<i<<endl;
            FOR(j,M){
               // cout<<A_Need[i][j]<<" "<<A_Availble[j]<<endl;
                if(A_Need[i][j]>A_Availble[j] ){ // 한번이라도 불가능하면 
                    check_Safe = 1; 
                }
            }
         //   cout<<"--------------------"<<endl;
            if(check_Safe == 0){ // 한번이라도 바뀜
                is_Work = 1; // 한번이라도 바뀌면 
                FOR(j,M){
                    A_Availble[j] += A_Alloc[i][j];
                    A_Need[i][j] = 987654321;
                }
            }
        }
        if(is_Work == 0){ // 한번도 안 바뀜
            return 0;
        }
        int end_Process = 0;
        FOR(i,N){
            if(A_Need[i][0] == 987654321){
                end_Process++;
            }
        }
        if(end_Process == N) break;
    }

    return 1; // 가능
}
void request(){
    int now_Process;
    vector<int> request(51);
    bool F = 1;
    ifs>>now_Process;
    FOR(i,M){
        int now;
        ifs>>request[i];
    }
    FOR(i,M){
        if(Availble[i]-request[i]<0){
            F = 0;
        }
    }
    //cout<<Availble[0]<<endl;
    F = is_Safe(now_Process, request);
    cout<<F<<endl;
    if(!F){
        request_Stack.push_back(make_pair(now_Process, request));
        return;
    }
    FOR(i,M){
        Availble[i] -= request[i];
        Alloc[now_Process][i] += request[i];
        Need[now_Process][i] = Max[now_Process][i] - Alloc[now_Process][i];
    }
}
int bb = 0;
void release(){
    int now_Process;
    vector <int> request(51);
    bool end = 0;
    ifs>>now_Process;
    FOR(i,M){
        ifs>>request[i];
        //cout<<start_Availble[i]<<request[i]<<endl;
        if(request[i]+Availble[i]>start_Availble[i]){
            end = 1;
        }
    }
    if(end == 1){
        return;
    }
    FOR(i,M){
        Availble[i] += request[i];
        Alloc[now_Process][i] -= request[i];
        Need[now_Process][i] = Max[now_Process][i] - Alloc[now_Process][i];
    }
/*
    FOR(i,M){
        cout<<Availble[i]<<" ";
    }
    cout<<endl;
    */
    bool F = 1;

    if(request_Stack.size() == 0){
        F = 0;
    }
    FOR(e,request_Stack.size()){
        now_Process = request_Stack[e].first;
        request = request_Stack[e].second;
        F = 1;
        FOR(i,M){
            if(Availble[i]-request[i]<0){
               F = 0;
            }
        }
        F = is_Safe(now_Process, request);
        if(F == 1){
            request_Stack.erase(request_Stack.begin()+e);
            break;
        }
        //cout<<"release: "<<F<<endl;
    }
    if(!F){
        return;
    }
    FOR(i,M){
        Availble[i] -= request[i];
        Alloc[now_Process][i] += request[i];
        Need[now_Process][i] = Max[now_Process][i] - Alloc[now_Process][i];
    }
}
void write_Available(){
    FOR(i,N){
        FOR(j,M){
            cout<<Need[i][j]<<" ";
        }
        cout<<endl;
    }
    FOR(i,M){
        ofs<<Availble[i]<<" ";
        //cout<<Availble[i]<<" ";
    }
    ofs<<endl;
}
void input(){
    ifs>>N>>M;
    FOR(i,M){
        ifs>>Availble[i];
        start_Availble[i] = Availble[i];
    }
    //cout<<endl;
    FOR(i,N){
        FOR(j,M){
            ifs>>Max[i][j];
        }
    }
    FOR(i,N){
        //cout<<"Need["<<i<<"] :";
        FOR(j,M){
            ifs>>Alloc[i][j];
            Availble[j] -= Alloc[i][j];
            Need[i][j] = Max[i][j] - Alloc[i][j];
            //cout<<Need[i][j]<<" ";
        }
        //cout<<endl;
    }
    string S;

    while(true){
        ifs>>S;
        if(S == "request"){
            request();
            write_Available();
        }
        else if(S == "release"){
            release();
            write_Available();
        }
        else if(S == "quit"){
            break;
        }
    }
}
int main(){
    ifs.open("2.inp");
    ofs.open("banker.out");
    input();    

    ifs.close();
    ofs.close();
    return 0;
}