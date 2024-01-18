#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int T = 10;        
    for (int t = 1; t < T+1; t++) {
        int N;
        cin >> N;
        int arr[1001];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int sum = 0;
        for (int i = 2; i < N - 2; i++) {
            int result;
            int leftMin;
            int rightMin;
            int left1 = arr[i] - arr[i - 1];
            int left2 = arr[i] - arr[i - 2];
            int right1 = arr[i] - arr[i + 1];
            int right2 = arr[i] - arr[i + 2];
            if (left1 < 0) left1 = 0;
            if (left2 < 0) left2 = 0;
            if (right1 < 0) right1 = 0;
            if (right2 < 0) right2 = 0;
            leftMin = min(left1, left2);
            rightMin = min(right1, right2);
            result = min(leftMin, rightMin);
            sum += result;
        }
        printf("#%d %d", t, sum);
    }
}
