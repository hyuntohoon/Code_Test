#include<iostream>
#include <queue>
#include <algorithm>
#define FOR(i,n) for(int i =0;i<n;i++)
using namespace std;

int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int N;
int map[16][16];
int visit[16];
int result = 0;

bool isVaild(int cnt) {
	FOR(i, cnt) {
		if(visit[i] == visit[cnt] || abs(visit[i]-visit[cnt]) == cnt-i) return false;
	}
	return true;
}
void go(int cnt) {
	if (cnt == N) {
		result++;
		return;
	}
	FOR(i, N) {
		visit[cnt] = i;
		if(isVaild(cnt)) go(cnt+1);
	}
}
int main() {
	cin>>N;
	go(0);
	cout<<result<<endl;
}
