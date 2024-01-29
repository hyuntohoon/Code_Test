package com.ssafy.daily01;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution_D3_1289_원재의메모리복구하기_박지훈 {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for(int t=1;t<T+1;t++) {
			String str = in.readLine();
			int count = 0;
			char now = '0';
			for(int i=0;i<str.length();i++) {
				if(str.charAt(i) != now) {
					now = str.charAt(i);
					count++;
				}
			}
			System.out.println(count);
		}
	}
}
