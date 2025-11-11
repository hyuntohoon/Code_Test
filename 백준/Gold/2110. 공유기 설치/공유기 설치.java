import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int []arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(arr);
        int left =1;
        int right = arr[n-1] - arr[0];
        int answer = 0;
        while(left <= right){
            int mid = left + (right - left)/2;
            int last = arr[0];
            int cnt = 1;
            for(int i = 1;i<n;i++){
                if(arr[i] - last >= mid){
                    cnt++;
                    last = arr[i];
                }
            }
            if(cnt >= c){ // 성공
                left = mid +1;
                answer = mid;
            }
            else{
                right = mid -1;
            }
        }
        System.out.println(answer);
    }
}
