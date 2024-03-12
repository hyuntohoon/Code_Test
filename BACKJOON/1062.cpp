#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int N, K;
set<char> S[55];
bool visit[55];
int ans;
int readWord() {
	int result = 0;
	FOR(i, N) {
		int cnt = 0;
		int temp = S[i].size();
		for (auto elem : S[i]) {
			if(elem == 'a'||elem =='n' || elem =='t'||elem =='i' || elem =='c') {
				temp--;
				continue;
			}
			if (visit[elem-'a'] == 1) temp--;
		}
		if(temp <=0) result++;
	}
	return result;
}

void go(int cnt, int start) {
	if (cnt == K-5) {
		ans = max(readWord(), ans);
		return;
	}

	for (int i = start; i < 26; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			go(cnt+1, i+1);
			visit[i] = 0;
		}
	}
}
int main() {

	cin>>N>>K;
	string temp[51];
	FOR(i, N) {
		cin>>temp[i];
		FOR(j,temp[i].size()){
			S[i].insert(temp[i][j]);
		}
	}
	if(K<5) {
		cout<<0; 
		return 0;
	}
	visit['a' - 'a'] = 1;
	visit['n' - 'a'] = 1;
	visit['t' - 'a'] = 1;
	visit['i' - 'a'] = 1;
	visit['c' - 'a'] = 1;
	go(0,0);
	cout<<ans<<endl;
}
