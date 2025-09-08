import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int []arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int []DP = new int[N];
        Arrays.fill(DP, 1);
        int ans = 1;

        for(int i =1;i<N;i++){
            for(int j = 0;j<i;j++){
                if(arr[i]>arr[j]){
                    DP[i] = Math.max(DP[i],DP[j]+1);
                   // System.out.println(j + " " + DP[j]+" ");

                }
                ans = Math.max(ans,DP[i]);
            }
        }
        System.out.println(ans);
    }
}