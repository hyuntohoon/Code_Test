import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int []arr = new int[n];
        st = new StringTokenizer(br.readLine());
        int right=0;
        int left = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            right += arr[i];
            left = Math.max(left, arr[i]);
        }
        int answer = 0;

        while(left<=right){
            int mid = left + (right - left)/2;
            int sum = 0;
            int cnt = 1;
            for(int i =0;i<n;i++){
                if(arr[i]+sum>mid){
                    sum = 0;
                    cnt++;
                }
                sum += arr[i];
            }
            if(cnt<=m) {// 성공
                right = mid -1;
                answer= mid;
            }
            else{
                left = mid + 1;
            }
        }
        System.out.println(answer);
    }
}
