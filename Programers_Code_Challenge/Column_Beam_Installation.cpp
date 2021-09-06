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
#define has(a) (building.find(temp_Build[(a)])!=building.end()) // 반복되는 긴 함수를 축약하기 위해 define을 썼다.
                                                                // 하지만 축약말고도 실수를 줄이기 위해 define을 쓴다.
using namespace std;
typedef long long ll;
void buffer_except(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

bool check_Build(set<vector<int>> building){ // building을 그대로 가져온다.
    for(auto elem:building){ // building 역시 auto elem으로 참조한다.
        int x = elem[0], y = elem[1], a = elem[2]; // 이번엔 변수를 뽑아서 쓴다.
                                                    // 그 이유는 해당 변수를 수정하며 함수에 실행하기 위해서이다.
        if(a==0){
            vector<int> temp_Build[3] = {{x,y,1},{x-1,y,1},{x,y-1,0}};  // 조건에 대해 vector로 구성한다.
            if(y == 0 || has(0) || has(1) || has(2)) continue; // define 해둔 fine 함수를 기준으로 if문을 간결히 처리한다.
            return 0;
        }
        else{
            vector<int> temp_Build[4] = {{x,y-1,0}, {x+1,y-1,0}, {x-1,y,1},{x+1,y,1}}; // 위와 같다.
            if(has(0) || has(1) || (has(2)&&has(3))) continue;
            return 0;
        }
    }
    
    return 1;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    set<vector<int>> building; // 정렬되어 출력하기 위해 set를 이용해 mapping을 해두었다.
    
    for(auto elem:build_frame){ // auto elem으로 bulid_frame을 참조하였다.
        vector<int> temp = {elem[0],elem[1],elem[2]}; // x,y,a을 변수로 뽑아내지 않고 벡터 그대로 사용하기 위해 벡터로 지정했다.
        if(elem[3] == 1){ // 구분하여 실행했다.
            building.insert(temp); // set 중복이 없다. 그래서 temp를 그대로 삭제 또는 insert한다면 문제 없이 바로 적용할 수 있다.
            if(!check_Build(building)) building.erase(temp); // check에 실패하면 다시 복귀했다.
        }
        else if(elem[3] == 0){
            building.erase(temp); // set 중복이 없다. 그래서 temp를 그대로 삭제 또는 insert한다면 문제 없이 바로 적용할 수 있다.
            if(!check_Build(building)) building.insert(temp); // check에 실패하면 다시 복귀했다.
        }
    }
    for(auto elem:building) answer.push_back(elem); // building의 구성은 vector이므로 바로 push_back했다.
    return answer;
}

/*  이 풀이에 놀라운 점은 vector, set의 적재적소에 알맞게 사용했고,
    간결하고 명확한 풀이를 위해 반복되는 부분을 잘 처리하였다.
*/