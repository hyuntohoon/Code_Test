import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        long []arr = new long[N];
        long end = 0;
        for(int i =0;i<N;i++) {
            arr[i] = Long.parseLong(br.readLine());
            if(i >0) end = Math.max(end, Math.abs(arr[i]-arr[i-1]));
        }
        Arrays.sort(arr);
        end = arr[N-1] - arr[0]+1;
        //System.out.println(end);
        long start = 0;
        long mid = 0;
        long ans = 0;
        while(start < end){
            mid = start +(end - start)/2;
            int findR = findR(arr, mid,M);
            //System.out.println(findR + " " + mid);
            if(findR == -1 || findR < M){
                end = mid;
            } // 실패시 길이 줄이기
            else{ // 성공시 길이 늘리기
                ans =mid;
                start = mid+1;
            }
        }
        System.out.println(ans);
    }

    private static int findR(long[] arr, long length, int max) {
        int count = 1;
        // 지금을 기준으로 순회하여 해당 지점이 큰게 있다면 count++
        long last = arr[0];
        for(int i = 1;i<arr.length;i++) {
            if(arr[i] - last >=length){
                count++;
                last = arr[i];
                if(max == count) return count;
            }
        }
        return count;
    }

}