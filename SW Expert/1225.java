package hwalgo04_부울경_04_박지훈;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Solution_D4_1225_암호생성기 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		for (int t = 1; t < 11; t++) {
			int T = Integer.parseInt(in.readLine());
			String[] temp = in.readLine().split(" ");
			int[] arr = new int[8];
			int minVal = 987654321;
			for (int i = 0; i < 8; i++) {
				arr[i] = Integer.parseInt(temp[i]);
				minVal = Math.min(arr[i], minVal);
			}
			int setArr = minVal / 15;
			setArr--;
			Queue<Integer> Q = new LinkedList<>();
			for (int i = 0; i < 8; i++) {
				arr[i] -= setArr * 15;
				Q.add(arr[i]);
			}

			int start = 1;
			while (true) {
				if (Q.peek() <= start) {
					int now = 0;
					Q.poll();
					Q.add(now);
					break;
				}
				int now = Q.poll() - start;
				Q.add(now);
				start++;
				if (start == 6)
					start = 1;
			}
			System.out.print("#"+t);
			for (int val : Q) {
				System.out.print(" "+val);
			}
			System.out.println();
		}
	}
}
