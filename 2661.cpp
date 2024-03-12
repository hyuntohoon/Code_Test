#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int N;
vector <int> V;
bool flag;
bool check() {
	int n = V.size()/2;
	for (int i = 1; i <= n; i++) {
		vector <int> F;
		vector <int> E;
		FOR(j, i) {
			E.push_back(V[V.size()-j-1]);
		}FOR(j, i) {
			F.push_back(V[V.size()- i - j-1]);
		}
		if(E == F) return false;
	}
	return true;
}
void go(int cnt) {
	if(flag == 1) return;
	if (N == cnt) {
		for(auto elem : V) cout<<elem;
		flag = 1;
		return;
	}
	for (int i = 1; i < 4; i++) {
		V.push_back(i);
		if (check()) {
			go(cnt+1);
			if(flag) return;
		}
		V.pop_back();
	}
}
int main() {
	cin>>N;
	go(0);
}
