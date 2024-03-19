#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stdio.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int N;
int arr[12];
vector <char> OP;
vector <char> orderOP;
bool visit[45];
int maxResult = -987654321;
int minResult = 987654321;
int plusCnt, minusCnt, mulCnt, divCnt;
set <string> S;
int cal(string temp) {
	int nowVal = arr[0];
	int nowIndex = 1;

	for (int i = 0; i < temp.length(); i++) {
		if(temp[i] == '+'){
			nowVal +=arr[nowIndex];
		}
		else if (temp[i] == '-') {
			nowVal -= arr[nowIndex];
		}
		else if (temp[i] == '*') {
			nowVal *= arr[nowIndex];
		}
		else if (temp[i] == '/') {
			nowVal /= arr[nowIndex];
		}
		nowIndex++;
	}
	return nowVal;
}

void go(int cnt,int nowPlus, int nowMinus, int nowMul, int nowDiv, int nowVal) {
	if (N-1 == cnt) {
		//cout<<nowPlus<<" "<<nowMinus<<" "<<nowMul<<" "<<nowDiv<<" "<<nowVal<<endl;
		maxResult =max(nowVal, maxResult);
		minResult = min(nowVal, minResult);
		return;
	}
	if (nowPlus < plusCnt) {
		go(cnt+1, nowPlus+1, nowMinus, nowMul, nowDiv, nowVal + arr[cnt + 1]); // 현재 추가 값 적기
	}
	if (nowMinus < minusCnt) {
		go(cnt + 1, nowPlus, nowMinus+1, nowMul, nowDiv, nowVal - arr[cnt + 1]); // 현재 추가 값 적기
	}
	if (nowMul < mulCnt) {
		go(cnt + 1, nowPlus, nowMinus, nowMul+1, nowDiv, nowVal * arr[cnt + 1]); // 현재 추가 값 적기
	}
	if (nowDiv < divCnt) {
		go(cnt + 1, nowPlus, nowMinus, nowMul, nowDiv+1, nowVal / arr[cnt+1]); // 현재 추가 값 적기
	}
}
int main() {
	cin>>N;
	FOR(i, N) {
		cin>>arr[i];
	}
	
	cin>>plusCnt>> minusCnt >> mulCnt >>divCnt;
	FOR(i,plusCnt) OP.push_back('+');
	FOR(i, minusCnt) OP.push_back('-');
	FOR(i, mulCnt) OP.push_back('*');
	FOR(i, divCnt) OP.push_back('/');

	go(0,0,0,0,0,arr[0]);
	for (auto elem : S) {
		int nowVal = cal(elem);
		maxResult = max(maxResult, nowVal);
		minResult = min(minResult, nowVal);
	}
	cout<< maxResult<<endl;
	cout<<minResult<<endl;
}
