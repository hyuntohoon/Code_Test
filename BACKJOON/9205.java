package work;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main_9205 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N, M;

		N = Integer.parseInt(in.readLine());
		for (int t = 0; t < N; t++) {
			List<int[]> board = new ArrayList<>();
			M = Integer.parseInt(in.readLine());
			int[][] graph = new int[M + 3][M + 3];
			for (int i = 0; i < M + 2; i++) {
				int from, to;
				int[] P = new int[2];
				st = new StringTokenizer(in.readLine());
				from = Integer.parseInt(st.nextToken());
				to = Integer.parseInt(st.nextToken());
				P[0] = from;
				P[1] = to;
				board.add(P);
			}
			for (int i = 0; i < M + 2; i++) {
				for (int j = 0; j < M + 2; j++) {
					if(i == j) graph[i][j] = 0;
					else {
						int x = Math.abs(board.get(i)[0]-board.get(j)[0]);
						int y = Math.abs(board.get(i)[1]-board.get(j)[1]);
						if(x+y >1000) {
							graph[i][j] = 987654321;
						}
						else {
							graph[i][j] = 1;
						}
					}
				}
			}
			for(int k=0;k<M+2;k++) {
				for(int i =0;i<M+2;i++) {
					for(int j=0;j<M+2;j++) {
						if(graph[i][j] > graph[i][k] + graph[k][j]) {
							
							graph[i][j] = graph[i][k] + graph[k][j];
						}
					}
				}
			}
			//System.out.println(graph[0][M+1]);
			if(graph[0][M+1]<=1000) {
				System.out.println("happy");
			}
			else {
				System.out.println("sad");
			}
		}
	}
}
