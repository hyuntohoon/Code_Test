import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        int N, M;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        
        ArrayList<Long> arr = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            arr.add(Long.parseLong(br.readLine()));
        }
        
        arr.sort(Comparator.naturalOrder());

        int left = 0, right = 0;
        long answer = Long.MAX_VALUE;

        while (right < N) {
            if(left>=N) break;
            long nowV = arr.get(right) - arr.get(left);

            if (nowV >= M) {
                answer = Math.min(answer, nowV);
                left++;
            } else {
                right++;
            }
        }

        System.out.println(answer);
    }
}
