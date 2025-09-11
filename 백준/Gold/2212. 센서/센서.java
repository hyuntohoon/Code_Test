import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int K = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            list.add(Integer.parseInt(st.nextToken()));
        }
        if(N<=K) {
            System.out.println(0);
            return;
        }
        list.sort(Comparator.comparingInt(a -> a));
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < N-1; i++) {
            int a = list.get(i);
            int b = list.get(i + 1);
            //System.out.print(a-b + " ");
            pq.add((int)Math.abs(a-b));
        }
        int count = N-K;
        int sum = 0;
        while(count != 0) {
            int a = pq.poll();
           // System.out.println(a);
            sum += a;
            count--;
        }
        System.out.println(sum);
    }
}