package live_09;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution_4012_요리사 {
	static int N;
	static int [][]arr;
	static boolean []check;
	static ArrayList<Integer> listA;
	static ArrayList<Integer> listB;
	static int result;
	static void comb(int cnt,int start) {
		//System.out.println("sasa");
		if(cnt == N/2) {
			listA = new ArrayList<>();
			listB = new ArrayList<>();
			for(int i=1;i<N+1;i++) {
				if(check[i]) {
					listA.add(i);
				}
				else {
					listB.add(i);
				}
			}
			int aSum = 0;
			int bSum = 0;
	
			for(int i = 0; i < listA.size()-1; i++) {
			    for(int j = i+1; j < listA.size(); j++) { // i+1부터 시작

			        aSum += arr[listA.get(i)][listA.get(j)];
			        aSum += arr[listA.get(j)][listA.get(i)];
			    }
			}
			for(int i = 0; i < listB.size()-1; i++) {
			    for(int j = i+1; j < listB.size(); j++) { // i+1부터 시작

			        bSum += arr[listB.get(i)][listB.get(j)];
			        bSum += arr[listB.get(j)][listB.get(i)];
			    }
			}
			result = Math.min(result, Math.abs(aSum-bSum));
			return;
		}
		for(int i=start;i<N+1;i++) {
			check[i] = true;
			comb(cnt+1, i+1);
			check[i] = false;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int t = 1;t<T+1;t++) {
			StringTokenizer st;
			N = Integer.parseInt(br.readLine());
			arr = new int[N+1][N+1];
			check = new boolean[N+1];

			result = 987654321;
			for(int i=1;i<N+1;i++) {
				 st = new StringTokenizer(br.readLine());
				for(int j=1;j<N+1;j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			comb(0,1);
			System.out.println("#"+t+" "+result);
		}
	}
}
