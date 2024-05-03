#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define FOR(i,N) for(int i = 0;i<N;i++)
#define FOR1(i,N) for(int i = 1;i<N;i++)
using ll = long long;
using namespace std;

int main() {
	priority_queue<int,vector<int>,greater<int>> pq;
	vector<pair<int,int>> V;
	int N;
	cin>>N;
	FOR(i, N) {
		int p,d;
		cin>>p>>d;
		V.push_back({d,p});
	}
	sort(V.begin(), V.end());
	int value = 0;
	for (auto elem : V) {
		pq.push(elem.second);
		if (elem.first < pq.size()) {
			pq.pop();
		}
	}
	// 만약 pq의 사이즈 보다 day가 작거나 같은 경우 여석을 줄인다.
	// 여석은 size가 커질 때 마다 day가 여석보다 큰 경우 추가한다.

	while (!pq.empty()) {
		value+=pq.top();
		pq.pop();
	}
	cout << value;
}
