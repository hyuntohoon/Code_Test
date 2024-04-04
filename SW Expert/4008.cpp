#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring> // memset을 사용하기 위해 추가
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

bool visit[13]; // 연산자 최대 개수에 맞춘 방문 배열
int maxAns;
int minAns;
int ops[4];
int N;
void go(int cnt, int nowSum, vector<int> &V) {
	if (cnt == N-1) {
		maxAns = max(nowSum, maxAns);
		minAns = min(nowSum, minAns);
		return;
	}
	FOR(i, 4) {
		if(ops[i] == 0) continue;
		ops[i]--;
		if (i == 0) go(cnt+1, nowSum+V[cnt+1], V);
		if (i == 1)  go(cnt + 1, nowSum - V[cnt+1], V);
		if (i == 2)  go(cnt + 1, nowSum * V[cnt+1], V);
		if (i == 3) go(cnt + 1, nowSum / V[cnt+1], V);
		ops[i]++;
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		vector<char> box;
		vector<int> V;
		maxAns = -987654321;
		minAns = 987654321;
		memset(visit, 0, sizeof(visit));

		FOR(i, 4) {
			cin>>ops[i];
		}

		FOR(i, N) {
			int temp;
			cin >> temp;
			V.push_back(temp);
		}

		go(0,V[0],V);
		cout<<maxAns<<" "<<minAns<<endl;
		cout << "#" << t << " " << maxAns - minAns << endl;
	}
}
