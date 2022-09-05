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

struct memory_State{
    int AD;
    int PID;
    int size;
    //memory_State(int AD, int PID, int size):AD(AD),PID(PID),size(size){}
};

struct time_State{
    int t;
    int check; // 0 반환, 1 요청
    int PID;
    int size;
    time_State(int t, int check ,int PID, int size):t(t), check(check),PID(PID),size(size){}
};

struct best{
    int AD;
    int PID;
    int size;
};

struct  compare
{
    bool operator()(time_State &A, time_State &B){
        if(A.t != B.t) // 다르면
            return A.t>B.t; // 바로
        if(A.check != B.check) // 다르면
            return A.check > B.check;
        return A.PID > B.PID; // 같으면
    }
};


priority_queue <time_State, vector<time_State>,compare> time_Stack1;
priority_queue <time_State, vector<time_State>,compare> time_Stack2;
priority_queue <time_State, vector<time_State>,compare> time_Stack3;
vector <int> V;

ifstream ifs;
ofstream ofs;
int N;
int max_Time= 0;

int first_Fit(){
    vector <memory_State> memory_Stack(10000);
    vector <time_State> wait_Q;
    memory_Stack[0].AD = 0;
    memory_Stack[0].PID= -1;
    memory_Stack[0].size = 1000;
    
    FOR(o,max_Time+1){
        int now_Size;
        int now_Check;
        int now_Pid;
        int now_Time;
        if(time_Stack1.size() == 0){ 
            break;
        }
        if(time_Stack1.top().t == o){
            now_Time = time_Stack1.top().t;
            now_Check = time_Stack1.top().check;
            now_Pid = time_Stack1.top().PID;
            now_Size = time_Stack1.top().size;
            
            //cout<<"memory : "<<now_Time<<" "<<now_Check<<" "<<now_Pid<<" "<<now_Size<<endl;
            FOR(aa, memory_Stack.size()){
                if(memory_Stack[aa].size == 0){
                    break;
                }
                //cout<<memory_Stack[aa].AD<<" "<<memory_Stack[aa].PID<<" "<<memory_Stack[aa].size<<endl;
            }
            //cout<<"memory end"<<endl;
            
            time_Stack1.pop();
            FOR(aa, memory_Stack.size()){
                if(memory_Stack[aa].size == 0){
                    break;
                }
            }
        if(now_Check == 1){ // 요청
            bool find_Check = 0;

            FOR(i,memory_Stack.size()){
                if(memory_Stack[i].size == 0) {
                    find_Check = 1; 
                    break;
                }
                if(memory_Stack[i].PID == -1 && memory_Stack[i].size >= now_Size){
                    memory_State M;
                    M.AD = memory_Stack[i].AD;
                    M.PID = now_Pid;
                    M.size = now_Size;
                    if(now_Size == memory_Stack[i].size){ // 요청 사이즈가 딱 맞는 경우
                        memory_Stack[i].PID = now_Pid;
                    }                
                    else{ // 차이가 나는 경우
                        memory_Stack.insert(memory_Stack.begin()+i, M);
                        memory_Stack[i+1].size -= now_Size;
                        memory_Stack[i+1].AD += now_Size;
                    }
                    if(now_Pid == N-1) {
                        return M.AD;
                    }
                    break;
                }
            }
            if(find_Check == 1) {
                wait_Q.push_back(time_State(0,now_Check,now_Pid,now_Size));
                //cout<<"wait_Q : "<<0<<" "<<now_Check<<" "<<now_Pid<<" "<<now_Size<<endl;
            }
        }

        if(now_Check == 0){ // 반환
            FOR(i,memory_Stack.size()){
                if(memory_Stack[i].size == 0) {
                    break;
                }
                if(now_Pid == memory_Stack[i].PID){
                    memory_Stack[i].PID= -1;
                    int plus_Size = 0;
                    if(i!=memory_Stack.size()-1){ // 앞 확인
                        if(memory_Stack[i+1].PID == -1){
                            plus_Size+=memory_Stack[i+1].size;
                            memory_Stack.erase(memory_Stack.begin()+i+1);
                        }
                    }
                    if(i!=0){ // 뒤 확인
                        if(memory_Stack[i-1].PID == -1){
                            plus_Size+=memory_Stack[i-1].size;
                            memory_Stack[i].AD = memory_Stack[i-1].AD; 
                            memory_Stack.erase(memory_Stack.begin()+i-1);
                            memory_Stack[i-1].size+=plus_Size; // 반환 완료
                        }
                        else memory_Stack[i].size+=plus_Size;
                    }
                    FOR(aa, memory_Stack.size()){
                       if(memory_Stack[aa].size == 0){
                            break;
                        }
                    }
                    break;
                }
            }
            //cout<<"size: "<<wait_Q.size()<<endl;
            FOR(a,wait_Q.size()){
                now_Pid = wait_Q[a].PID;
                now_Size = wait_Q[a].size;
                //cout<<"now_wait Q : "<<now_Pid<<" "<<now_Size<<endl;
                FOR(i,memory_Stack.size()){
                     if(memory_Stack[i].size == 0) {
                        break;
                    }
                    if(memory_Stack[i].PID == -1 && memory_Stack[i].size >= now_Size){
                        memory_State M;
                        M.AD = memory_Stack[i].AD;
                        M.PID = now_Pid;
                        M.size = now_Size;
                        if(now_Size == memory_Stack[i].size){ // 요청 사이즈가 딱 맞는 경우
                            memory_Stack[i].PID = now_Pid;
                        }                
                        else{ // 차이가 나는 경우
                            memory_Stack.insert(memory_Stack.begin()+i, M);
                            memory_Stack[i+1].size -= now_Size;
                            memory_Stack[i+1].AD += now_Size;
                        }
                        //cout<<"erase wait_Q"<<wait_Q[a].PID<<" "<<wait_Q[a].size<<endl;
                        wait_Q.erase(wait_Q.begin()+a);
                        /*
                        FOR(oo,wait_Q.size()){
                            cout<<wait_Q[oo].PID<<" "<<wait_Q[oo].size<<endl;
                        }*/
                        if(a != 0) a--;
                        if(now_Pid == N-1) {
                            return M.AD;
                        }
                        break;
                    }
                }
            }
        }
        }
        if(time_Stack1.top().t == now_Time){
            o--;
        }
    }
    return -1;
}

