import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        long []arr = new long[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }
        Arrays.sort(arr);

        int left = 0;
        int right = arr.length - 1;
        long answer = Long.MAX_VALUE;
        long answerLeft = 0;
        long answerRight = 0;
        while(left < right){
            long sum = arr[left] + arr[right];
            long val = Math.abs(sum);
            if(val < answer){
                answer = val;
                answerLeft = arr[left];
                answerRight = arr[right];
                if(val == 0) break;
            }
            if(sum > 0){
                right--;
            }
            else{
                left++;
            }
        }
        System.out.println(answerLeft + " " + answerRight);
    }
}
