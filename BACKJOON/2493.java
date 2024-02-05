package com.ssafy.daily05;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

class Top{
	public Top(int num, int height) {
		this.num = num;
		this.height = height;
	}
	int num;
	int height;

}
public class Main_골드5_2493_탑 {
	static int N;
	static int []arr;
	static Stack<Top> S = new Stack<>();

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(in.readLine());
		arr = new int[N+1];
		String []temp = in.readLine().split(" ");
		for(int i=1;i<N+1;i++) {
			int nowHeight = Integer.parseInt(temp[i-1]);
			if(S.empty()) {
				System.out.print(0 +" ");
				S.push(new Top(i,nowHeight));
			}
			else {
				while(true) {
					if (S.isEmpty()) {
						System.out.print(0 +" ");
						S.push(new Top(i,nowHeight));
						break;
					}
					Top top = S.peek();
					if(top.height>nowHeight) {
						System.out.print(top.num +" ");
						S.push(new Top(i,nowHeight));
						break;
					}
					else {
						S.pop();
					}
				}
			}
		}

	}
}
