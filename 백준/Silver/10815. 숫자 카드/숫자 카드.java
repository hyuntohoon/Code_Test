import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static ArrayList<Integer> al;
    public static int bin(int n) {
        int start = 0;
        int end = al.size();
        while(start < end) {
            int mid = start + (end- start) / 2;
            if(al.get(mid) == n) return 1;
            else if(al.get(mid)> n) end = mid;
            else start = mid + 1;
        }
        return 0;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        al = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
       for (int i = 0; i < N; i++) {

            al.add(Integer.parseInt(st.nextToken()));
       }
        al.sort((a, b) -> a - b);
        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < M; i++) {

            int a= Integer.parseInt(st.nextToken());
          //  System.out.print(bin(a)+ " ");
            sb.append(bin(a)+" ");
        }
        System.out.println(sb);
    }
}