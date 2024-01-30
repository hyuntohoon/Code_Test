#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ll N, B, C;
ll arr[1000001];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> B >> C;
	ll count = 0;
	for (int i = 0; i < N; i++) {
		ll temp = arr[i];

		temp -= B;
		count++;
		//cout << 1 << " ";
		if (temp <= 0) continue;
		int tempCount = (temp / C);
		if (temp % C > 0) tempCount++;
		count += tempCount;
		//cout <<tempCount << endl;
	}
	cout << count << endl;
}
