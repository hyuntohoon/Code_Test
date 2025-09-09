import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static class Node implements Comparable<Node> {
        int index, weight;
        public Node(int index, int weight) {
            this.index = index;
            this.weight = weight;

        }
        @Override
        public int compareTo(Node o) {
            return this.weight - o.weight;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N, M;
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int[] arr = new int[N + 1];
        st = new StringTokenizer(br.readLine());
        ArrayList<Integer>[] child = new ArrayList[N + 1];
        for(int i = 1; i <= N; i++) {
            child[i] = new ArrayList<>();
        }
        int root = 0;
        int []parents = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            int temp = Integer.parseInt(st.nextToken());
            parents[i] = temp;
            if(parents[i] == -1) { root = i;}
            else child[parents[i]].add(i);
        }
        Queue<Integer> Q = new LinkedList<>();
        int []add = new int[N + 1];
        for(int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            add[a] += b;
        }
        Q.add(root);
        long []sum = new long[N + 1];
        sum[root] = add[root];
        while(!Q.isEmpty()) {
            int now = Q.poll();
            for(int i : child[now]) {
                sum[i] = sum[now] + add[i];
                Q.add(i);
            }
        }
        for(int i = 1; i <= N; i++) {
            System.out.print(sum[i] + " ");
        }

    }

}