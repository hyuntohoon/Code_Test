#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> board;
vector<vector<bool>> combined;

void compress(vector<int> &line) {
	vector<int> newLine;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] != 0) {
			newLine.push_back(line[i]);
		}
	}
	newLine.resize(N, 0);
	line = newLine;
}

void combine(vector<int> &line) {
	for (int i = 0; i < N - 1; i++) {
		if (line[i] != 0 && line[i] == line[i + 1]) {
			line[i] *= 2;
			line[i + 1] = 0;
			compress(line); // Compress the line after combining
		}
	}
}

vector<vector<int>> moveBoard(int d, vector<vector<int>> curBoard) {
	// Rotate the board according to the direction
	vector<vector<int>> newBoard(N, vector<int>(N, 0));
	if (d == 0) { // Up
		for (int j = 0; j < N; j++) {
			vector<int> line;
			for (int i = 0; i < N; i++) line.push_back(curBoard[i][j]);
			compress(line);
			combine(line);
			for (int i = 0; i < N; i++) newBoard[i][j] = line[i];
		}
	}
	else if (d == 1) { // Right
		for (int i = 0; i < N; i++) {
			vector<int> line(curBoard[i].rbegin(), curBoard[i].rend());
			compress(line);
			combine(line);
			for (int j = 0; j < N; j++) newBoard[i][N - 1 - j] = line[j];
		}
	}
	else if (d == 2) { // Down
		for (int j = 0; j < N; j++) {
			vector<int> line;
			for (int i = N - 1; i >= 0; i--) line.push_back(curBoard[i][j]);
			compress(line);
			combine(line);
			for (int i = 0; i < N; i++) newBoard[N - 1 - i][j] = line[i];
		}
	}
	else if (d == 3) { // Left
		for (int i = 0; i < N; i++) {
			vector<int> line = curBoard[i];
			compress(line);
			combine(line);
			for (int j = 0; j < N; j++) newBoard[i][j] = line[j];
		}
	}
	return newBoard;
}

int getMaxBlock(const vector<vector<int>> &b) {
	int maxBlock = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			maxBlock = max(maxBlock, b[i][j]);
		}
	}
	return maxBlock;
}

int result = 0;
void go(vector<vector<int>> curBoard, int cnt) {
	if (cnt == 5) {
		result = max(result, getMaxBlock(curBoard));
		return;
	}
	for (int i = 0; i < 4; i++) {
		vector<vector<int>> newBoard = moveBoard(i, curBoard);
		go(newBoard, cnt + 1);
	}
}

int main() {
	cin >> N;
	board.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	go(board, 0);
	cout << result << endl;
	return 0;
}
