package daily22;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int[][] arr;
	static int[] visit;
	static int startHiiter;
	static int ans;
	static int calScore(int inning) {
		int out= 0;
		boolean flag = false;
		boolean first = false;
		boolean second = false;
		boolean thrid = false;
		int score = 0;
		while(out !=3) {
			if(flag) break;
			for(int i = startHiiter;i<=9;i++) {
				int nowHitter = visit[i]; // visit[1] => 첫번째 타자가 몇번째에 나오는지
				int nowResult = arr[inning][nowHitter];
				if(nowResult == 0) out++;
				if(out == 3) {
					flag = true;
					startHiiter = (i+1)%10;
					if(startHiiter == 0) startHiiter = 1;
					return score;
				}
				if(nowResult == 1) {
					if(thrid) {
						thrid = false;
						score++;
					}
					if(second) {
						thrid = true;
						second = false;
					}
					if(first) {
						first = false;
						second = true;
					}
					first = true;
				}
				if(nowResult == 2) {
					if(thrid) {
						thrid = false;
						score++;
					}
					if(second) {
						score++;
						second = false;
					}
					if(first) {
						first = false;
						thrid = true;
					}
					second = true;
				}
				if(nowResult == 3) {
					if(thrid) {
						thrid = false;
						score++;
					}
					if(second) {
						score++;
						second = false;
					}
					if(first) {
						first = false;
						score++;
					}
					thrid = true;
				}
				if(nowResult ==4) {
					if(thrid) {
						thrid = false;
						score++;
					}
					if(second) {
						score++;
						second = false;
					}
					if(first) {
						first = false;
						score++;
					}
					score++;
				}
			}
			startHiiter = 1;
		}
		return score;
	}
	static void DFS(int cnt) {
		if (cnt == 10) {
			int result = 0;
			startHiiter = 1;
			for(int i =0;i<N;i++) {
				result +=calScore(i);
			}
			ans = Math.max(ans, result);
			//System.out.println(result);
			return;
		}

		for (int i = 1; i <= 9; i++) {
			if(i == 4) continue;
			if (visit[i] == 0) {
				visit[i] = cnt;
				DFS(cnt+1);
				visit[i] = 0;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[51][10];
		visit = new int[10];
		visit[4] = 1;
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 1; j < 10; j++)
				arr[i][j] = Integer.parseInt(st.nextToken());
		}
		DFS(2);
		System.out.println(ans);
	}
}