int best_Fit(){
    vector <memory_State> memory_Stack(10000);
    vector <time_State> wait_Q;
    memory_Stack[0].AD = 0;
    memory_Stack[0].PID= -1;
    memory_Stack[0].size = 1000;
    
    FOR(o,max_Time+1){
        int now_Size;
        int now_Check;
        int now_Pid;
        int now_Time;
        if(time_Stack2.size() == 0){ 
            break;
        }
        if(time_Stack2.top().t == o){
            now_Time = time_Stack2.top().t;
            now_Check = time_Stack2.top().check;
            now_Pid = time_Stack2.top().PID;
            now_Size = time_Stack2.top().size;
            /*
            cout<<"memory : "<<now_Time<<" "<<now_Check<<" "<<now_Pid<<" "<<now_Size<<endl;
            FOR(aa, memory_Stack.size()){
                if(memory_Stack[aa].size == 0){
                    break;
                }
                cout<<memory_Stack[aa].AD<<" "<<memory_Stack[aa].PID<<" "<<memory_Stack[aa].size<<endl;
            }
            cout<<"memory end"<<endl;
            */
            time_Stack2.pop();
            FOR(aa, memory_Stack.size()){
                if(memory_Stack[aa].size == 0){
                    break;
                }
            }

        if(now_Check == 1){ // 요청
            bool find_Check = 0;
            pair<int,int> best; // 가장 작은 크기, 해당 크기의 순서
            best.first = 1001;
            best.second = -1;
            FOR(i,memory_Stack.size()){
                if(memory_Stack[i].size == 0) {
                    if(best.first ==1001){
                        find_Check = 1; 
                    }
                    break;
                }
                if(memory_Stack[i].PID == -1 && memory_Stack[i].size >= now_Size){ // 메모리가 요청 사이즈 보다 클 경우
                    if(best.first > memory_Stack[i].size){
                        best.first = memory_Stack[i].size;
                        best.second = i;
                    }
                }
            }
            if(find_Check == 0){
                memory_State M;
                M.AD = memory_Stack[best.second].AD;
                M.PID = now_Pid;
                M.size = now_Size;
                if(now_Size == best.first){ // 요청 사이즈가 딱 맞는 경우
                    memory_Stack[best.second].PID = now_Pid;
                }                
                else{ // 차이가 나는 경우
                    memory_Stack.insert(memory_Stack.begin()+best.second, M);
                    memory_Stack[best.second+1].size -= now_Size;
                    memory_Stack[best.second+1].AD += now_Size;
                }
                if(now_Pid == N-1) {
                    return M.AD;
                }
            }
            if(find_Check == 1) {
                wait_Q.push_back(time_State(0,now_Check,now_Pid,now_Size));
            }
        }

        if(now_Check == 0){ // 반환
            FOR(i,memory_Stack.size()){
                if(memory_Stack[i].size == 0) {
                    break;
                }
                if(now_Pid == memory_Stack[i].PID){
                    memory_Stack[i].PID= -1;
                    int plus_Size = 0;
                    if(i!=memory_Stack.size()-1){ // 앞 확인
                        if(memory_Stack[i+1].PID == -1){
                            plus_Size+=memory_Stack[i+1].size;
                            memory_Stack.erase(memory_Stack.begin()+i+1);
                        }
                    }
                    if(i!=0){ // 뒤 확인
                        if(memory_Stack[i-1].PID == -1){
                            plus_Size+=memory_Stack[i-1].size;
                            memory_Stack[i].AD = memory_Stack[i-1].AD; 
                            memory_Stack.erase(memory_Stack.begin()+i-1);
                            memory_Stack[i-1].size+=plus_Size; // 반환 완료
                        }
                        else memory_Stack[i].size+=plus_Size;
                    }
                    FOR(aa, memory_Stack.size()){
                       if(memory_Stack[aa].size == 0){
                            break;
                        }
                    }
                    break;
                }
            }
            
            FOR(a,wait_Q.size()){
                now_Pid = wait_Q[a].PID;
                now_Size = wait_Q[a].size;
                bool find_Check = 0;
                pair<int,int> best; // 가장 작은 크기, 해당 크기의 순서
                best.first = 1001;
                best.second = -1;
                FOR(i,memory_Stack.size()){
                    if(memory_Stack[i].size == 0) {
                        if(best.first == 1001){
                            find_Check = 1; 
                        }
                        break;
                    }
                    if(memory_Stack[i].PID == -1 && memory_Stack[i].size >= now_Size){ // 메모리가 요청 사이즈 보다 클 경우
                        if(best.first > memory_Stack[i].size){
                            best.first = memory_Stack[i].size;
                            best.second = i;
                        }
                    }
                }
                if(find_Check == 0){
                    memory_State M;
                    M.AD = memory_Stack[best.second].AD;
                    M.PID = now_Pid;
                    M.size = now_Size;
                    if(now_Size == best.first){ // 요청 사이즈가 딱 맞는 경우
                        memory_Stack[best.second].PID = now_Pid;
                    }                
                    else{ // 차이가 나는 경우
                        memory_Stack.insert(memory_Stack.begin()+best.second, M);
                        memory_Stack[best.second+1].size -= now_Size;
                        memory_Stack[best.second+1].AD += now_Size;
                    }
                    if(now_Pid == N-1) {
                        return M.AD;
                    }
                    wait_Q.erase(wait_Q.begin()+a);
                    if(a != 0) a--;
                    break;
                    }
                }
            }
        }
        if(time_Stack2.top().t == now_Time){
            o--;
        }
    }
    return -1;
}

