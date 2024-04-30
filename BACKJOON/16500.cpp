#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
#define FOR(i,N) for(int i =0;i<N;i++)
#define FOR1(i,N) for(int i =1;i<N;i++)
using namespace std;

string S;
vector<string> A;
unordered_map<int, bool> memo;

bool check(int start) {
	if (start == S.size()) {
		return true;  
	}
	if (memo.count(start)) {
		return memo[start];  
	}

	for (const auto& elem : A) {
		int next_start = start + elem.size();
		if (next_start <= S.size() && S.substr(start, elem.size()) == elem) {
			if (check(next_start)) {
				return memo[start] = true;
			}
		}
	}
	return memo[start] = false; 
	}
int main() {
	cin >> S;
	int N;
	cin >> N;
	FOR(i, N) {
		string temp;
		cin >> temp;
		A.push_back(temp);
	}

	int result = 0;
	result = check(0) ? 1 : 0; 

	cout << result << endl;
	return 0;
}
