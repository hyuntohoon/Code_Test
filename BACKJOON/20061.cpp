#include<iostream>

using namespace std;

int N;
int arr[10][10];
int result = 0;
int slot;
void move(int t,int sx,int sy) {
	int Gsy = sy;
	int Gsx = sx;
	int Ssy = sy;
	int Ssx = sx;
	while (true) {
		if (Gsx == 11) break;
		if (t == 1) {
			if (arr[Gsy][Gsx] != 0 || Gsx == 10) {
				arr[Gsy][Gsx - 1] = 1;
				break;
			}
			Gsx++;
		}
		if (t == 2) {
			if (arr[Gsy][Gsx + 1] != 0 || Gsx == 9) {
				arr[Gsy][Gsx - 1] = 1;
				arr[Gsy][Gsx] = 1;
				break;
			}
			Gsx++;
		}
		if (t == 3) {
			if (arr[Gsy][Gsx] != 0 || arr[Gsy+1][Gsx] != 0 || Gsx == 10) {
				arr[Gsy][Gsx - 1] = 1;
				arr[Gsy+1][Gsx - 1] = 1;
				break;
			}
			Gsx++;
		}
	}

	while (true) {
		if (Ssy == 11) break;
		if (t == 1) {
			if (arr[Ssy][Ssx] != 0 || Ssy == 10) {
				arr[Ssy -1][Ssx] = 1;
				break;
			}
			Ssy++;
		}
		if (t == 2) {
			if (arr[Ssy][Ssx] != 0 || arr[Ssy][Ssx +1] != 0 || Ssy == 10) {
				arr[Ssy -1][Ssx] = 1;
				arr[Ssy -1][Ssx +1] = 1;
				break;
			}
			Ssy++;
		}
		if (t == 3) {
			if (arr[Ssy +1][Ssx] != 0 || Ssy == 9) {
				arr[Ssy -1][Ssx] = 1;
				arr[Ssy][Ssx] = 1;
				break;
			}
			Ssy++;
		}
	}
}

void moveOneSero(int y) {
	for (int i = 0; i < 4; i++) {
		arr[y][i] = 0;
	}
	for (int i = y; i > 0; i--) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = arr[i - 1][j];
		}
	}
}

void moveOneGaro(int x) {
	for (int i = 0; i < 4; i++) {
		arr[i][x] = 0;
	}
	for (int i = x; i > 0; i--) {
		for (int j = 0; j < 4; j++) {
			arr[j][i] = arr[j][i-1];
		}
	}
}
void checkZeroOne() {
	for (int j = 0; j < 4; j++) {
		if (arr[j][5] == 1) {
			moveOneGaro(9);

		}
	}
	for (int j = 0; j < 4; j++) {
		if (arr[j][5] == 1) {
			moveOneGaro(9);

		}
	}
	for (int j = 0; j < 4; j++) {
		if (arr[j][5] == 1) {
			moveOneSero(9);
		}
	}
	for (int j = 0; j < 4; j++) {
		if (arr[j][5] == 1) {
			moveOneSero(9);
		}
	}
}
int checkScore() {
	int sum = 0;
	for (int i = 9; i >= 5; --i) {
		bool flag = 1;
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			sum++;
			moveOneSero(i);
			i++;
		}
	}
	for (int i = 9; i >= 5; --i) {
		bool flag = 1;
		for (int j = 0; j < 4; j++) {
			if (arr[j][i] == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			sum++;
			moveOneGaro(i);
			i++;
		}
	}
	return sum;
}
void input() {
	int t, sx, sy;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t >> sy >> sx;
		move(t, sx, sy);
		result += checkScore();
		checkZeroOne();
	}
	for (int j = 0; j < 10; j++) {
		for (int o = 0; o < 10; o++) {
			if (arr[j][o] == 1) slot++;
		}
	}
}
void run() {
	input();
	cout << result << endl;
	cout << slot << endl;
}


int main() {
	run();
}