int worst_Fit(){
    vector <memory_State> memory_Stack(10000);
    vector <time_State> wait_Q;
    memory_Stack[0].AD = 0;
    memory_Stack[0].PID= -1;
    memory_Stack[0].size = 1000;
    
    FOR(o,max_Time+1){
        int now_Size;
        int now_Check;
        int now_Pid;
        int now_Time;
        if(time_Stack3.size() == 0){ 
            break;
        }
        if(time_Stack3.top().t == o){
            now_Time = time_Stack3.top().t;
            now_Check = time_Stack3.top().check;
            now_Pid = time_Stack3.top().PID;
            now_Size = time_Stack3.top().size;
            /*
            cout<<"memory : "<<now_Time<<" "<<now_Check<<" "<<now_Pid<<" "<<now_Size<<endl;
            FOR(aa, memory_Stack.size()){
                if(memory_Stack[aa].size == 0){
                    break;
                }
                cout<<memory_Stack[aa].AD<<" "<<memory_Stack[aa].PID<<" "<<memory_Stack[aa].size<<endl;
            }
            cout<<"memory end"<<endl;
            */
            
            time_Stack3.pop();
            FOR(aa, memory_Stack.size()){
                if(memory_Stack[aa].size == 0){
                    break;
                }
            }

        if(now_Check == 1){ // 요청
            bool find_Check = 0;
            pair<int,int> worst; // 가장 작은 크기, 해당 크기의 순서
            worst.first = -1;
            worst.second = -1;
            FOR(i,memory_Stack.size()){
                if(memory_Stack[i].size == 0) {
                    if(worst.first ==-1){
                        find_Check = 1; 
                    }
                    break;
                }
                if(memory_Stack[i].PID == -1 && memory_Stack[i].size >= now_Size){ // 메모리가 요청 사이즈 보다 클 경우
                    if(worst.first < memory_Stack[i].size){
                        worst.first = memory_Stack[i].size;
                        worst.second = i;
                    }
                }
            }
            if(find_Check == 0){
                memory_State M;
                M.AD = memory_Stack[worst.second].AD;
                M.PID = now_Pid;
                M.size = now_Size;
                if(now_Size == worst.first){ // 요청 사이즈가 딱 맞는 경우
                    memory_Stack[worst.second].PID = now_Pid;
                }                
                else{ // 차이가 나는 경우
                    memory_Stack.insert(memory_Stack.begin()+worst.second, M);
                    memory_Stack[worst.second+1].size -= now_Size;
                    memory_Stack[worst.second+1].AD += now_Size;
                }
                if(now_Pid == N-1) {
                    return M.AD;
                }
            }
            if(find_Check == 1) {
                wait_Q.push_back(time_State(0,now_Check,now_Pid,now_Size));
            }
        }

        if(now_Check == 0){ // 반환
            FOR(i,memory_Stack.size()){
                if(memory_Stack[i].size == 0) {
                    break;
                }
                if(now_Pid == memory_Stack[i].PID){
                    memory_Stack[i].PID= -1;
                    int plus_Size = 0;
                    if(memory_Stack[i].size != 0){ // 앞 확인
                        if(memory_Stack[i+1].PID == -1){
                            plus_Size+=memory_Stack[i+1].size;
                            memory_Stack.erase(memory_Stack.begin()+i+1);
                        }
                    }
                    if(i!=0){ // 뒤 확인
                        if(memory_Stack[i-1].PID == -1){
                            plus_Size+=memory_Stack[i-1].size;
                            memory_Stack[i].AD = memory_Stack[i-1].AD; 
                            memory_Stack.erase(memory_Stack.begin()+i-1);
                            memory_Stack[i-1].size+=plus_Size; // 반환 완료
                        }
                        else memory_Stack[i].size+=plus_Size;
                    }
                    FOR(aa, memory_Stack.size()){
                       if(memory_Stack[aa].size == 0){
                            break;
                        }
                    }
                    break;
                }
            }
            
            FOR(a,wait_Q.size()){
                now_Pid = wait_Q[a].PID;
                now_Size = wait_Q[a].size;
                bool find_Check = 0;
                pair<int,int> worst; // 가장 작은 크기, 해당 크기의 순서
                worst.first = -1;
                worst.second = -1;
                FOR(i,memory_Stack.size()){
                    if(memory_Stack[i].size == 0) {
                        if(worst.first == -1){
                            find_Check = 1; 
                        }
                        break;
                    }
                    if(memory_Stack[i].PID == -1 && memory_Stack[i].size >= now_Size){ // 메모리가 요청 사이즈 보다 클 경우
                        if(worst.first < memory_Stack[i].size){
                            worst.first = memory_Stack[i].size;
                            worst.second = i;
                        }
                    }
                }
                if(find_Check == 0){
                    memory_State M;
                    M.AD = memory_Stack[worst.second].AD;
                    M.PID = now_Pid;
                    M.size = now_Size;
                    if(now_Size == worst.first){ // 요청 사이즈가 딱 맞는 경우
                        memory_Stack[worst.second].PID = now_Pid;
                    }                
                    else{ // 차이가 나는 경우
                        memory_Stack.insert(memory_Stack.begin()+worst.second, M);
                        memory_Stack[worst.second+1].size -= now_Size;
                        memory_Stack[worst.second+1].AD += now_Size;
                    }
                    if(now_Pid == N-1) {
                        return M.AD;
                    }
                    wait_Q.erase(wait_Q.begin()+a);
                     if(a != 0) a--;
                    break;
                    }
                }
            }
        }
        if(time_Stack3.top().t == now_Time){
            o--;
        }
    }
    return -1;
}

