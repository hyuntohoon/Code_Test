// ConsoleApplication11.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <set>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N, K;
		cin >> N >> K;
		string temp;
		cin >> temp;
		int start = 0;
		int digit = N / 4;
		set <int, greater<int>> S;
		for (int rotate = 0; rotate < digit; rotate++) {
			for (int i = 0; i < 4; i++) { // 나누기
				string aa = temp.substr(start + i * (N / 4), N / 4);
				int aaValue = 0;
				int start = 0;
				for (int i = digit; i > 0; i--) {
					int intChar = (int)aa[start];
					if (65 <= intChar && intChar <= 70) {
						intChar -= 55;
					}
					else intChar -= 48;
					aaValue += intChar * pow(16, i-1);
					start++;
				}
				S.insert(aaValue);
				//cout << aa << " ";
			}
			cout << endl;
			char a = temp.back();
			temp.insert(temp.begin(), a);
			temp.pop_back();
		}
		auto iter = S.begin();
		FOR(i, K-1) iter++;

		cout << "#"<<t<<" "<<*iter << endl;
	}

}
