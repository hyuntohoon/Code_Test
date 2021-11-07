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
map<string, bool> M;
vector<int> solution(int n, vector<string> words) {
    int now = 0;
    int cycle = 0;
    while(true){
        cycle++;
        FOR(i,n){
            if(M[words[now]] == 1){
                vector<int> answer;
                answer.push_back(i+1);
                answer.push_back(cycle);
                return answer;
                
            }
            if(now-1 >= 0){
                char before = words[now-1][words[now-1].length()-1];
                char after = words[now][0];
                cout<<words[now-1]<<" "<<before<<" "<<words[now]<<after<<endl;
                if(before != after){
                    cout<<"before"<<endl;
                    vector<int> answer;
                    answer.push_back(i+1);
                    answer.push_back(cycle);
                    return answer;
                }
            }
            M[words[now]] = 1;
            now++;
        }
        if(now == words.size()){
            cout<<"end"<<endl;
            vector<int> answer;
            answer.push_back(0);
            answer.push_back(0);
            return answer;
        }
    }
    // 같은 거 말함, 또는 다른 알파벳 말함
    // 몇번째 순서에 몇번째 사람이 탈락하는지 출력
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}