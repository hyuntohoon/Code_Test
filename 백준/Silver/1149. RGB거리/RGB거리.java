import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        int []red = new int[N];
        int []green = new int[N];
        int []blue = new int[N];
        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            red[i] = Integer.parseInt(st.nextToken());
            green[i] = Integer.parseInt(st.nextToken());
            blue[i] = Integer.parseInt(st.nextToken());
        }
        int [][]DP = new int[N][3];
        DP[0][0] = red[0];
        DP[0][1] = green[0];
        DP[0][2] = blue[0];
        for(int i = 1; i < N; i++) {
            DP[i][0] = Math.min(DP[i-1][1] +red[i], DP[i-1][2]+red[i] );
            DP[i][1] = Math.min(DP[i-1][0] +green[i], DP[i-1][2]+green[i] );
            DP[i][2] = Math.min(DP[i-1][0] +blue[i], DP[i-1][1]+blue[i] );
        }
      

        int ans = Math.min(DP[N-1][0], DP[N-1][1]);
        ans = Math.min(ans, DP[N-1][2]);
        System.out.println(ans);
    }
}