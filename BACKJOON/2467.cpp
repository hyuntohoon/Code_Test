#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FOR(i,N) for(int i = 0;i<N;i++)
#define FOR1(i,N) for(int i = 1;i<N;i++)
using ll = long long;
using namespace std;

int main() {
	int N;
	cin>>N;
	vector<ll> V(N+1);
	V[0] = -9876543211;
	FOR1(i, N+1) {
		cin>>V[i];
	}
	ll ans = 9876543211;
	pair<ll,ll> ansP;
	FOR1(i,N+1){
		ll elem = V[i];
		elem *= -1;
		int left = 1;
		int right = V.size()-1;
		int mid;
		while (true) {
			mid = (right + left) / 2;
			if (left >= right) {
				break;
			}
			if (V[mid] < elem) {
				left = mid+1;
			}
			else {
				right = mid-1;
			}
		}
		for (int j = max(1, mid - 1); j <= min(N, mid + 1); j++) {
			if (j != i && abs(V[j] - elem) < ans) {
				ans = abs(V[j] - elem);
				ansP.first = min(V[j], elem * -1);
				ansP.second = max(V[j], elem * -1);
			}
		}
	}
	cout<<ansP.first<<" "<<ansP.second<<endl;
}
