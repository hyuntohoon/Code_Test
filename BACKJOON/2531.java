import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int []arr = new int[30001];
        int []eatArr = new int[3001];
        int maxEat = 0;
        for(int i = 0;i<N;i++){
            arr[i] = Integer.parseInt(br.readLine());
        }
        int count = 0;


        for(int i=0;i<k;i++){
            int nowArr = arr[i];
            if(eatArr[nowArr] == 0){
                eatArr[nowArr] = 1;
                count++;
            }
            else eatArr[nowArr]++;
        }
        maxEat = count;
        if (eatArr[c] == 0) {
            maxEat++;
        }

        for (int i = 1; i < N; i++) {
            int prevArr = arr[(i - 1) % N];
            int nowArr = arr[(i + k - 1) % N];
            eatArr[prevArr]--;
            if(eatArr[prevArr] == 0) count--;
            if(eatArr[nowArr] == 0) {
                count++;
            }
            eatArr[nowArr]++;
            int currentEat = count;
            if (eatArr[c] == 0) {
                currentEat++;
            }
            maxEat = Math.max(maxEat, currentEat);
        }
        System.out.println(maxEat);
    }
}
