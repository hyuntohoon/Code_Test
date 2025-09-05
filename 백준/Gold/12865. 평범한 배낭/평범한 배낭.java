import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
   public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st = new StringTokenizer(br.readLine());
       int N = Integer.parseInt(st.nextToken());
       int K = Integer.parseInt(st.nextToken());
       int [][]arr = new int[N+1][2];
       for(int i=1;i<=N;i++){
           st = new StringTokenizer(br.readLine());
           int a = Integer.parseInt(st.nextToken());
           int b = Integer.parseInt(st.nextToken());
            arr[i][0] = a;
            arr[i][1] = b;
       }
       int [][]dp = new int[N+1][K+1];
     //  Arrays.fill(dp,0);
       for(int i = 1;i<N+1;i++){
            int nowWeight = arr[i][0];
            int nowValue = arr[i][1];

            for(int j=0;j<K+1;j++){
                dp[i][j] = dp[i-1][j];
                if(nowWeight <= j){
                    dp[i][j] = Math.max(dp[i-1][j], + dp[i-1][j-nowWeight] + nowValue);
                }
            }
       }
       System.out.println(dp[N][K]);
   }
}
