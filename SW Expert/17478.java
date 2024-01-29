package com.ssafy.daily01;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_실버5_17478_재귀함수가뭔가요_박지훈 {
	public Main_실버5_17478_재귀함수가뭔가요_박지훈() throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("1204_input.txt"));
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
