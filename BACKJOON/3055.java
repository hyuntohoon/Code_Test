package hwalgo21_부울경_04_박지훈;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_3055 {
	static int N, M;
	static char[][] board;
	static int []dx = {0,0,1,-1};
	static int []dy = {1,-1,0,0};
	static int [][] visit;
	static void BFS(int startX, int startY) {
		int[] XY = new int[2];
		XY[0] = startX;
		XY[1] = startY;
		Queue<int[]> biber = new LinkedList();
		Queue<int[]> water = new LinkedList();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == '*') {
					int[] temp = new int[2];
					temp[0] = i;
					temp[1] = j;
					water.add(temp);
				}
			}
		}

		biber.add(XY);
		int cnt = 0;
		while (!biber.isEmpty()) {
			cnt++;
			int waterCnt = water.size();
			for (int w = 0; w < waterCnt; w++) {
				int x= water.peek()[0];
				int y= water.peek()[1];
				water.poll();
				for(int k=0;k<4;k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if(nx>=0 && ny >=0 && nx<N && ny <M) {
						if(board[nx][ny] == '.') {
							board[nx][ny] = '*';
							int[] temp = new int[2];
							temp[0] = nx;
							temp[1] = ny;
							water.add(temp);
						}	
					}
				}
			}
			int biberCnt = biber.size();
			for (int b = 0; b < biberCnt; b++) {
				int x = biber.peek()[0];
				int y = biber.peek()[1];
				biber.poll();	
				if(board[x][y] =='D') {
					System.out.println(cnt-1);
					System.exit(0);
				}
				for(int k=0;k<4;k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if(nx>=0 && ny >=0 && nx<N && ny <M && visit[nx][ny] == 0) {
						if(board[nx][ny] == '.' || board[nx][ny] == 'D') {
							int[] temp = new int[2];
							temp[0] = nx;
							temp[1] = ny;
							biber.add(temp);
							visit[nx][ny] = 1;
						}	
					}
				}
			}

		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		visit = new int[N][M];
		board = new char[N][M];
		int startX = -1;
		int startY = -1;
		for (int i = 0; i < N; i++) {
			String S = in.readLine();
			for (int j = 0; j < M; j++) {
				board[i][j] = S.charAt(j);
				if (board[i][j] == 'S') {
					startX = i;
					startY = j;
				}
			}
		}
		BFS(startX, startY);
		System.out.println("KAKTUS");
	}
}
