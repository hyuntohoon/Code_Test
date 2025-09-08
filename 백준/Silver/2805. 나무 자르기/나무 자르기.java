import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        long M = Long.parseLong(st.nextToken());
        long []arr = new long[N];
        st = new StringTokenizer(br.readLine());
        long maxHeight = Integer.MIN_VALUE;
        for (int i = 0; i < N; i++) {
            arr[i] = Long.parseLong(st.nextToken());
            maxHeight = Math.max(maxHeight, arr[i]);
        }

        long start =0;
        long end = maxHeight;
        long ans = 0;
        while(start <= end){
            long mid = start + (end - start)/2;
            long now = cut(arr, mid);

            if(now >= M){ // 정답은 되는데 높이를 높혀
                ans = mid;
                start = mid + 1;
            }
            else if(now < M){
                end = mid - 1;
            }
        }
        System.out.println(ans);
    }
    public static long cut(long []arr, long height ) {
        long sum = 0;
        for(long i : arr){
            if(i>height) sum += i-height;
        }
        //System.out.println(height + " " + sum);
        return sum;
    }
}