// ConsoleApplication7.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#define FOR(i,n) for(int i =0;i<n;i++)
using ll = long long;
using namespace std;
int N, S;
vector<int> V;
map<int,int> subsum;
ll result = 0;
void go1(int cnt, int sum) {
	if(cnt==N/2){
		subsum[sum]++;
		return;
	}
	go1(cnt+1,sum+V[cnt]);
	go1(cnt+1,sum);
}
void go2(int cnt, int sum) {
	if (cnt == N) {
		result +=subsum[S-sum];
		return;
	}
	go2(cnt + 1, sum + V[cnt]);
	go2(cnt + 1, sum);
}
int main()
{
	cin>>N>>S;
	FOR(i, N) {
		int temp;
		cin>> temp;
		V.push_back(temp);
	}
	go1(0,0);
	go2(N/2,0);
	if(S==0) result--;
	cout<<result<<endl;
}
