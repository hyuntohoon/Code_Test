package hwalgo21_부울경_04_박지훈;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_1263 {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int N = Integer.parseInt(st.nextToken());
			int[][] graph = new int[N + 1][N + 1];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int temp = Integer.parseInt(st.nextToken());
					if (temp == 0)
						graph[i][j] = 1001;
					else
						graph[i][j] = 1;
				}
			}
			for (int k = 0; k < N; k++) {
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						if (i == j)
							continue;
						graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
					}
				}
			}
			int []dist  = new int[N+1];
			int result = 987654321;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if(graph[i][j] == 1001) continue;
					dist[i] += graph[i][j];
				}
				result = Math.min(dist[i],result);
			}
			System.out.println("#"+t+" "+result);
		}
	}
}
