#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define FOR(i,n) for(int i=0;i<n;i++)
using ll = long long;

using namespace std;

int N, M;
int arr[100001];
string name[100001];
vector<pair<string, int>> V;

string binary(int target) {

	int mid;
	int low = 0;
	int high = N - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] < target) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return name[low];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	FOR(i, N) {
		string tempS;
		int temp;
		cin >> tempS >> temp;
		arr[i] = temp;
		name[i] = tempS;
	}
	int startIndex = 0;
	int endIndex = M;
	int vIndex = 0;
	FOR(i, M) {
		int temp;
		cin >> temp;
		cout << binary(temp) << "\n";
	}
}
