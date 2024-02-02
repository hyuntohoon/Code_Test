// ConsoleApplication2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int N;
int T[16];
int P[16];
int DP[16];
int result;
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
		if (T[i] + i <= N) DP[i] = P[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		for (int j = i + T[i]; j < N; j++) {
			DP[i] = max(DP[i], P[i] + DP[j]);
		}
		result = max(DP[i], result);
	}
	cout << result << endl;
}
