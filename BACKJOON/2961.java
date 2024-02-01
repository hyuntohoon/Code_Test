package hwalgo03_부울경_04_박지훈;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collection;
import java.util.HashSet;
import java.util.Set;

public class Main_실버2_2961_도영이가만든맛있는음식 {
	static int []sour;
	static boolean []ingreUsed;
	static int []ingre;
	static int []bitter;
	static int N;
	static long []tasteSum = new long[1024];
	static int tasteTemp;
	static long result = 987654321;
	
	static long sourCal(int cnt) {
		long sourNow = sour[ingre[0]];
		for(int i= 1;i<cnt;i++) {
			sourNow *= sour[ingre[i]];
		}
		return sourNow;
	}
	static long bitterCal(int cnt) {
		long bitterNow = bitter[ingre[0]];
		for(int i= 1;i<cnt;i++) {
			bitterNow += bitter[ingre[i]];
		}
		return bitterNow;
	}

	static void subset(int n, int cnt) {
		if(n == cnt) {
			for(int i=0;i<cnt;i++) {
				//System.out.print(ingre[i] + " ");
			}
			//System.out.println();
			tasteSum[tasteTemp] = sourCal(cnt);
			result = Math.min(result,Math.abs(tasteSum[tasteTemp] - bitterCal(cnt)));
			return;
		}
		for(int i=0;i<N;i++) {
			if(ingreUsed[i]) continue;
			ingre[cnt] = i;
			ingreUsed[i] = true;
			subset(n, cnt+1);
			ingreUsed[i] = false;
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(in.readLine());
		sour = new int[N];
		bitter = new int[N];
		ingre = new int[N];
		ingreUsed = new boolean[N];
		for(int i=0;i<N;i++) {
			String[] temp = in.readLine().split(" ");
			sour[i] = Integer.parseInt(temp[0]);
			bitter[i] = Integer.parseInt(temp[1]);
		}
		for(int i=1;i<=N;i++) {
			subset(i, 0);
		}

		System.out.println(result);
	}
}
