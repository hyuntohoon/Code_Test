package hwalgo01_부울경_04_박지훈;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution_D2_1954_달팽이숫자_박지훈 {
	static int []dx = {0,-1,0,1};
	static int []dy = {1,0,-1,0};
	static int [][]arr = new int[11][11];
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for(int t = 1;t<=T;t++) {
			int N = Integer.parseInt(in.readLine());
			int aa = N;
			for(int i=1;i<=N;i++) {
				arr[0][i-1] = i;
			}
			int start = N;
			int nowD = 0;
			int startX = N - 1;
			int startY = 0;
			N--;
			while(N!=0) {
				for(int i=1;i<=N;i++) {// 
					startY = startY +dy[nowD];
					startX = startX + dx[nowD];
					start++;
					arr[startY][startX] = start;
				}
				nowD++;
				if(nowD==4) nowD = 0;
				for(int i=1;i<=N;i++) {// 
					startY = startY +dy[nowD];
					startX = startX + dx[nowD];
					start++;
					arr[startY][startX] = start;
				}
				nowD++;
				if(nowD==4) nowD = 0;
				N--;
			}
			System.out.println("#" + t);
			for(int i=0;i<aa;i++) {
				for(int j=0;j<aa;j++) {
					System.out.print(arr[i][j] + " ");
				}
				System.out.println();
			}
		}
	}
}
