#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'

using namespace std;

int M, S;
int fishNow[5][5][8];
int fishNext[5][5][8];
int fishCopy[5][5][8];
int fishSmell[5][5];
int visitFish[5][5];
int shark[2];

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int sdx[4] = { 0,-1,0,1 };
int sdy[4] = { -1,0,1,0 };
void input() {
	cin >> M >> S;
	for (int i = 0; i < M; i++) {
		int x, y, d;
		cin >> y >> x >> d;
		d--;
		fishNow[y][x][d]++;
	}
	int x, y;
	cin >> y >> x;
	shark[0] = x;
	shark[1] = y;
}
void renewSmell(int bestMoveD) {
	//cout << "sasasasasa" << bestMoveD << endl;
	//cout << "qqqq" << shark[0]<<" "<<sdx[bestMoveD] << endl;
	int sharkBestMoveX = shark[0] + sdx[bestMoveD];

	int sharkBestMoveY = shark[1] + sdy[bestMoveD];
	if (sharkBestMoveX < 1 || sharkBestMoveY < 1 || sharkBestMoveX >5 || sharkBestMoveY>5) {
		return;
	}
	cout << "sharkmove" << sharkBestMoveX << " " << sharkBestMoveY << endl;
	for (int i = 0; i < 8; i++) {
		if (fishNow[sharkBestMoveY][sharkBestMoveX][i] != 0) {
			for (int d = 0; d < 8; d++) {
				fishNow[sharkBestMoveY][sharkBestMoveX][d] = 0;
				fishSmell[sharkBestMoveY][sharkBestMoveX] = 3;
			}
		}
	}
	shark[0] = sharkBestMoveX;
	shark[1] = sharkBestMoveY;
}
bool sharkCheckRange(int x, int y) {
	if (x >= 1 && y >= 1 && x < 5 && y < 5) return true;

	return false;
}
bool checkRange(int x,int y) {
	if (x >= 1 && y >= 1 && x < 5 && y < 5) {
		cout << "check" << " " << x << " " << y << endl;
		cout << shark[0] << " " << shark[1] << endl;
		if (x == shark[0] && y == shark[1]) return false;
		cout << "check" << " " << x << " " << y << endl;
		if (fishSmell[y][x] == 0)return true;

	}
	return false;
}

