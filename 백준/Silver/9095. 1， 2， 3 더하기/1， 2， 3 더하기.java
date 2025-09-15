import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static int []dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        dp = new int[13];
        Arrays.fill(dp, -1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        for(int i = 0;i<T;i++){
            int N = Integer.parseInt(br.readLine());
            for(int j =3;j<=N;j++){
                dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
            }
            System.out.println(dp[N]);
        }

   }
}
