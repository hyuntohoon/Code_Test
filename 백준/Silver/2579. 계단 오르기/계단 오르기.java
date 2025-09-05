import java.io.*;
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] s = new int[N];
        for (int i = 0; i < N; i++) s[i] = Integer.parseInt(br.readLine());

        if (N == 1) { System.out.println(s[0]); return; }
        if (N == 2) { System.out.println(s[0] + s[1]); return; }

        int[] dp = new int[N];
        dp[0] = s[0];
        dp[1] = s[0] + s[1];
        dp[2] = Math.max(s[0] + s[2], s[1] + s[2]);

        for (int i = 3; i < N; i++) {
            dp[i] = Math.max(dp[i-2], dp[i-3] + s[i-1]) + s[i];
        }
        System.out.println(dp[N-1]);
    }
}