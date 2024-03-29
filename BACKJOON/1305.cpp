// ConsoleApplication7.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#define FOR(i,n) for(int i =0;i<n;i++)
using ll = long long;
using namespace std;

vector <int> makeLPS(string& S) {
	int i = 1;
	int length = 0;
	int M = S.size();
	vector <int> lps(M, 0);
	while (i < M) {
		if (S[i] == S[length]) {
			length++;
			lps[i] = length;
			i++;
		}
		else {
			if (length != 0) {
				length = lps[length - 1];
			}
			else { // length가 0이면 하나도 안 같은 경우
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}



int main() {
	int L;
	string S;
	cin >> L >> S;
	vector<int> lps = makeLPS(S);
	int result = 0;
	cout<<L-lps[L-1]<<endl;
}
