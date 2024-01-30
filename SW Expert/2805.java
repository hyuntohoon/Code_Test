package com.ssafy.daily02;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_D3_2805_농작물수확하기 {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		int t = 1;
		while(true) {
			if(t == T) break;
			t++;
			int sum = 0;
			int N = Integer.parseInt(in.readLine());
			System.out.println(T + " " + N);
			int [][]arr = new int[N][N];
			int aa = 0;
			while(true) {
				if(aa == N-1) break;
				String temp = in.readLine();
				for(int i =0; i<N;i++) {
					arr[aa][i] = Character.getNumericValue(temp.charAt(i));
					System.out.println(arr[aa][i]);
				}
				aa++;
			}
			for(int i = 0;i<N/2;i++) {
				for(int j =N/2-i;j<=(N/2+i);j++) {
					sum += arr[i][j];
				}
			}
			for(int i = N/2;i>=0;i--) {
				for(int j =N/2-i;j<=(N/2+i);j++) {
					sum += arr[N-i-1][j];
				}
			}
			
			System.out.printf("#%d %d", t, sum);
			System.out.println();
		}
	}
}
