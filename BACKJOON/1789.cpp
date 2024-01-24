#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;
long long S;
long long temp_S;
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> S;
}
int go() {
	long long mid = S/2;
	temp_S = S;
	if (S == 1) return 1;
	while (true) {
		if((mid * (mid + 1)) / 2 == S) return mid;
		if ((temp_S - mid == 1) && ((mid * (mid + 1)) / 2 < S)) return mid;
		if ((mid * (mid+1)) / 2 > S) {
			temp_S = mid;
			mid = temp_S / 2; 
		}
		if ((mid * (mid + 1)) / 2 < S) mid = (temp_S + mid) / 2;
	}
	return 0;
}
void solve() {
	input();
	cout<<go();
}
int main() {
	solve();

}
