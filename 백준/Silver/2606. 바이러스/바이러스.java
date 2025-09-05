import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static List<Integer>[] arr;
    public static int sum;
   public static boolean []visit;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
       arr = new List[N + 1];
       visit = new boolean[N+1];
       for(int i = 1; i <= N; i++) {
           arr[i] = new LinkedList<>();
       }
       sum = 0;
        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr[a].add(b);
            arr[b].add(a);
        }
        visit[1] = true;
        go(1);
        System.out.println(sum);
    }
    public static void go(int now) {
        for(int i : arr[now]){
            int x = i;
            if(!visit[i]){
                visit[i] = true;
                sum++;
               // System.out.println(sum);
                go(x);
            }
        }
    }
}
