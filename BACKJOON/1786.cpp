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

vector <int> makeLPS(string& P) {
	int length = 0;
	int i = 1;
	int M =P.size();
	vector<int> lps(M,0);
	while (i < M) {
		if(P[i] == P[length]){ // 접두사와 접미사가 같은 경우
			length++; // 길이를 늘려서 비교해본다.
			lps[i] = length; // 원래 기본 값이 0이기 때문에 더하고 추가한다.
			i++; // 현재 해당하는 i를 늘린다.
		}
		else {
			if (length != 0) { // 접두사와 접미사가 1개 이상이였다가 달라진 경우
				length = lps[length-1]; // 이 경우 해당 length만큼은 검사를 했고, 실패를 했기 때문에
									// 해당 경우보다 작은 경우 length-1만큼 다시 참조하여 비교해본다.
			}
			else { //접두사와 접미사가 하나도 일치하지 않는 경우
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}
int cnt;
vector <int> findIndex;
void KMPSearch(string& T, string& P, vector <int> lps) {
	int N = T.size();
	int M = P.size();
	int i=0;
	int j =0;
	bool flag = 0;
	int startIndex;
	while (i < N) {
		if (P[j] == T[i]) {
			j++;
			i++;
		}
		if (j == M) {
			cnt++;
			j = lps[j - 1];
			findIndex.push_back(i-M+1);
		}
		else if (i < N && P[j] != T[i]) { // i가 N보다 작은 경우는 끝이 안 난 경우, P와 T가 다른 경우는
			if(j != 0) j = lps[j-1]; // 한번이라도 일치한 경우는 j의 이전수의 lps만큼 j를 가져온다.
			else i++; // 한번도 일치 안 한 경우
		}
	}
}

int main() {
	string T, P;
	getline(cin, T);
	getline(cin,P);	
	vector <int> lps = makeLPS(P);
	KMPSearch(T,P,lps);
	cout<<cnt<<endl;
	for (auto elem : findIndex) {
		cout<<elem<<" ";
	}
}
