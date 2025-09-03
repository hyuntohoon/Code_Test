import java.io.*;
import java.util.*;

public class Main {
   public static void main(String[] args) throws IOException {
       BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st = new StringTokenizer(br.readLine());
       int N = Integer.parseInt(st.nextToken());
       int M = Integer.parseInt(st.nextToken());
       int []arr = new int[N];
       for(int i =0;i<N;i++) {
           arr[i] = Integer.parseInt(br.readLine());
       }
       int cnt = 0;
       while(!(M == 0)){
           for(int i = N-1;i>=0;i--) {
               if(arr[i]<=M){
                   M -= arr[i];
                   i++;
                   cnt++;
                   if(M==0) break;
                  // System.out.println(M);
               }
           }
       }
       System.out.println(cnt);
   }
}
