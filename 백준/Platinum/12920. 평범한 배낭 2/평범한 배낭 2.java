import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
   public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st = new StringTokenizer(br.readLine());
       int N = Integer.parseInt(st.nextToken());
       int M = Integer.parseInt(st.nextToken());
       int []weghits = new int[N+1];
       int []values = new int[N+1];
       int []count = new int[N+1];
       for(int i = 1;i<=N;i++){
           st = new StringTokenizer(br.readLine());
                weghits[i] = Integer.parseInt(st.nextToken());
                values[i] = Integer.parseInt(st.nextToken());
                count[i] = Integer.parseInt(st.nextToken());

       }
      int []DP = new int[M+1];
       ArrayList<int[]> al = new ArrayList<>();
       for(int i = 1;i<=N;i++){
           int nowW = weghits[i];
           int nowV = values[i];
           int nowC = count[i];
           for(int j =1;nowC>0;j<<=1){
               int take = Math.min(j,nowC);
                al.add(new int[]{nowW * take, nowV * take});
                nowC -= take;
           }
       }
        for(int []i : al){
            int nowW = i[0];
            int nowV = i[1];
            for(int j=M;j>=nowW;j--){
                DP[j] = Math.max(DP[j], DP[j-nowW] + nowV);
            }
        }
        System.out.println(DP[M]);
   }
}
