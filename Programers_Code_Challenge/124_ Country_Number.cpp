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



using namespace std;

string solution(int n) {
    string answer ="";
    vector<int> V;
    while(n>=3){
        //cout<<n<<endl
        if(n%3 == 0){
            n = (n/3)-1;
            V.push_back(4);
            continue;
        }
        V.push_back(n%3);
        n = n/3;
    }
    //cout<<n<<endl;
    V.push_back(n);
    
    cout<<endl;
    for(auto elem : V){
        if(elem == 1){
           // cout<<"hi"<<endl;
            answer+="1";
        }
        else if(elem == 2){
            answer+="2";
        }
        else if(elem == 4){
            answer+="4";
        }
        //cout<<elem<<endl;
    }
    reverse(answer.begin(), answer.end());
    cout<<answer<<endl;
    return answer;
}