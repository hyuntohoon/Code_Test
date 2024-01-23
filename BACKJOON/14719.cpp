#include <iostream>
#include <algorithm>
using namespace std;

int H, W;
int arr[501];

void input() {
    cin >> H >> W;
    for (int i = 0; i < W; i++) {
        cin >> arr[i];
    }
}

void solve() {
    input();

    int leftMax[501], rightMax[501];
    
    // 왼쪽에서 가장 높은 블록 계산
    leftMax[0] = arr[0];
    for (int i = 1; i < W; i++) {
        leftMax[i] = max(leftMax[i-1], arr[i]);
    }

    // 오른쪽에서 가장 높은 블록 계산
    rightMax[W-1] = arr[W-1];
    for (int i = W-2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i+1], arr[i]);
    }

    // 빗물 계산
    int result = 0;
    for (int i = 0; i < W; i++) {
        result += min(leftMax[i], rightMax[i]) - arr[i];
    }

    cout << result << endl;
}

int main() {
    solve();
    return 0;
}
