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
ifstream ifs;
ofstream ofs;
vector <pair<string,int> > V;
string Name[1001][2];
map<string,int> Overlap_Name;
int FN_Length;
vector <string> LN_V;
void input_Set(int N){
    string ID;
    string FN;
    string LN;
    FOR(i,N){
        ifs>>ID>>FN>>LN;
        Name[i][0] = FN;
        Name[i][1] = LN;
        Overlap_Name[LN]++;
        if(Overlap_Name[LN] ==2){
            LN_V.push_back(LN);
        }
        FN_Length = max((int)FN.length(),FN_Length);
        V.push_back(make_pair(ID,i));
        /*
        cout<<ID<<i<<endl;
        cout<<FN_Length<<endl;
        cout<<LN<<" : "<<Overlap_Name[LN];
        */
    }
    sort(LN_V.begin(),LN_V.end());
}

void running(){
    sort(V.begin(),V.end());
    FOR(i,N){
        int now_Name = V[i].second;
        ofs<<V[i].first<<" "<<Name[now_Name][0];
        //cout<<"길이 : "<<FN_Length<<" "<<Name[now_Name][0].size()<<endl;
        FOR(j,FN_Length-Name[now_Name][0].size()+1){
          ofs<<" ";
        }
        ofs<<Name[now_Name][1]<<endl;
    }
    ofs<<endl;
    FOR(i,LN_V.size()){
        ofs<<LN_V[i]<<" "<<Overlap_Name[LN_V[i]]<<endl;
    }
}
int main(){
    ifs.open("test.inp");
    ofs.open("test.out");
    ifs>>N;
    input_Set(N);
    running();
    ifs.close();
    ofs.close();
    return 0;
}
