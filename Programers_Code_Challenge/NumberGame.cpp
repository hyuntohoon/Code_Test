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

using namespace std;

int solution(vector<int> A, vector<int> B) {
   sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    vector<int> :: iterator it_B;
    int N = A.size();
    int ans = 0;
    int tirggerA = 0;
    int tirggerB = 0;
    for(int i = 0;i<N;i++){
        
        if(B[tirggerB]>A[tirggerA]){
            ans++;
            tirggerB++;
            A.pop_back();
            B.pop_back();
        }
        else{
            A.pop_back();
            it_B = B.end()-1;
            B.erase(it_B);
        }
        tirggerA++;
    }
    return ans;
}