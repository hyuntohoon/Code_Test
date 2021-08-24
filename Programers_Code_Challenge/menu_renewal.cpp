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

vector<char> combi;
map<string, int> food;
int course_Max[11];
void mix(int N, int cnt, int start, string s){ // 재귀 N => j, cnt => 현재 cnt, 현재 s
    if(N == cnt){
        string temp ="";
        for(auto elem : combi){
            temp+=elem;
        }
        //cout<<temp<<endl;
        if(food.find(temp) != food.end()){
            food[temp]++;
            course_Max[temp.size()] = max(course_Max[temp.size()], food[temp]);
            cout<<"코스맥스"<<temp.size()<<" : "<<course_Max[temp.size()]<<endl;
        }
        else{
            
            food.insert(make_pair(temp, 1));
        }
        return;
    }
    for(int i=start;i<s.size();i++){
        combi.push_back(s[i]);
        mix(N,cnt+1,i+1,s);
        combi.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    // 조합을 통해 food maping
    FOR(i,course.size()){ // coruse의 사이즈만큼 전체 반복
        for(int j=0;j<orders.size();j++){ // 음식의 갯수만큼 반복
            //course 내 숫자만큼 조합 만들기
           // cout<<"orders : "<<orders[j]<<endl;
            mix(course[i], 0, 0, orders[j]);
        }
        //cout<<endl;
    }
    for(auto elem : food){
        cout<<elem.first<<" "<<elem.second<<endl;
    }
        for(auto food_Elem : food){
            cout<<"course_Max["<<food_Elem.first.size()<<"] : "<<course_Max[food_Elem.first.size()]<<" food_Elem.second : "<<food_Elem.second<<endl;
            if(course_Max[food_Elem.first.size()] == food_Elem.second){
                answer.push_back(food_Elem.first);
            }
        }
    
    return answer;
}
int main(){
    vector<string> orders ={"XYZ", "XWY", "WXA"};
    vector<string> orders_temp = orders;
    orders.clear();
    for(auto elem : orders_temp){
        vector<char> C;
        for(int i = 0;i<elem.size();i++){
            C.push_back(elem[i]);
        }
        sort(C.begin(),C.end());
        string temp = "";
        for(int i=0;i<C.size();i++){
            temp+=C[i];
        }
        orders.push_back(temp);
    }
    for(auto elem : orders){
        cout<<elem<<" ";
    }
    cout<<endl;
    vector<int> course = {2,3,4};
    vector<string> answer = solution(orders, course);
    for(auto elem : answer){
        cout<<elem<<" ";
    }
    cout<<endl;
}
