import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N, M;
		int [][]arr;
		String[] temp = in.readLine().split(" ");
		N = Integer.parseInt(temp[0]);
		M = Integer.parseInt(temp[1]);
		arr = new int[N+1][N+1];
		for(int i = 1;i<=N;i++) {
			String[] arrTemp = in.readLine().split(" ");
			arr[i][1] = Integer.parseInt(arrTemp[0]);
			for(int j=2;j<=N;j++) {
				arr[i][j] = Integer.parseInt(arrTemp[j-1]) + arr[i][j-1];
			}
		}
		for(int i = 0;i<M;i++) {
			String[] sectionTemp = in.readLine().split(" ");
			int Ay = Integer.parseInt(sectionTemp[0]);
			int Ax = Integer.parseInt(sectionTemp[1]);
			int By = Integer.parseInt(sectionTemp[2]);
			int Bx = Integer.parseInt(sectionTemp[3]);
			int sum = 0;
			for(int j= Ay;j<=By;j++) {
				sum += arr[j][Bx] - arr[j][Ax-1];
			}
			sb.append(sum + "\n");
		}
		System.out.println(sb);
	}
}

/*
 * arr[a] = arr[a-1] + arr[a]
 * 
 * 
 */
