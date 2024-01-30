import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	private static boolean []visited = new boolean[9];
	private static int []numbers = new int[9];
	private static int N;
	private static int M;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		StringBuilder sb = new StringBuilder();
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		nextPermutation(0);
		
	}

	private static void nextPermutation(int now) {
		if(M == now) {
			for(int i=0;i<M;i++) {
				System.out.print(numbers[i] + " ");
			}
			System.out.println();
			return;
		
		}
		for(int i =1;i<N+1;i++) {
			if(visited[i]) continue;
			numbers[now] = i;
			visited[i] = true;
			nextPermutation(now + 1);
			visited[i] = false;
			
		}
		
	}
}
