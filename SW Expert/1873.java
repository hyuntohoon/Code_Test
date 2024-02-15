package hwalgo10_부울경_04_박지훈;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_D3_1873_상호의배틀필드 {
	static int H, W, N;
	static char[][] board;
	static int sx, sy;
	static int D;
	static int []dx = {0,0,-1,1};
	static int []dy = {-1,1,0,0};
	static boolean checkRange(int x, int y) {
		if(x >= 0 && y>= 0 && x<W && y<H ) return true;
		return false;
	}
	static void go(char order) {
		if(order == 'U') {
			D = 0;
			if(checkRange(sx, sy-1)) {
				if(board[sy-1][sx] != '*' && board[sy-1][sx] != '#' && board[sy-1][sx] != '-') sy--;
			}
		}
		if(order == 'D') {
			D = 1;
			if(checkRange(sx, sy+1) ) {
				if(board[sy+1][sx] != '*' && board[sy+1][sx] != '#' && board[sy+1][sx] != '-') sy++;
			}
		}
		if(order == 'L') {
			D = 2;
			if(checkRange(sx-1, sy)) {
				if(board[sy][sx-1] != '*' && board[sy][sx-1] != '#' && board[sy][sx-1] != '-') sx--;
			}
		}
		if(order == 'R') {
			D = 3;
			if(checkRange(sx+1, sy)) {
				if(board[sy][sx+1] != '*' && board[sy][sx+1] != '#' && board[sy][sx+1] != '-') sx++;
			}
		}
		if(order == 'S') {
			int shootX = sx + dx[D];
			int shootY = sy + dy[D];
			while(true) {
				if(!checkRange(shootX, shootY)) break;
				if(board[shootY][shootX] == '*') {
					board[shootY][shootX] = '.';
					break;
				}
				if(board[shootY][shootX] == '#') break;
				shootX += dx[D];
				shootY += dy[D];
			}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			H = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			board = new char[H][W];
			for (int i = 0; i < H; i++) {
				String temp = br.readLine();
				for (int j = 0; j < W; j++) {
					board[i][j] = temp.charAt(j);
					if(board[i][j] == '^' || board[i][j] == 'v' || board[i][j] == '<' || board[i][j] == '>') {
						sx = j;
						sy = i;
						if(board[i][j] == '^') D = 0;
						if(board[i][j] == 'v') D = 1;
						if(board[i][j] == '<') D = 2;
						if(board[i][j] == '>') D = 3;
						board[sy][sx] = '.';
					}
				}
			}
			N = Integer.parseInt(br.readLine());
			String order = br.readLine();
			for (int i = 0; i < N; i++) {
				go(order.charAt(i));
			}
			if(D == 0) board[sy][sx] = '^';
			if(D == 1) board[sy][sx] = 'v';
			if(D == 2) board[sy][sx] = '<';
			if(D == 3) board[sy][sx] = '>';
			System.out.print("#"+t+" ");
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					System.out.print(board[i][j]);
				}
				System.out.println();
			}
				
		}
	}
}
