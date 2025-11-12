import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        int N, S;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        int []arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int firstPoint = 0, lastPoint = 0;
        int answer = Integer.MAX_VALUE;
        int nowSum = 0;
        while(lastPoint<N){
            nowSum += arr[lastPoint];
            while (nowSum >= S) {
                answer = Math.min(answer, lastPoint - firstPoint + 1);
                nowSum -= arr[firstPoint];
                firstPoint++;
            }
            lastPoint++;
        }
        if(answer == Integer.MAX_VALUE){
            System.out.println(0);
        }
        else System.out.println(answer);
    }
}