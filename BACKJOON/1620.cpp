#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef unsigned long long ull;

ull ref(ull A, ull B, ull C) {
	if (B == 0) return 1;
	if (B == 1) return A % C;
	ull temp = ref(A, B / 2, C);
	if (B % 2 == 0) return (temp * temp) % C;
	if (B % 2 == 1) return ((temp * temp) % C * A % C);
}

int main() {
	ios::sync_with_stdio;
	cin.tie(NULL);
	ull A, B, C;
	cin >> A >> B >> C;
	cout << ref(A, B, C);
}