void input_Set(){
    ifs>>N;
    FOR(i,N){
        int start, running_Time, size;
        ifs>>start>>running_Time>>size;
       // cout<<start<<" "<<1<<" "<<i<<" "<<size<<endl;
        time_Stack1.push(time_State(start,1,i,size));
        time_Stack1.push(time_State(start+running_Time,0,i,size));
        time_Stack2.push(time_State(start,1,i,size));
        time_Stack2.push(time_State(start+running_Time,0,i,size));
        time_Stack3.push(time_State(start,1,i,size));
        time_Stack3.push(time_State(start+running_Time,0,i,size));
        max_Time = max(max_Time, start+running_Time);
    }
    /*
    while(!time_Stack1.empty()){
        cout<<"time table : "<<time_Stack1.top().t<<" "<<time_Stack1.top().check<<" "<<time_Stack1.top().PID<<" "<<time_Stack1.top().size<<endl;
        time_Stack1.pop();
    }*/
    ofs<<first_Fit()<<endl;
    //cout<<"----------------"<<endl;
    ofs<<best_Fit()<<endl;
    //cout<<"-----------------"<<endl;
    ofs<<worst_Fit();
}

int main(){
    ifs.open("allocation.inp");
    ofs.open("allocation.out");
    input_Set();
    ifs.close();
    ofs.close();
}