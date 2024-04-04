#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<n;i++)
using ll = long long;

vector<vector<int>> V(10, vector<int>(10, 0));

bool check() {
	FOR(i, 10) {
		FOR(j, 10) {
			if(V[i][j] == 1) return false;
		}
	}
	return true;
}
int ans = 987654321;
int paper[6] = { 0,5,5,5,5,5 };
bool isVaild(int x, int y, int k) {
	if (x + k > 10 || y + k > 10) return false;
	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			if(V[i][j] == 0) return false;
		}
	}
	return true;
}

bool setPaper(int x, int y, int k, bool f) {
	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			V[i][j] =f;
		}
	}
	return true;
}
void go(int cnt) {
	if(cnt >=ans) return;
	if (check()) {
		ans = min(ans,cnt);
	}
	FOR(i, 10) {
		FOR(j, 10) {
			if (V[i][j] == 1) {
				for (int k = 5; k >= 1; k--) {
					if (isVaild(i, j, k) && paper[k] > 0) {
						setPaper(i,j,k,0);
						paper[k]--;
						go(cnt+1);
						paper[k]++;
						setPaper(i, j, k, 1);
					}
				}
				return;
			}
		}
	}
}

int main() {
	FOR(i, 10) {
		FOR(j, 10) {
			cin>>V[i][j];
		}
	}
	go(0);
	cout<<(ans==987654321 ? -1 : ans);
}
