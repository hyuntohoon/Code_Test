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
ll result = 987654321;
ll A, B;
void go(ll now, ll count) {
	//cout << now << " " << count << endl;
	if (now > B) return;
	if (count > result) return;
	if (now == B) result = min(result, count);
	go(now * 2, count+1);
	go(now * 10 + 1, count+1);

}
int main() {
	cin >> A >> B;

	go(A, 0);
	if (result == 987654321) cout << -1;
	else cout << result+1;

}
