package com.ssafy.daily05;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;

public class Main_실버4_1158_요세푸스문제 {
	static int N, K;
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String []temp = in.readLine().split(" ");
		 StringBuilder sb = new StringBuilder();
		N = Integer.parseInt(temp[0]);
		K = Integer.parseInt(temp[1]);
		List<Integer> list = new LinkedList<>();
		for(int i=1;i<N+1;i++) {
			list.add(i);
		}
		int start = 0;
		sb.append("<");
		while(!list.isEmpty()) {
			start = (start + K - 1) % list.size();
			sb.append(list.remove(start)).append(", ");
			
		}
		sb.setLength(sb.length()-2);
		sb.append(">");
		System.out.println(sb);
	}
}
