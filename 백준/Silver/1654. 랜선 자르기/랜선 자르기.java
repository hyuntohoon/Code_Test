import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static long cut(long nowLength, long cutSize){
        return nowLength / cutSize;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        long K  = Long.parseLong(st.nextToken());
        long []arr = new long[N+1];
        long maxV = -1;
        for(int i=0;i<N;i++){
            arr[i] = Long.parseLong(br.readLine());
            maxV = Math.max(maxV,arr[i]);
        }
        long start = 1;
        long end = maxV+1;
        long ans = 0;
        while(start<end){
            long mid = start + (end-start)/2;
            long sum = 0;
            for(long temp : arr){
                sum += cut(temp,mid);
            }
            if(sum<K){ // 실패하면 범위 줄이기
                end = mid;
            }
            else{ // 성공하면 범위 늘리기
                start = mid+1;
            }
        }
        System.out.println(start-1);
    }
}