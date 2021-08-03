#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;

int main(){
    vector<string> gems;
    gems.push_back("DIA");
    gems.push_back("RUBY");
    gems.push_back("RUBY");
    gems.push_back("DIA");
    gems.push_back("DIA");
    gems.push_back("EMERALD");
    gems.push_back("SAPPHIRE");
    gems.push_back("DIA");
    vector<int> answer(2);
    unordered_map<string, int> m;
    set<string> num(gems.begin(), gems.end());
    int Min, start = 0, end = 0;
    for(auto elem : num){
        cout<<elem<<" ";
    }
    cout<<endl;
    for(auto& s : gems){
        m[s]++;
        if(m.size() == num.size()) break;
        end++;  // => 이렇게 코딩했을때 end의 값이 바로 나온다.
                // m의 사이즈와 보석의 갯수가 같은 경우 => end의 기저사례
    }
    // map size => key 값을 기준으로 측정
    // key 값내 value => size값에 영향없음.
    
    cout<<end<<endl;
    cout<<gems.size()<<endl;
    Min = end - start;  //구간중 가장 짧은 구간을 구해야 하므로
    answer[0] = start + 1;
    answer[1] = end + 1;
    // answer를 이렇게 설정함으로 => 최소 사례가 정해짐

    while(end < gems.size()){ //
        string key = gems[start];
        m[key]--; start++;

        if(m[key] == 0){    // 최소한의 보석일 경우
                            // 추가될 수 있는 경우가 바로 end값의 확장이다.
                            
            end++;
            for(; end < gems.size(); end++){
                            // end부터 gems.size가 남아있는 경우까지
                m[gems[end]]++;  // m의 값을 추가하며
                if(key == gems[end]) // 이번 while문 내에서 삭제한 키값과
                                     // end이후의 키값이 동일한 경우
                                    // 구간의 확장이 가능할 수 있기때문에
                                    // 해당 for문을 종료하고
                    break;
            }
            if(end == gems.size()) break;
            // end가 마지막 gems까지 갔다면 while문 break
        }
        if(Min > end - start){ // answer_Change, 구간의 길이가 바뀐지 확인하고
                                // answer를 변경과 함께, Min값 변경
            answer[0] = start + 1;
            answer[1] = end + 1;
            Min = end - start;
        }

    }

    //return answer;
}

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

vector<int> solution(vector<string> gems) {
    set<string> S(gems.begin(), gems.end());
    map<string, int> M;
    deque<string> DQ;
    vector<int> answer(2);
    int len = 987654321 , start = 0, end=0;
  
    while(true){
        int i;
        for(i = end;i<gems.size();i++){
            M[gems[i]]++;
            if(M.size() == S.size()){
                end = i;
                break;
            }
        }
        if(i == gems.size()){
            break;
        }
        for(i = start; i<gems.size();i++){
            if(M[gems[i]] == 1){
                start = i;
                break;
            }
            else M[gems[i]]--;
        }
        
        if(end-start<len){
            answer[0] = start + 1;
            answer[1] = end + 1;
            len = end - start;
        }
        
        M.erase(gems[start]);
        start++;
        end++;
        
    }
    return answer;
}