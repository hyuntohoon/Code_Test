package com.ssafy.daily02;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Solution_D4_1210_Ladder1 {
	private static int []dx = {1,-1,0};
	private static int []dy = {0,0,-1};
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		for(int o = 1;o<11;o++) {
			int T = Integer.parseInt(in.readLine());
			int [][]arr = new int[100][100];
			int startX = 0;
			int startY = 0;
			for (int i = 0; i < 100; i++) {
				String[] split = in.readLine().split(" ");
				for (int j = 0; j < split.length; j++) {
					arr[i][j] = Integer.parseInt(split[j]);
					if(arr[i][j] == 2) {
						startX = j;
						startY = i;
						//System.out.println(i+ " " + j);
					}
				}
			}


			while(startY != 0) {
				for(int j = 0;j<3;j++) {
					int nx = startX + dx[j];
					int ny = startY + dy[j];
					if(nx>=0 && ny>=0 && nx<100 && ny<100) {
						if(arr[ny][nx] == 1) {
							startX = nx;
							startY = ny;
							arr[ny][nx] = 3;
							//System.out.println(startX+ " "+ startY);
						}
					}
				}
			}
			System.out.println(startX);
		}

	}
}
