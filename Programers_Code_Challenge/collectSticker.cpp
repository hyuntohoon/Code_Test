#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int N = sticker.size();
    int DP[1000010];
    if(N == 1){
        return sticker[0];
    }
    DP[0] = sticker[0];
    DP[1] = sticker[0];
    for(int i=2;i<N-1;i++){
        DP[i] = max(DP[i-2] + sticker[i], DP[i-1]);
    }
    int ans = DP[N-2];
    DP[0] = 0;
    DP[1] = sticker[1];
    for(int i=2;i<N;i++){
        DP[i] = max(DP[i-2] + sticker[i], DP[i-1]);
    }
    ans = max(ans, DP[N-1]);
    return ans;
}