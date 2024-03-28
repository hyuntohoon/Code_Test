#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<n;i++)
using ll = long long;

using namespace std;
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> S(N);
	for (int i = 0; i < N; ++i) {
		cin >> S[i];
	}

	int left = 0, right = 0;
	int deleteCount = 0; // 홀수를 제거한 횟수
	int maxLength = 0; // 최대 길이

	for (right = 0; right < N; ++right) {
		if (S[right] % 2 != 0) { // 홀수를 만나면 deleteCount 증가
			deleteCount++;
		}

		// K번을 초과하여 홀수를 제거한 경우
		while (deleteCount > K) {
			if (S[left] % 2 != 0) { // left가 홀수였다면 deleteCount 감소
				deleteCount--;
			}
			left++; // left 포인터를 오른쪽으로 이동
		}

		// 최대 길이 업데이트
		maxLength = max(maxLength, right - left + 1 - deleteCount);
	}

	cout << maxLength << endl;
	return 0;
}
