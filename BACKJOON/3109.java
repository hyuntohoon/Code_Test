package hwalgo09_부울경_04_박지훈;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main2 {
	static int N, M;
	static char[][] arr;
	static boolean[][] visit;
	static int[] dx = { 1,1,1};
	static int[] dy = { -1,0,1 };
	static int result = 0;
	static boolean Ans;
	static void dfs(int y, int x) {
		visit[y][x] = true;
		if (x == M-1) {
			Ans = true;
			result++;
			return;
		}
		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (ny >= 0 && nx >= 0 && nx < M && ny < N && arr[ny][nx] == '.' && visit[ny][nx] == false) {
				//System.out.println(ny+" "+nx);
				dfs(ny,nx);
				if(Ans == true) return;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new char[N][M];
		visit =new boolean[N][M];
		for (int i = 0; i < N; i++) {
			String temp = br.readLine();
			for (int j = 0; j < M; j++) {
				arr[i][j] = temp.charAt(j);
				
			}
		}
		for(int i = 0;i<N;i++) {
			Ans = false;
			dfs(i,0);
		}
		System.out.println(result);
	}
}
