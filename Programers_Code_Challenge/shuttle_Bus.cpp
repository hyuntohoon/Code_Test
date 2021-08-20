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
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000000 + 1
#define DIV 1000000009
#define DOWN 1
#define RIGHT 2
#define endl "\n"
using namespace std;
typedef long long ll;
void buffer_except(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
int main(){
    /*
     
     n = 운행 횟수 (0<n<=10)
     t = 셔틀 운행 간격 (0<t<=60)
     m = 한 셔틀에 탈 수 있는 최대 크루 수 (0<m<=45)
         1. 콘은 제일 늦게 도착하고 싶다.
         2. 하지만 무조건 출근을 해야한다.
         3. 그래서 탈 수 있는 경우 중 가장 늦게 타야한다.
     n * m => 태울 수 있는 최대 명수
     timetable => 최대 2000 길이
     (최대 명수) vs (timetable.size())
     (<=)이면 최대 명수까지 timetable 움직이고 그
     (>)이면 => 제일 마지막에
     */
    int n, t, m;
    vector<string> timetable = { "09:00", "09:00", "09:00", "09:00"};
    n=2;
    t=1;
    m=2;
    vector<int> timetable_Minute;
    int temp;
    int answer_Minute=540;
    for(auto elem : timetable){
        
        temp = 0;
        temp+=((elem[0]-48)*600);
        temp+=((elem[1]-48)*60);
        temp+=((elem[3]-48)*10);
        temp+=((elem[4])-48);
        timetable_Minute.push_back(temp);
        cout<<temp<<endl;
    }
    sort(timetable_Minute.begin(),timetable_Minute.end());
    int suttle_Time=540;
    int crew_Idx=0;
    if(timetable.size()<n*m){
        answer_Minute+=n*t;
    }
    else{
        for(int i=1;i<n;i++,suttle_Time+=t){
            int count=0;
            for(int j=crew_Idx;j<timetable.size();j++){
                if(timetable_Minute[crew_Idx]<=suttle_Time){
                    crew_Idx++;
                    count++;
                    if(count == m) break;
                }
            }
            if(i==n){
                if(count==m){
                    answer_Minute = timetable_Minute[crew_Idx-1]-1;
                }
                else{
                    answer_Minute = suttle_Time;
                }
            }
        }
    }
    string answer = "";
    int hour = answer_Minute / 60;
    int minute = answer_Minute % 60;
    char A = hour / 10 + 48;
    char B = hour % 10 + 48;
    char C = minute / 10 + 48;
    char D = minute % 10 + 48;
    answer = answer + A;
    answer = answer + B;
    answer = answer + ':';
    answer = answer + C;
    answer = answer + D;

}
