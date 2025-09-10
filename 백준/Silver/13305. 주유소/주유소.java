import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       int N = Integer.parseInt(br.readLine());
       int []V = new int[N-1];
       int []E = new int[N];
       StringTokenizer st = new StringTokenizer(br.readLine());
       for(int i = 0; i < N-1; i++) {
           V[i] = Integer.parseInt(st.nextToken());
       }
       st = new StringTokenizer(br.readLine());
       for(int i = 0; i < N; i++) {
           E[i] = Integer.parseInt(st.nextToken());
       }
       int []DP = new int[N];
        Arrays.fill(DP, Integer.MAX_VALUE);
       for(int i = 0; i < N; i++) {
           for(int j = i; j < N-1; j++) {
               DP[j] = Math.min(DP[j], V[j]*E[i]);
               //System.out.print(DP[j] + " " + i+ " " + j + " ");
           }
          // System.out.println();
       }
       int sum = 0;
       for (int i =0; i < N-1; i++) {
           //System.out.print(DP[i] + " ");
           sum += DP[i];
       }
       System.out.println(sum);
    }
}