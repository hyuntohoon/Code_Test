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

class com {//연산자 오버로딩부분
    public: bool operator() (const pair<int, int> a, const pair<int, int> b) {
        return a.second > b.second;
    }
};

ifstream ifs;
ofstream ofs;
int aa = 0;
int N;
int idle_Time;
int end_Time[1001];
int now_Time;
queue <int> P[1001];
priority_queue<pair<int, int>, vector<pair<int,int> >,greater<pair<int,int> > >sort_Process; 
void input_Set(int N){
    FOR(i,N){
        int start_Point;
        ifs>>start_Point;
        //cout<<"start : " <<start_Point<<endl;
        sort_Process.push(make_pair(start_Point,i));
            for(int j = 1;j<1001;j++){
                int nowNum;
                ifs>>nowNum;
            // cout<<nowNum<<" ";
                P[i].push(nowNum);
                if(nowNum == -1){
                    break;
                }
                //cout<<nowNum<<endl;
                //P[i].push_back(nowNum);
            }
        }
}

/*
int find_Process(){
    int now_Process = sort_Process.top().second;
    if(now_Time<sort_Process.top().first){
        idle_Time+=sort_Process.top().first-now_Time;
        now_Time = sort_Process.top().first;
    }
    else{
        now_Time += P[now_Process].front();
        P[now_Process].pop();
        sort_Process.push(make_pair(now_Time+P[now_Process].front(),now_Process));
        P[now_Process].pop();   
    }
}
*/
void running(){
    while(true){
        if(sort_Process.empty() == true){
            //cout<<idle_Time<<endl;
            ofs<<idle_Time<<endl;
            FOR(i,N){
                //cout<<end_Time[i]<<endl;
                ofs<<end_Time[i]<<endl;
            }
            return;
        }

        int now_Process = sort_Process.top().second;
        //cout<<" now_Time : "<<now_Time<<" now_Process : "<<now_Process<<" idle_Time "<<idle_Time<<endl;
        if(now_Time<sort_Process.top().first){ // idle 있을 경우 갱신하고, 다시 시작
            //cout<<P[sort_Process.top().second].front()<<" "<<aa<<endl;
            if((P[sort_Process.top().second].front() == -1) && (aa == N) ){
                idle_Time-=sort_Process.top().first-now_Time;
            }
            //cout<<now_Time<<" "<<sort_Process.top().first<<endl;
            idle_Time+=sort_Process.top().first-now_Time;
            now_Time = sort_Process.top().first;
        }
        else{ // idle 없을 경우 스택에 프로세스 실행, 갱신, 스택 pop
            if(P[now_Process].front() != -1){
                now_Time += P[now_Process].front();
            }
           // cout<<"now_Pop["<<now_Process<<"]: "<<P[now_Process].front()<<endl;
            P[now_Process].pop();
            int bb = P[now_Process].front(); // 만약 프로세스의 끝일 경우, 해당 bb를 더한 값이 끝
            sort_Process.pop();
            if(P[now_Process].front() == -1){ //짝수일 때
                //now_Time++;
                if(end_Time[now_Process] == 0){
                    aa++;
                    end_Time[now_Process] = now_Time;
                }
                //cout<<"end_Time["<<now_Process<<"] : "<<now_Time<<endl;
            }
            else{ // 홀수일 때 =>문제 없음
                sort_Process.push(make_pair(now_Time+P[now_Process].front(),now_Process));
                //cout<<"now_Pop["<<now_Process<<"]: "<<P[now_Process].front()<<endl;
                P[now_Process].pop();   
                if(P[now_Process].front() == -1){
                    aa++;
                    end_Time[now_Process] = now_Time+bb;
                    P[now_Process].push(-1);
                    //cout<<now_Time<<"@@@@@@@@@@@"<<endl;
                   // cout<<"hi"<<endl;
                }
            }
        }
 
    }



   /*
    while(sort_Process.size() !=0){
        cout<<sort_Process.top().first<<sort_Process.top().second<<endl;
        sort_Process.pop();
    }*/
}



int main(){
    ifs.open("fcfs.inp");
    ofs.open("fcfs.out");
    ifs>>N;
    input_Set(N);
    running();
    ifs.close();
    //ofs<<idle_Time<<endl;
    /*
    FOR(i,N){
        ofs<<end_Time[i]<<endl;
    }
    */
    ofs.close();
}
