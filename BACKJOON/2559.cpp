#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    int arr[100001];

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int now_sum = 0;
    int max_sum = 0;

    for (int i = 0; i < k; i++) {
        now_sum += arr[i];
    }

    max_sum = now_sum;

    for (int i = k; i < n; i++) {
        now_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, now_sum);
    }

    cout << max_sum << endl;

    return 0;
}
