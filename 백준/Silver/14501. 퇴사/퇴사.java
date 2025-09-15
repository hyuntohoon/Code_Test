import java.io.*;
import java.util.*;

public class Main {
    public static int []parents;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        int []days = new int[N+1];
        int []values = new int[N+1];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            days[i] = Integer.parseInt(st.nextToken());
            values[i] = Integer.parseInt(st.nextToken());

        }
        int []DP = new int[N+1];
        for(int i =1;i<=N;i++){
            int nowDay = days[i];
            int nowValue = values[i];
            DP[i] = Math.max(DP[i], DP[i-1]);
            if(N>=i+nowDay-1){
                //System.out.println(i+nowDay);
                DP[i+nowDay-1] = Math.max(DP[i-1] + nowValue, DP[i+nowDay-1]);
            }
        }
        int ans = 0;
        for(int i =0;i<=N;i++){
           // System.out.println(i + " " +DP[i]);
            ans = Math.max(ans, DP[i]);
        }
        System.out.println(ans);
    }
}