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
#define MAX 1000000 + 1
#define DIV 1000000009
#define DOWN 1
#define RIGHT 2
#define endl "\n"
#define has(a) (building.find(temp_Build[(a)])!=building.end())
using namespace std;
typedef long long ll;
void buffer_except(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> D;
    FOR(i,progresses.size()){
        int P = progresses[i];
        int S = speeds[i];
        double temp = ceil(((100-P)*1.0)/S);
        //cout<<temp<<endl;
        D.push_back(temp);
    }
    int B = D[0];
    int now_Stack=1;
    vector<int> answer;
    for(int i = 1;i<D.size();i++){
        int now_D = D[i];
        //cout<<B<<" "<<now_D<<endl;
        if(B<now_D){
            //cout<<"push"<<endl;
            answer.push_back(now_Stack);
            now_Stack=1;
            B = now_D;
            continue;
        }
        //cout<<"now_S : "<<now_Stack<<endl;
        now_Stack++;
    }
    answer.push_back(now_Stack);
    
    return answer;
}