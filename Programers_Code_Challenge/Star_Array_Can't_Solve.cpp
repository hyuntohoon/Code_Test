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

int num[1000000];
int solution(std::vector<int> a) {
    std::vector<int> arr;
    int temp = a[0];
    arr.push_back(temp);
    for(int i=0;i<a.size();i++){
        if(temp != a[i]){
            arr.push_back(a[i]);
        }
        temp = a[i];
    }
    int answer = -1;
    for(auto elem : arr){
        num[elem]++;
        answer= std::max(num[elem], answer);
        
    }
    if(arr.size() == 1){
        return 0;
    }
    return answer*2;
}