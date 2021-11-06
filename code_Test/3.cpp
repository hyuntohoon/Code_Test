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
#include <tuple>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<n;i++)
#define FOR2(i,n) for(int i=2;i<n;i++)
#define FORV(elem,V) for(auto elem : V)
#define MAX 1010
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
map<char,int> map_Al;
map<string, pair<int, int>> map_Menu;

int solution(vector<string> ings, vector<string> menu, vector<string> sell) {
    for(auto elem : ings){
        char Al = elem[0];
        string temp = elem.substr(2);
        map_Al[Al] = stoi(temp);
    }
    for(auto elem : menu){
        string temp = elem;
        istringstream ss(temp);
        string cut;
        int CASE = 0;
        string MENU = "";
        string arr_Al = "";
        string price = "";
        while(ss>>cut){
            if(CASE == 0){
                MENU = cut;
            }
            if(CASE == 1){
                arr_Al = cut;
            }
            if(CASE == 2){
                price = cut;
            }
            CASE++;
        }
        //cout<<MENU<<" "<<arr_Al<<" "<<price<<endl;
        int sum = 0;
        FOR(i,arr_Al.length()+1){
            sum+=map_Al[arr_Al[i]];
            cout<<arr_Al[i]<<" ";
            //cout<<"AL : "<<map_Al[arr_Al[i]]<<endl;
        }
        cout<<"sum : "<<sum<<endl;
        int P = stoi(price);
        map_Menu[MENU] = make_pair(sum, P);
    }
    int result = 0;
    for(auto elem : sell){
        string MENU = "";
        string cnt = "";
        istringstream ss(elem);
        int CASE =0;
        string cut;
        while(ss>>cut){
            if(CASE ==0){
                MENU = cut;
                CASE++;
            }
            if(CASE == 1){
                cnt = cut;
            }
        }
        cout<<map_Menu[MENU].second<<" "<<map_Menu[MENU].first<<endl;
        int benefit = map_Menu[MENU].second-map_Menu[MENU].first;
        int c = stoi(cnt);
        result += benefit*c;
    }
    cout<<result;
    return result;
}
int main(){
    /*
    string str = "PIZZA arraak 145";
    istringstream ss(str);
    cout<<ss.str()<<endl;
    string str_copy;
    vector<string> V;
    while(ss>>str_copy){
        V.push_back(str_copy);
    }
    for(auto elem : V){
        cout<<elem<<endl;
    }*/
    solution({"r 10", "a 23", "t 124", "k 9"}, {"PIZZA arraak 145", "HAMBURGER tkar 180", "BREAD kkk 30", "ICECREAM rar 50", "SHAVEDICE rar 45", "JUICE rra 55", "WATER a 20"},{ "BREAD 5", "ICECREAM 100", "PIZZA 7", "JUICE 10", "WATER 1"});
}
