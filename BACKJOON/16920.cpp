#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define FOR(i, N) for(int i = 0; i < N; i++)
#define FOR1(i, N) for(int i = 1; i <= N; i++)
using ll = long long;
using namespace std;

int N, M, P;
int S[11];
bool visit[10][1001][1001];
vector<vector<char>> board;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int result[10];

int allCastle() {
	int total = 0;
	FOR1(i,P) total += result[i];
	return total;
}

bool checkRange(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < M;
}

void BFS(int playerIndex) {
	queue<pair<int, pair<int, int>>> Q;
	FOR(i, N) {
		FOR(j, M) {
			if (board[i][j] == '1' + playerIndex - 1) {
				Q.push({ 0, {i, j} });
				visit[playerIndex][i][j] = true;
			}
		}
	}

	while (!Q.empty()) {
		int dist = Q.front().first;
		int x = Q.front().second.first;
		int y = Q.front().second.second;
		Q.pop();
		if (dist == S[playerIndex]) continue;
		FOR(i, 4) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (checkRange(nx, ny) && !visit[playerIndex][nx][ny] && board[nx][ny] == '.' && board[nx][ny] != '#') {
				board[nx][ny] = '1' + playerIndex - 1;
				visit[playerIndex][nx][ny] = true;
				Q.push({ dist + 1, {nx, ny} });
				result[playerIndex]++;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M >> P;
	board.assign(N, vector<char>(M));
	FOR1(i, P) {
		cin >> S[i];
	}

	FOR(i, N) {
		string temp;
		cin >> temp;
		FOR(j, M) {
			board[i][j] = temp[j];
			if(temp[j] != '.' && board[i][j] != '#')result[temp[j] - '1'+1]++;
			
		}
	}
	bool isExpanding = true;
	while (isExpanding) {
		isExpanding = false;
		FOR1(i, P) {
			int beforeExpansion = result[i];
			BFS(i);
			if (result[i] > beforeExpansion) isExpanding = true;
		}
	}
	FOR1(i, P) cout << result[i] << " ";
}
