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
            return Integer.compare(this.weight, o.weight);
        }
    }

    public static int dij(int start, int end) {
        int []dist = new int[N+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
        PriorityQueue <Node> pq = new PriorityQueue<>();
        pq.add(new Node(start, 0));
        while(!pq.isEmpty()) {
            Node cur = pq.poll();
            int nowIndex = cur.index;
            int nowWeight = cur.weight;
            if(dist[nowIndex] < nowWeight) continue;
            for(Node next : graph[nowIndex]) {
                int nextWeight = next.weight + dist[nowIndex];
                if(nextWeight < dist[next.index]){
                    dist[next.index] = nextWeight;
                    pq.add(new Node(next.index, nextWeight));
                }
            }
        }
        if(dist[end] == Integer.MAX_VALUE) return -1;
        return dist[end];
    }
    public static int N;
    public static ArrayList<Node>[] graph;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int E;
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        graph = new ArrayList[N+1];
        for(int i =1;i<=N;i++){
            graph[i] = new ArrayList<>();
        }
        for(int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            graph[start].add(new Node(end, weight));
            graph[end].add(new Node(start, weight));
        }
        st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int firstMove = dij(1,a);
        int secondMove = dij(a,b);
        int lastMove = dij(b,N);
        int ans = Integer.MAX_VALUE;

        if(firstMove == -1 || secondMove == -1 || lastMove == -1) {
            System.out.println("-1");
            return;

        }
        ans = Math.min(firstMove+secondMove+lastMove, ans);
        firstMove = dij(1,b);
        secondMove = dij(b,a);
        lastMove = dij(a,N);
        ans = Math.min(firstMove+secondMove+lastMove, ans);
        System.out.println(ans);
    }

}