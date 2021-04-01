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
#include <cmath>

using namespace std;

bool visit[200 + 1];
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int N = numbers.size();
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int sum = numbers[i] + numbers[j];
            if(visit[sum] == 0){
                visit[sum] = 1;
                answer.push_back(sum);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}