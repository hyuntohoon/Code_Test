package day20;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_2636 {
	static int[] dx = { 0, 0, -1, 1 };
	static int[] dy = { 1, -1, 0, 0 };

	static class Point {
		int x, y;

		public Point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[][] board = new int[N][M];
		int[][] visit = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		Queue<Point> Q = new LinkedList<>();
		Queue<Point> delCheeze = new LinkedList<>();
		int cnt = 0;
 		while (true) {
 			cnt++;
			Q.add(new Point(0, 0));
			for (int i = 0; i < N; i++) {
			    Arrays.fill(visit[i], 0);
			}
			while (!Q.isEmpty()) {
				int x = Q.peek().x;
				int y = Q.peek().y;
				Q.poll();
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx >= 0 && ny >= 0 && nx < N && ny < M && visit[nx][ny] == 0) {
						if (board[nx][ny] == 1) {
							delCheeze.add(new Point(nx,ny));
							visit[nx][ny] = 1;
						}
						if(board[nx][ny] == 0) {
							Q.add(new Point(nx,ny));
							visit[nx][ny] = 1;
						}
					}
				}
			}
			int cheezeSize = 0;
			for(int i=0;i<N;i++) {
				for(int j=0;j<M;j++) {
					if(board[i][j] == 1) cheezeSize++;
				}
			}
			if(delCheeze.size() == cheezeSize) {
				System.out.println(cnt);
				System.out.println(cheezeSize);
				break;
			}
			while(!delCheeze.isEmpty()) {
				int x = delCheeze.peek().x;
				int y = delCheeze.peek().y;
				delCheeze.poll();
				board[x][y] = 0;
			}
		}
	}
}
