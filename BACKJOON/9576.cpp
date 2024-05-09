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
	int T;
	cin>>T;
	FOR(t,T){
	int N,M;
	cin>>N>>M;
	priority_queue<pair<int,int>> pq;
	FOR(i, M) {
		int a,b;
		cin>>a>>b;
		pq.push({-b,-a});
	}
	bool visit[1001] ={0,};
	int count = 0;
	while (!pq.empty()) {
		int a = -pq.top().second;
		int b = -pq.top().first;
		pq.pop();
		for (int i = a; i <= b; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				count++;
				break;
			}
		}
	}
	cout<<count<<endl;
}
}
