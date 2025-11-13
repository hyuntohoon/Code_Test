import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static class Node implements Comparable<Node> {
        int index, weight;
        Node(int index, int weight){
            this.index= index;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o){
            return this.weight - o.weight;
        }
    }
    public static int N;
    public static ArrayList <Node>[] graph;

    public static int dij(int start, int end){

        int []dist = new int[N+1];
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(start, 0));
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
        while(!pq.isEmpty()){
            Node cur = pq.poll();
            int nowI = cur.index;
            int nowW = cur.weight;
            if(dist[nowI] <nowW){
                continue;
            }
            for(Node next : graph[nowI]){
                int nextWeight = next.weight + dist[nowI];
                if(dist[next.index]>nextWeight){
                    dist[next.index] = nextWeight;
                    pq.add(new Node(next.index, nextWeight));
                }
            }
        }
        return dist[end];
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());
        graph = new ArrayList[N+1];
        for(int i=0;i<=N;i++){
            graph[i] = new ArrayList<>();
        }
        for(int i = 0;i<M;i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            graph[start].add(new Node(end,weight));
        }
        int ans = -1;
        for(int i =1;i<=N;i++){
            int from = dij(i,X);
            int to = dij(X, i);

            ans = Math.max(ans, from+to);
        }
        System.out.println(ans);
    }
}