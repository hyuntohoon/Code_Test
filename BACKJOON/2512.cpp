

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<n;i++)
using ll = long long;

using namespace std;

ll N, M;
ll arr[10001];

ll endVal = 0;

ll preMax = 0;

ll cal(ll mid) {
	ll result = 0;
	FOR(i, N) {
		if (mid < arr[i]) {
			result += mid;
		}
		else {
			result +=arr[i];
		}
	}
	return result;
}

int main()
{
	cin>>N;
	ll start = 1;
	FOR(i, N) {
		cin>>arr[i];
		endVal = max(arr[i], endVal);
	}
	cin>>M;
	ll result = 1;
	ll ans = 1;
	ll mid = (start + endVal) / 2;

	while (start<=endVal) {
		mid = (start + endVal) /2;
		ll nowMax = cal(mid);
		if (nowMax == M) {
			cout<<mid<<endl;
			return 0;
		}
		if (result < nowMax && nowMax <= M) {
			result = nowMax;
			ans = mid;
		}
		if (nowMax < M) {
			start = mid+1;
		}
		else {
			endVal = mid -1;
		}
	}
	cout<<ans;
}

