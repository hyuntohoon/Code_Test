import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long K = Long.parseLong(br.readLine());
        long start = 1;
        long end = (long) N * N; // 반드시 long 곱셈으로! (int 오버플로우 방지)
        while(start< end){
            long mid = start + (end-start)/2;
            long count =getSCount(mid,N);
            if(count>=K){ // K보다 크면 수 줄이기
                end =mid;
            }
            else{
                start = mid+1;
            }
        }
      System.out.println(start);
    }

    private static long getSCount(long mid, long N) {
        long count = 0;
        for(int i = 1;i<=N;i++){
            //count+= mid/i;
            count += Math.min((long) N, mid / i);
        }
        //System.out.println(mid + " " + N + " " + count);
        return count;
    }
}