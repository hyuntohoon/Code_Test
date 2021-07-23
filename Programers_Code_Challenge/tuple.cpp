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
    string s = "{{11,2,3},{2,11},{11,2,4,3},{2}}";
    vector<string> V[501];
    bool push_On = 0;
    string temp = "";
    int j = 0;
    for(int i =1;i<s.length();i++){
        if(s[i] == '{'){
            push_On = 1;
            continue;
        }
        if(s[i] == '}'){
            V[j].push_back(temp);
            temp = "";
            push_On = 0;
            j++;
        }
        if(push_On){
            if(s[i] != ','){
                temp+=s[i];
            }
            if(s[i] == ','){
                V[j].push_back(temp);
                temp = "";
            }
        }
    }
    int len = 1;
    bool visit[100010] = { false,};
    vector<int> answer;
    while (1)
    {
        bool F = false;
        for (int i = 0; i < j; i++)
        {
            if (V[i].size() == len)
            {
                F = true;
                for (int o=0;o<V[i].size();o++)
                {
                    int num = stoi(V[i][o]);
                    //cout<<num<<endl;
                    if (visit[num] == false)
                    {
                        visit[num] = true;
                        answer.push_back(num);
                    }
                }
                len++;
                break;
            }
        }
        if (F == false) break;
    }

}
