import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());
            int [][]arr = new int[2][N];
            StringTokenizer st;
            for(int i=0;i<2;i++) {
                st = new StringTokenizer(br.readLine());
                for(int j=0;j<N;j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            int [][]DP = new int[2][N];
            DP[0][0] = arr[0][0];
            DP[1][0] = arr[1][0];
            for(int j=1;j<N;j++) {
                DP[0][j] = Math.max(DP[0][j-1], DP[1][j-1] + arr[0][j]);
                DP[1][j] = Math.max(DP[1][j-1], DP[0][j-1] + arr[1][j]);
            }
            System.out.println(Math.max(DP[0][N-1], DP[1][N-1]));
        }
    }
}