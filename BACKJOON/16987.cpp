#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

int N;
int broken[301];
vector<pair<int,int>> egg;
int result = 0;
void go(int start) {
	if (start >= N) {
		int cnt= 0;
		for (auto elem : egg) {
			if(elem.first <=0) cnt++;
		}
		result = max(result, cnt);
		return;
	}
	int nowEggDura = egg[start].first;
	int nowEggWeight = egg[start].second;
	if(nowEggDura <= 0) {
		go(start+1);
	}
	else {
		for (int i = 0; i < N; i++) {
			if (i == start || egg[i].first <= 0) continue;
			int selEggDura = egg[i].first;
			int selEggweight = egg[i].second;
			egg[start].first = egg[start].first - egg[i].second;
			egg[i].first = egg[i].first - egg[start].second;
			go(start + 1);
			egg[start].first = nowEggDura;
			egg[i].first = selEggDura;

		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin>>N;
	FOR(i, N) {
		int dura, weight;
		cin>>dura>>weight;
		egg.push_back(make_pair(dura, weight));
	}
	go(0);
	cout<<result<<endl;
}

