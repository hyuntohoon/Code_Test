import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        long[] dist = new long[N - 1];
        long[] price = new long[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N - 1; i++) dist[i] = Long.parseLong(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) price[i] = Long.parseLong(st.nextToken());

        long minPrice = price[0];
        long total = 0;

        for (int i = 0; i < N - 1; i++) {
            if (price[i] < minPrice) minPrice = price[i]; // 현재 도시 가격 반영
            total += minPrice * dist[i];
        }

        System.out.println(total);
    }
}