int eatFish(int x, int y) {
	int eatFishSum = 0;
	bool flag = 1;
	for (int i = 0; i < 8; i++) {
		if (fishNow[y][x][i] != 0 && visitFish[y][x] == 0) {
			//cout << "power" << endl;
			eatFishSum += fishNow[y][x][i];
			flag = 0;
		}
	}
	if (!flag) visitFish[y][x] = 1;
	return eatFishSum;
}
void visitFishClear() {
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 5; j++) {
			visitFish[i][j] = 0;
		}
	}
}
void move() {
	while (S--) {
		//cout << "start" << S << endl;
		cout << "시작 상어 현재 위치" << endl;
		for (int i = 1; i < 5; i++) { // fishNow를 fishNext로 변환
			for (int j = 1; j < 5; j++) {
				if (i == shark[1] && j == shark[0]) cout << "#" << " ";
				else cout << 0 << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << "시작 물고기 현재 위치" << endl;
		for (int i = 1; i < 5; i++) { // fishNow를 fishNext로 변환
			for (int j = 1; j < 5; j++) {
				int aa = 0;
				for (int d = 0; d < 8; d++) {
					aa += fishNow[i][j][d];
					 
				}
				cout << aa << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << "방향과 함께 제시" << endl;
		for (int i = 1; i < 5; i++) { // fishNow를 fishNext로 변환
			for (int j = 1; j < 5; j++) {
				bool flag = true;
				for (int d = 0; d < 8; d++) {
					if (fishNow[i][j][d] != 0) {
						flag = false;
						cout <<"d: "<< d<<" "<< fishNow[i][j][d];
					}
				}
				if (flag) cout << 0 << " ";
				else cout << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 1; i < 5; i++) { // 복사
			for (int j = 1; j < 5; j++) {
				for (int d = 0; d < 8; d++) {
					fishCopy[i][j][d] = fishNow[i][j][d];
				}
			}
		}
		for (int i = 1; i < 5; i++) { // 이동
			for (int j = 1; j < 5; j++) {
				for (int d = 0; d < 8; d++) {
					int fishD = d;
					int fishNum = fishNow[i][j][d];
					int x = j;
					int y = i;
					if (fishNum == 0) continue;
						for (int a = 0; a < 8; a++) {
							int nd = (d - a + 8) % 8;

							int nx = x + dx[nd];
							int ny = y + dy[nd];
							//cout << "nd : " << nd << " " << d << " " << a << " " << j << " " << i <<" "<<nx<<" "<<ny<< endl;
							if (checkRange(nx, ny)) { // 이동완료
								//cout << "nd : " << nd << " " << d << " " << a << " " << j << " " << i << endl;
								fishNext[ny][nx][nd] += fishNow[y][x][fishD];
								fishNow[y][x][fishD] = 0;
								break;
							}
							else {
								if (a == 7) { // 아예 못 움직였을 때
									fishNext[y][x][d] += fishNow[y][x][fishD];
									fishNow[y][x][fishD] = 0;
								}
							}
						}
					
					
				}
			}
		}
		cout << "이동만 후" << endl;
		for (int i = 1; i < 5; i++) { // fishNow를 fishNext로 변환
			for (int j = 1; j < 5; j++) {
				int aa = 0;
				for (int d = 0; d < 8; d++) {
					aa += fishNext[i][j][d];
				}
				cout << aa << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 1; i < 5; i++) { // fishNow를 fishNext로 변환
			for (int j = 1; j < 5; j++) {
				for (int d = 0; d < 8; d++) {
					fishNow[i][j][d] = fishNext[i][j][d];
					fishNext[i][j][d] = 0;
				}
			}
		}
		int bestMoveF;
		int bestMoveS;
		int bestMoveT;
		bool flag = true;
		int maxEat = 0;
		for (int i = 0; i < 4; i++) { // 상어 이동 4의 3중 for문
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					
					int sharkX = shark[0];
					int sharkY = shark[1];;
					//cout << "shakr : "<<sharkX << " " << sharkY << endl;
					int sharkFirstX = sharkX + sdx[i];
					int sharkFirstY = sharkY + sdy[i];
					int sharkSecondX = sharkFirstX + sdx[j];
					int sharkSecondY = sharkFirstY + sdy[j];
					int sharkThirdX = sharkSecondX + sdx[k];
					int sharkThirdY = sharkSecondY + sdy[k];
					int eatFishSum = 0;
					if (sharkCheckRange(sharkFirstX, sharkFirstY) && sharkCheckRange(sharkSecondX, sharkSecondY) && sharkCheckRange(sharkThirdX, sharkThirdY)) {

						eatFishSum += eatFish(sharkFirstX, sharkFirstY);
						eatFishSum += eatFish(sharkSecondX, sharkSecondY);
						eatFishSum += eatFish(sharkThirdX, sharkThirdY);
						if (flag) {
							bestMoveF = i;
							bestMoveS = j;
							bestMoveT = k;
							maxEat = eatFishSum;
							flag = false;
						}
						if (maxEat < eatFishSum) {
							bestMoveF = i;
							bestMoveS = j;
							bestMoveT = k;
							maxEat = eatFishSum;
						}
						visitFishClear();
					}
				}
			}
		}
		//cout << "best" << bestMoveF << " " << bestMoveS << " " << bestMoveT << endl;
		// 냄새 및 물고기 상태 갱신
		renewSmell(bestMoveF);
		renewSmell(bestMoveS);
		renewSmell(bestMoveT);
		// 베스트 움직임 갱신
		//int moveSharkX = shark[0] + sdx[bestMoveF] + sdx[bestMoveS] + sdx[bestMoveT];
		//int moveSharkY = shark[1] + sdy[bestMoveF] + sdy[bestMoveS] + sdy[bestMoveT];
		//shark[0] = moveSharkX;
		//shark[1] = moveSharkY;

		cout << "먹힌 후, 복제전" << endl;
		for (int i = 1; i < 5; i++) { // fishNow를 fishNext로 변환
			for (int j = 1; j < 5; j++) {
				int aa = 0;
				for (int d = 0; d < 8; d++) {
					aa += fishNow[i][j][d];

				}
				cout << aa << " ";
			}
			cout << endl;
		}
		cout << endl;
		// 냄새 제거 
		for (int i = 1; i < 5; i++) {
			for (int j = 1; j < 5; j++) {
				if (fishSmell[i][j] != 0) fishSmell[i][j]--;
			}
		}
		//fishCopy 완료
		for (int i = 1; i < 5; i++) { 
			for (int j = 1; j < 5; j++) {
				for (int d = 0; d < 8; d++) {
					fishNow[i][j][d] += fishCopy[i][j][d];
					fishCopy[i][j][d] = 0;
				}
			}
		}
		for (int i = 1; i < 5; i++) { // fishNow를 fishNext로 변환
			for (int j = 1; j < 5; j++) {
				if (i == shark[1] && j == shark[0]) cout << "#" << " ";
				else cout << 0 << " ";
			}
			cout << endl;
		}
		cout << "aaaaaaaaaaa" << endl;
		for (int i = 1; i < 5; i++) { // fishNow를 fishNext로 변환
			for (int j = 1; j < 5; j++) {
				int aa = 0;
				for (int d = 0; d < 8; d++) {
					aa += fishNow[i][j][d];
				}
				cout << aa << " ";
			}
			cout << endl;
		}
		cout << "smell" << endl;
		for (int i = 1; i < 5; i++) { // fishNow를 fishNext로 변환
			for (int j = 1; j < 5; j++) {
				cout << fishSmell[i][j] << " ";
			}
			cout << endl;
		}
	}
	int fishSumResult = 0;
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 5; j++) {
			for (int d = 0; d < 8; d++) {
				fishSumResult += fishNow[i][j][d];
			}
		}
	}

	cout << fishSumResult << endl;
}
void run() {
	input();
	move();
}
int main() {
	run();
}
