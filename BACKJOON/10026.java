package day20;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_10026 {
	static int N;
	static int[] dx = { 0, 0, -1, 1 };
	static int[] dy = { 1, -1, 0, 0 };
	static char[][] board;
	static boolean[][] visit;
	static char[][] redGreenBoard;
	static boolean[][] redGreenVisit;

	static void DFS(int x, int y) {

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && ny >= 0 && ny < N && nx < N) {
				if (board[x][y] == board[nx][ny] && visit[nx][ny] == false) {
					visit[nx][ny] = true;
					DFS(nx, ny);
				}
			}
		}
	}

	static void redGreenDFS(int x, int y) {
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && ny >= 0 && ny < N && nx < N && redGreenVisit[nx][ny] == false) {
				if (redGreenBoard[x][y] == 'G' && (redGreenBoard[nx][ny] == 'R' || redGreenBoard[nx][ny] == 'G')) {
					redGreenVisit[nx][ny] = true;
					redGreenDFS(nx, ny);
				} else if (redGreenBoard[x][y] == 'R'
						&& (redGreenBoard[nx][ny] == 'R' || redGreenBoard[nx][ny] == 'G')) {
					redGreenVisit[nx][ny] = true;
					redGreenDFS(nx, ny);
				} else if (redGreenBoard[x][y] == redGreenBoard[nx][ny]) {
					redGreenVisit[nx][ny] = true;
					redGreenDFS(nx, ny);
				}
			}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		board = new char[N][N];
		visit = new boolean[N][N];
		redGreenBoard = new char[N][N];
		redGreenVisit = new boolean[N][N];
		for (int i = 0; i < N; i++) {
			String temp = br.readLine();
			for (int j = 0; j < N; j++) {
				board[i][j] = temp.charAt(j);
				redGreenBoard[i][j] = temp.charAt(j);
			}
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == false) {
					cnt++;
					DFS(i, j);
				}
			}
		}

		int redGreenCnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (redGreenVisit[i][j] == false) {
					redGreenCnt++;
					redGreenDFS(i, j);
				}
			}
		}
		System.out.println(cnt + " " + redGreenCnt);
	}
}
