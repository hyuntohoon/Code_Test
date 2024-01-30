package com.ssafy.daily02;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_Solution_D4_1210_Ladder1 {
	class reverseComparator implements Comparator<Integer> {
	    @Override
	    public int compare(Integer a, Integer b) {
	        if(a > b) return a;
	        else return b;
	    }
	}
	public static void main(String[] args) throws IOException, NumberFormatException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = 1;
		while(true) {
			if(T ==11) break;
			List<Integer> list = new ArrayList<>();
			int dump = Integer.parseInt(in.readLine());
			StringTokenizer st = new StringTokenizer(in.readLine());
			for(int i = 0;i<100;i++) {
				Integer a = new Integer(st.nextToken());
				list.add(Integer.valueOf(a));
			}
			Collections.sort(list);
			while(true) {
				if(dump == 0) break;
				list.set(99, list.get(99)-1);
				list.set(0, list.get(0)+1);
				Collections.sort(list);
				dump--;
			}
			System.out.println("#" + T + " " + (list.get(99)-list.get(0)));
			T++;
		}
	}
}
