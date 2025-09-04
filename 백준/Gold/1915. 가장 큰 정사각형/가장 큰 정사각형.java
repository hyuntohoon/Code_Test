import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
   public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       int n,m;
       StringTokenizer st = new StringTokenizer(br.readLine());
       n = Integer.parseInt(st.nextToken());
       m = Integer.parseInt(st.nextToken());
       int [][]arr = new int[n][m];
       int [][]dp = new int[n][m];
       for(int i =0;i<n;i++) {
           String temp = br.readLine();
           for(int j =0;j<m;j++) {
               arr[i][j] = temp.charAt(j) - '0';
           }
       }
       for(int i=0;i<n;i++) {
           for(int j=0;j<m;j++) {
               if(arr[i][j]==0) dp[i][j]=0;
               else if(i == 0 || j == 0) dp[i][j]=1;
               else dp[i][j] = Math.min(Math.min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
           }
       }
        int ans = 0;
       for(int i =0;i<n;i++) {
           for(int j=0;j<m;j++) {
              // System.out.print(dp[i][j]+" ");
               ans = Math.max(ans,dp[i][j]);
           }
           //System.out.println();
       }
       System.out.println(ans*ans);
   }
}
