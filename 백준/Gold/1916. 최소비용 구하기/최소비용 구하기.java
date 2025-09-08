import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static int N,M;
    public static ArrayList<Node>[] graph;
    public static class Node implements Comparable<Node> {
        int index, weight;
        Node(int index, int weight){
            this.index = index;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            return this.weight - o.weight;
        }
    }
    public static int dijkstra(int start, int end){
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(start, 0));
        int []dist = new int[N+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
        while(!pq.isEmpty()){
            Node cur = pq.poll();
            int nowIndex = cur.index;
            int nowWeight = cur.weight;
            if(nowWeight > dist[nowIndex]){
                continue;
            }
            for(Node n : graph[nowIndex]){
                int newDist = dist[nowIndex] + n.weight;
                if(newDist < dist[n.index]){
                    dist[n.index] = newDist;
                    pq.add(new Node(n.index, newDist));
                }
            }
        }
        return dist[end];
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         N = Integer.parseInt(br.readLine());
         M = Integer.parseInt(br.readLine());
         graph = new ArrayList[N+1];
        for(int i = 0; i <= N; i++){
            graph[i] = new ArrayList<>();
        }
        StringTokenizer st;
        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int dist = Integer.parseInt(st.nextToken());
            graph[start].add(new Node(end, dist));
        }
        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());
        System.out.println(dijkstra(start, end));
    }
}