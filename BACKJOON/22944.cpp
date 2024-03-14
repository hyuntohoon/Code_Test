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
int N, H, D;
pair <int, int> S;
pair <int, int> E;
char map[501][501];
vector <pair<int, int>> U;
bool visit[11];
vector <int> order;
int result = 987654321;

int ordercal() {
	int disSum = 0;
	int nowHp = H;
	int nowU = 0;
	int nowX = S.first;
	int nowY = S.second;
	FOR(i, order.size()) { // 시작부터 우산까지
		pair<int, int> nowStart = { nowX, nowY };
		pair<int, int> nowEnd = U[order[i]];
		int distance = abs(nowStart.first - nowEnd.first) + abs(nowStart.second - nowEnd.second);
		disSum += distance; // 거리 합 더하기
		distance--; // 우산 도착 시는 비를 바로 안 맞기 때문에 거리의 -1만큼 hp 감소
		if (nowU > 0) { // 우산까지 가는 거리를 계산
			int temp = distance;
			distance = distance - nowU;
			nowU -= temp;
			if (nowU < 0) nowU = 0;
			if (distance < 0) distance = 0;
		}
		nowHp -= distance;
		if (nowHp <= 0) return 987654321; //여기 디버깅시 유의
		nowU = D; // 우산에 도착했기 때문에 우산 쓰면서 1만큼 감소
		nowX = nowEnd.first;
		nowY = nowEnd.second;
	}
	int distance = abs(nowX - E.first) + abs(nowY - E.second);
	disSum += distance; // 거리 합 더하기
	// 우산 도착 시는 비를 바로 안 맞기 때문에 거리의 -1만큼 hp 감소
	if (nowU > 0) { // 우산까지 가는 거리를 계산
		int temp = distance;
		distance = distance - nowU;
		nowU -= temp;
		if (nowU < 0) nowU = 0;
		if (distance < 0) distance = 0;
	}
	nowHp -= distance;
	if (nowHp <= 0) return 987654321; //여기 디버깅시 유의

	return disSum;
}
void DFS(int cnt) {
	if (cnt > U.size()) {
		return;
	}
	result = min(result, ordercal());
	for (int i = 0; i < U.size(); i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			order.push_back(i);
			DFS(cnt + 1);
			visit[i] = 0;
			order.pop_back();
		}
	}
}
int main() {
	cin >> N >> H >> D;
	FOR(i, N) {
		string temp;
		cin >> temp;
		FOR(j, N) {
			char a = temp[j];
			map[i][j] = a;
			if (a == 'S') {
				S = { i,j };
			}
			else if (a == 'U') {
				U.push_back({ i,j });
			}
			else if (a == 'E') {
				E = { i,j };
			}
		}
	}

		DFS(0);
		if (result != 987654321) {
			cout << result;
			return 0;
		}
	
	cout << -1;
	return 0;
}
