import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int []W = new int[N];
        int []H = new int[N];
        for(int i= 0;i<N;i++){
            st = new StringTokenizer(br.readLine());
            W[i] = Integer.parseInt(st.nextToken());
            H[i] = Integer.parseInt(st.nextToken());
        }
        int []DP = new int[M+1];
        for(int i=0;i<N;i++){
            for(int j = M;j>=0;j--){
                if(j - W[i] >= 0) {

                    DP[j] = Math.max(DP[j], DP[j-W[i]] + H[i]);
                   // System.out.println(DP[j]);
                }
            }
        }
        System.out.println(DP[M]);
    }
}