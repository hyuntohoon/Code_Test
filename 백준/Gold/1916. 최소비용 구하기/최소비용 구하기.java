import java.io.*;
import java.util.*;

public class Main {
    public static class Node implements Comparable<Node> {
        int vertex, weight;
        public Node(int vertex, int weight) {
            this.vertex = vertex;
            this.weight = weight;
        }
        @Override
        public int compareTo(Node o) {
            return this.weight - o.weight;
        }
    }
   public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       int N = Integer.parseInt(br.readLine());
       int M = Integer.parseInt(br.readLine());
       StringTokenizer st;
       List<List<Node>> graph = new ArrayList<>();
       for(int i = 0; i < N+1; i++) {
           graph.add(new ArrayList<>());
       }
       for(int i = 0; i < M; i++) {
           st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            graph.get(start).add(new Node(end, weight));
       }
       st = new StringTokenizer(br.readLine());
       int startVertex = Integer.parseInt(st.nextToken());
       int endVertex = Integer.parseInt(st.nextToken());
       System.out.println(dij(startVertex, endVertex, graph,N));
   }
    public static int dij(int startVertex, int endVertex, List<List<Node>> graph, int N ) {
        int []dist = new int[N+1];
        for(int i = 0;i<N+1;i++){
            dist[i] = Integer.MAX_VALUE;
        }
        dist[startVertex] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(startVertex, 0));
        while(!pq.isEmpty()) {
            Node cur = pq.poll();
            if(dist[cur.vertex] < cur.weight) continue;
            for(Node nextNode : graph.get(cur.vertex)) {
                int nextDist = dist[cur.vertex] + nextNode.weight;
                if(nextDist < dist[nextNode.vertex]) {
                    dist[nextNode.vertex] = nextDist;
                    pq.add(new Node(nextNode.vertex, nextDist));
                }
            }
        }
        return dist[endVertex];
    }
}