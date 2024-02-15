package daily12;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_1247 {
	static int[] visit;
	static int N;
	static Point[] cilent;
	static Point home;
	static int result;

	static void go(int cnt, Point prev, int sum) {
		if (sum >= result) return;

		if (cnt == N) {
			result = Math.min(sum + home.calDis(prev), result);
			return;
		}
		for (int i = 0; i < N; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				go(cnt + 1, cilent[i], sum + prev.calDis(cilent[i]));
				visit[i] = 0;
			}
		}
	}

	static class Point {
		int x;
		int y;

		public Point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		int calDis(Point o) {
			return Math.abs(this.x - o.x) + Math.abs(this.y - o.y);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			N = Integer.parseInt(br.readLine());
			visit = new int[N];
			cilent = new Point[N];
			result = 987654321;
			StringTokenizer st = new StringTokenizer(br.readLine());
			int companyX = Integer.parseInt(st.nextToken());
			int companyY = Integer.parseInt(st.nextToken());
			Point company = new Point(companyX, companyY);
			int homeX = Integer.parseInt(st.nextToken());
			int homeY = Integer.parseInt(st.nextToken());
			home = new Point(homeX, homeY);
			for (int i = 0; i < N; i++) {
				int tempX = Integer.parseInt(st.nextToken());
				int tempY = Integer.parseInt(st.nextToken());
				cilent[i] = new Point(tempX, tempY);
			}
			go(0, company, 0);
			System.out.println("#"+t+" "+result);
		}
	}
}
