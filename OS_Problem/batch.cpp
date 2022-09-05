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
int N;
int allTime = 0;
int idleTime = 0;
queue <int> P[1001];
int process_IO[1001];
int idle_Time;
ifstream ifs;
ofstream ofs;
int bb;
int now_Time = 0;


void input_Set(int N){
FOR(i,N){
        FOR(j,1001){
            int nowNum;
            ifs>>nowNum;
            if(nowNum == -1){
                break;
            }
            //cout<<nowNum<<endl;
            P[i].push(nowNum);
            //P[i].push_back(nowNum);
        }
    }
}

int find_Process(){ //가장 낮고 I/O가 아닌, process 찾기,
    int least_IO = 987654321;
    FOR(i,N){ //
        //cout<<now_Time<<" VS process_IO["<<i<<"] : "<<process_IO[i]<<endl;
        if(now_Time>=process_IO[i]){ // 찾음
            //cout<<now_Time<<"process_IO"<<i<<" : "<<process_IO<<endl;
            return i;
        }
        least_IO = min(least_IO, process_IO[i]);
    }
    //cout<<"least_IO : "<<least_IO<<endl;
    if(least_IO != 987654321){
        //cout<<"sasasaf"<<least_IO<<" "<<now_Time<<endl;
        bb = least_IO - now_Time;
        idle_Time+=least_IO-now_Time;
        now_Time = least_IO;
        //cout<<"***now_Time : "<<now_Time<<endl;
        return -2;
    }
    return -1;
}
void running(){
   while(true){
       int now_Process = find_Process();
       //cout<<now_Process<<endl;
       //cout<<now_Time<<endl;
       if(now_Process == -1){
           //cout<<"end: "<<now_Time<<endl;
           idle_Time -= bb;
            //cout<<idle_Time<<endl;
           return;
       }
       if(now_Process == -2){
            
             //cout<<"now_Time : "<<now_Time<<endl;
             //cout<<"aa : "<<aa<<endl;
              //cout<<"now_Time : "<<now_Time<<endl;
             continue;
       }
       if(P[now_Process].size()>1){
           cout<<"front"<<P[now_Process].front()<<endl;
            now_Time +=P[now_Process].front();
            P[now_Process].pop();
            process_IO[now_Process] = now_Time+P[now_Process].front();
            P[now_Process].pop();
       }
       else{
           now_Time+=P[now_Process].front();
           P[now_Process].pop();
           process_IO[now_Process] = 987654321;
       }
   }
   return;
}
int main(){
    ifs.open("batch.inp");
    ofs.open("batch.out");
    ifs>>N;
    input_Set(N);
    running();
    ifs.close();
    ofs<<idle_Time<<" "<<now_Time<<"as";
    ofs.close();
    return 0;
}
 /*
    ofstream ofs;
    ofs.open("batch.out");
    ofs<<idleTime<<" "<<allTime<<endl;
    ofs.close();
    */