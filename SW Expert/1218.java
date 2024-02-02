package hwalgo04_부울경_04_박지훈;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Solution_D4_1218_괄호짝짓기 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		for (int t = 1; t < 11; t++) {
			int N = Integer.parseInt(in.readLine());
			Stack<Integer> S = new Stack<>();
			String temp = in.readLine();
			boolean flag = true;
			for(int i=0;i<N;i++) {
				if(temp.charAt(i) == '(') {
					S.push(0);
				}
				if(temp.charAt(i) == '[') {
					S.push(1);
				}
				if(temp.charAt(i) == '{') {
					S.push(2);
				}
				if(temp.charAt(i) == '<') {
					S.push(3);
				}
				int nowPeek = S.peek();
				
				int nowC;
				if(temp.charAt(i) == ')') {
					nowC = 0;
					if(nowPeek != nowC) {
						System.out.println("#"+t+" "+0); 
						flag = false;
						break;
					}
					S.pop();
				}
				if(temp.charAt(i) == ']') {
					nowC = 1;
					if(nowPeek != nowC) {
						System.out.println("#"+t+" "+0); 
						flag = false;
						break;
					}
					S.pop();
				}
				if(temp.charAt(i) == '}') {
					nowC = 2;
					if(nowPeek != nowC) {
						System.out.println("#"+t+" "+0); 
						flag = false;
						break;
					}
					S.pop();
				}
				if(temp.charAt(i) == '>') {
					nowC = 3;
					if(nowPeek != nowC) {
						System.out.println("#"+t+" "+0); 
						flag = false;
						break;
					}
					S.pop();
				}
				
			}
			if(flag == true) System.out.println("#"+t+" "+1);
		}
	}
}
