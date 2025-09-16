import java.io.*;
import java.util.*;

public class Main {
    public static final long MOD = 1_000_000_000L;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        long [][]DP = new long[N+1][10];
        for(int i = 1; i <= 9; i++) {
            DP[1][i] = 1;
        }

        for(int i =2; i <= N; i++) {
            for(int j = 0;j<10;j++){
                if(j == 0){
                    DP[i][j] = DP[i-1][1] % MOD;
                }
                else if(j == 9){
                    DP[i][j] = DP[i-1][8]% MOD;
                }
                else{
                    DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1])% MOD;
                }
            }
        }
        long sum = 0;
        for(int i = 0; i <= 9; i++) {
            sum= (sum + DP[N][i]) % MOD;
        }
        System.out.println(sum);
    }

}