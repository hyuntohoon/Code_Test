package live_09;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_D3_5215_햄버거다이어트 {
	static int result;
	static int N;
	static boolean []sel;
	static int [][]arr;
	static int calSum() {
		int sum=0;
		for(int i=0;i<N;i++) {
			if(sel[i]) {
				sum+=arr[i][1];
			}
		}
		//System.out.println("cal" + sum);
		return sum;
	}

	static int scoreSum() {
		int sum=0;
		for(int i=0;i<N;i++) {
			if(sel[i]) {
				sum+=arr[i][0];
			}
		}
		//System.out.println("score" +sum);
		result = Math.max(result, sum);
		return sum;
	}
	static void comb(int start, int cnt, int limitCnt, int L) {
		if(cnt == limitCnt) {
			int sum = calSum();
			if(sum<=L) {	
				scoreSum();
			}
			return;
		}
		for(int i=start+1;i<N;i++) {
			sel[i] = true;
			comb(i,cnt+1,limitCnt,L);
			sel[i] = false;
		}
		return;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int t = 1;t<T+1;t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());

			N = Integer.parseInt(st.nextToken());
			sel = new boolean[N];
			int L = Integer.parseInt(st.nextToken());
			arr = new int[N][2];
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				arr[i][0] = Integer.parseInt(st.nextToken());
				arr[i][1] = Integer.parseInt(st.nextToken());
			}
			for(int i=1;i<N+1;i++) {
				comb(-1,0,i,L);
			}
			System.out.println("#"+t+" "+result);
		}
	}
}
