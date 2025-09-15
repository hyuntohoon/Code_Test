import java.io.*;
import java.util.*;

public class Main {
    public static int []parents;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        ArrayList<Integer>[] tree = new ArrayList[N+1];
        for (int i = 0; i <= N; i++) {
            tree[i] = new ArrayList<>();
        }
        parents = new int[N+1];
        for (int i = 0; i < N-1; i++) {
            st = new StringTokenizer(br.readLine());
            int a= Integer.parseInt(st.nextToken());
            int b= Integer.parseInt(st.nextToken());
            tree[a].add(b);
            tree[b].add(a);
        }
        go(1,tree);
        for(int i=2;i<=N;i++) {
            System.out.println(parents[i]);
        }
    }

    private static void go(int parent, ArrayList<Integer>[] tree) {
        for(int child : tree[parent]) {
            if(parents[child] == 0) {
                parents[child] = parent;
                go(child, tree);
            }
        }
    }
}