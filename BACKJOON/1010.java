package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class jh1010 {
    static int [][]DP;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T;
        T = Integer.parseInt(br.readLine());
        for(int t = 0;t<T;t++){


            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            DP = new int[N+1][M+1];
            for(int i =0;i<=N;i++){
                for(int j =0;j<=M;j++){
                    DP[i][j] = -1;
                }
            }
            for(int i =1;i<=M;i++){
                DP[1][i] = i;
            }
            System.out.println(dp(N,M));
        }

    }
    static int dp(int n,int m){
        if(DP[n][m] == -1){
            int temp = 0;
            for(int i=1;i<m;i++){
                temp += dp(n-1,m-i);
            }
            DP[n][m] = temp;
        }
        return DP[n][m];
    }
}
