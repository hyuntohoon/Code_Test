package work;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_4013_특이한자석 {
	static class doRotate {
		int num, dir;

		public doRotate(int num, int dir) {
			this.num = num;
			this.dir = dir;
		}
	}

	static int[] Rotate(int[] tobni, int dir) {
		int[] tempTobni = new int[8];
		if (dir == 1) {
			for (int i = 1; i < 8; i++) {
				tempTobni[i] = tobni[i - 1];
			}
			tempTobni[0] = tobni[7];

		} else {
			for (int i = 6; i >= 0; i--) {
				tempTobni[i] = tobni[i + 1];
			}
			tempTobni[7] = tobni[0];
		}
		return tempTobni;
	}

	static int[][] go(int num, int dir, int[][] tobnis) {
		Queue<doRotate> Q = new LinkedList<>();
		Q.add(new doRotate(num, dir));
		int tempDir = dir;
		if (num == 0) {
			int nowDir = dir;
			if (tobnis[1][6] != tobnis[0][2]) {
				Q.add(new doRotate(1, nowDir*-1));
				nowDir*=-1;
				if (tobnis[1][2] != tobnis[2][6]) {
					Q.add(new doRotate(2, nowDir*-1));
					nowDir*=-1;
					if (tobnis[2][2] != tobnis[3][6]) {
						Q.add(new doRotate(3, nowDir*-1));
						nowDir*=-1;
					}
				}
			}
		} else if (num == 1) {
			dir = tempDir;
			if (tobnis[1][2] != tobnis[2][6]) {
				Q.add(new doRotate(2, dir*-1));
				dir*=-1;
				if (tobnis[2][2] != tobnis[3][6]) {
					Q.add(new doRotate(3, dir*-1));
					dir*=-1;
				}
			}
			dir = tempDir;
			if (tobnis[1][6] != tobnis[0][2]) {
				Q.add(new doRotate(0, dir*-1));
				dir*=-1;
			}
		} else if (num == 2) {
			dir = tempDir;
			if (tobnis[1][2] != tobnis[2][6]) {
				Q.add(new doRotate(1, dir*-1));
				dir*=-1;
				if (tobnis[1][6] != tobnis[0][2]) {
					Q.add(new doRotate(0, dir*-1));
					dir*=-1;
				}
			}
			dir = tempDir;
			if (tobnis[2][2] != tobnis[3][6]) {
				Q.add(new doRotate(3, dir*-1));
				dir*=-1;
			}
		} else if (num == 3) {
			dir = tempDir;
			if (tobnis[2][2] != tobnis[3][6]) {
				Q.add(new doRotate(2, dir*-1));
				dir*=-1;
				if (tobnis[1][2] != tobnis[2][6]) {
					Q.add(new doRotate(1, dir*-1));
					dir*=-1;
					if (tobnis[1][6] != tobnis[0][2]) {
						Q.add(new doRotate(0, dir*-1));
						dir*=-1;
					}
				}
			}
		}

		while (!Q.isEmpty()) {
			tobnis[Q.peek().num] = Rotate(tobnis[Q.peek().num], Q.peek().dir);
			Q.poll();
		}
		return tobnis;
	}
	static int calScore(int [][]tobnis) {
		int score = 0;
		if(tobnis[0][0] == 1) score +=1;
		if(tobnis[1][0] == 1) score +=2;
		if(tobnis[2][0] == 1) score +=4;
		if(tobnis[3][0] == 1) score +=8;
		return score;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			int K = Integer.parseInt(br.readLine());
			int[][] tobnis = new int[4][8];
			for (int i = 0; i < 4; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < 8; j++) {
					tobnis[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			int ans = 0;
			for (int i = 0; i < K; i++) {
				st = new StringTokenizer(br.readLine());
				int numTobni = Integer.parseInt(st.nextToken()) - 1;
				int dirTobni = Integer.parseInt(st.nextToken());
				go(numTobni, dirTobni, tobnis);
			}
			ans += calScore(tobnis);
			System.out.println("#"+t+" "+ans);
		}
	}
}
