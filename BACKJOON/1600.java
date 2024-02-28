import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_1600 {
	static int[] dx = { 0, 0, -1, 1 };
	static int[] dy = { 1, -1, 0, 0 };
	// static int[][] visit;
	static boolean[][][] dist;
	static int N, M, K;
	static int[][] map;
	static int[] hx = { -2, -1, 1, 2, 2, 1, -1, -2 };
	static int[] hy = { 1, 2, 2, 1, -1, -2, -2, -1 };

	static class Point {
		int x, y, cnt, power;

		public Point(int x, int y, int cnt, int power) {
			super();
			this.x = x;
			this.y = y;
			this.cnt = cnt;
			this.power = power;
		}
	}

	static void BFS() {
		Queue<Point> Q = new LinkedList<>();
		Q.add(new Point(0, 0, 0, 0));
		dist[0][0][0] = true;
		while (!Q.isEmpty()) {
			int x = Q.peek().x;
			int y = Q.peek().y;
			int cnt = Q.peek().cnt;
			int power = Q.peek().power;
			if (x == N - 1 && y == M - 1) {
				System.out.println(cnt);
				return;
			}
			Q.poll();
			if (power < K) {
				for (int i = 0; i < 8; i++) {
					int nx = x + hx[i];
					int ny = y + hy[i];
					if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
						if (dist[nx][ny][power + 1] == false && map[nx][ny] == 0) {
							dist[nx][ny][power + 1] = true;
							Q.add(new Point(nx, ny, cnt + 1, power + 1));
						}
					}
				}
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
					if (dist[nx][ny][power] == false && map[nx][ny] == 0) {
						dist[nx][ny][power] = true;
						Q.add(new Point(nx, ny, cnt + 1, power));
					}
				}
			}
		}
		System.out.println(-1);
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		K = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		dist = new boolean[N][M][31];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		BFS();
	}
}
