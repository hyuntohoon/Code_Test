#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring> // memset 함수 사용
#define FOR(i,n) for(int i =0;i<n;i++)
using namespace std;
using ll = long long;

ll result = 0;
ll N;
void go(ll n, ll cnt, string temp) {
	if (n == cnt) {
		result++;
		//cout<<temp<<endl;
		if (result == N+1) {
			cout << temp << endl;
			exit(0); // 프로그램 종료
		}
		return;
	}
	for (ll i = 0; i < 10; i++) {
		if (cnt == 0 ||temp[cnt - 1] - '0' > i) {
			temp.push_back(i+'0');
			go(n, cnt + 1, temp);
			temp.pop_back();
		}
	}
}

int main() {

	cin>>N;
	for (ll i = 1; i < 11; i++) {
		go(i,0,"");
	}
	if (N == 0) {
		cout << 0 << endl;
		exit(0);
	}
	cout<<-1<<endl;
}
