import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Main {
	static int N, M;
	static int []numbers;
	public static StringBuilder sb = new StringBuilder();
	static void go(int start, int end){
		//System.out.println(start+" " +end);
		int sum;
		if(start == 0) sum = numbers[end];
		else sum = numbers[end]-numbers[start-1];
		sb.append(sum + "\n");
	}
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		String []temp = in.readLine().split(" ");
		N = Integer.parseInt(temp[0]);
		M = Integer.parseInt(temp[1]);
		String []numTemp = in.readLine().split(" ");
		numbers = new int[N];
		numbers[0] = Integer.parseInt(numTemp[0]);
		for(int i=1;i<N;i++) {
			numbers[i] = Integer.parseInt(numTemp[i])+ numbers[i-1];
		}
		for(int i=0;i<M;i++) {
			int []section = new int[M];
			String []sectionTemp = in.readLine().split(" ");
			section[0] = Integer.parseInt(sectionTemp[0])-1;
			section[1] = Integer.parseInt(sectionTemp[1])-1;
			go(section[0], section[1]);
		}
		System.out.println(sb);
	}
}

/*
 * arr[a] = arr[a-1] + arr[a]
 * 
 * 
 */
