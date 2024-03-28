package work;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main_1194 {
	static int N;
	static int M;
	static char[][] board;
	static int dx[] = { 0, 0, 1, -1 };
	static int dy[] = { 1, -1, 0, 0 };
	static boolean[][][] visit;

	static class minsik {
		int x;
		int y;
		int key;
		int nowMove;

		public minsik(int x, int y, int key, int nowMove) {
			super();
			this.x = x;
			this.y = y;
			this.key = key;
			this.nowMove = nowMove;
		}
	}

	static int BFS(int startX, int startY) {
		Queue<minsik> Q = new ArrayDeque<>();
		Q.add(new minsik(startX, startY, 0, 0));
		while (!Q.isEmpty()) {
			int x = Q.peek().x;
			int y = Q.peek().y;
			int key = Q.peek().key;
			int nowMove = Q.peek().nowMove;
			Q.poll();
			if(board[x][y] == '1') return nowMove;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
					if (visit[nx][ny][key] == false) {
						if (board[nx][ny] == '.' || board[nx][ny] == '1') {
							visit[nx][ny][key] = true;
							Q.add(new minsik(nx, ny, key, nowMove + 1));
						} else if ('a' <= board[nx][ny] && board[nx][ny] <= 'f') {
							int nKey = key | (1 << (board[nx][ny] - 'a'));
							visit[nx][ny][nKey] = true;
							Q.add(new minsik(nx, ny, nKey, nowMove + 1));
						} else if ('A' <= board[nx][ny] && board[nx][ny] <= 'F') {
							int nKey = key | (1 << (board[nx][ny] - 'a'));
							if ((key & (1 << (board[nx][ny] - 'A'))) != 0) {
								visit[nx][ny][nKey] = true;
								Q.add(new minsik(nx, ny, nKey, nowMove + 1));
							}
						}
					}
				}
			}
		}
		return -1;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String str = in.readLine();
		StringTokenizer st = new StringTokenizer(str);
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		board = new char[N+1][M+1];
		visit = new boolean[N+1][M+1][64];
		for(int i=0;i<N;i++) {
			for(int j =0;j<M;j++) {
				for(int k=0;k<64;k++) {
					visit[i][j][k] = false;
				}
			}
		}

		int []start = new int[2];
		for (int i = 0; i < N; i++) {
			str = in.readLine();
			for (int j = 0; j < M; j++) {
				board[i][j] = str.charAt(j);
				if(board[i][j] == '0') {
					start[0] = i;
					start[1] = j;
					board[i][j] = '.';
				}
			}
		}
		System.out.println(BFS(start[0], start[1]));
	}
}
