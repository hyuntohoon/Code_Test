#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef unsigned long long ull;

int N;
int arr[11][11];
bool visited[11][11];
int result = 987654321;
bool rangeCheck(int x, int y) {
	if (x > 0 && y > 0 && x < N && y < N) return true;
	return false;
}

bool checkVisited(int x, int y) {
	if (visited[y - 1][x] == 0 && visited[y + 1][x] == 0 && visited[y][x - 1] == 0 && visited[y][x + 1] == 0) return true;
	return false;
}
void setVisited(int x, int y, int value) {
	visited[y][x] = value;
	visited[y-1][x] = value;
	visited[y+1][x] = value;
	visited[y][x-1] = value;
	visited[y][x+1] = value;
}
int sumCost(int x, int y) {
	int tempSum = 0;
	tempSum += arr[y][x];
	tempSum += arr[y - 1][x];
	tempSum += arr[y + 1][x];
	tempSum += arr[y][x - 1];
	tempSum += arr[y][x + 1];
	return tempSum;
}
void DFS(int count, int sum) {
	if (count == 3) { result = min(result, sum); return; }
	for (int i = 1; i < N-1; i++) {
		for (int j = 1; j < N-1; j++) {
			if (rangeCheck(j, i) && checkVisited(j, i)) {
				setVisited(j, i, 1);
				int nowSum = sumCost(j, i);
				DFS(count + 1, sum + nowSum);
				setVisited(j, i, 0);
			}
		}
	}
}
int main() {
	cin >> N;
	ios::sync_with_stdio;
	cin.tie(NULL);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	DFS(0, 0);
	cout << result << endl;
}
