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
        public int compareTo(Node o){
            return Integer.compare(this.weight, o.weight);
        }
    }
    public static ArrayList<Node>[] graph;
    public static int V;
   public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
       int E = Integer.parseInt(st.nextToken());
       int startV = Integer.parseInt(br.readLine());
       graph = new ArrayList[V+1];
       for(int i = 0; i <= V; i++){
           graph[i] = new ArrayList<>();
       }
       for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            graph[start].add(new Node(end, weight));
       }int []dist = dij(startV);
       int ans;
       for(int i = 1; i <= V; i++){
           if(i != startV){
               ans = dist[i];
               if(ans == Integer.MAX_VALUE){
                   System.out.println("INF");
               }
               else{
                   System.out.println(ans);
               }
           }
           else System.out.println("0");

       }
   }

    private static int[] dij(int startV) {
       int []dist = new int[V+1];
       Arrays.fill(dist, Integer.MAX_VALUE);
       dist[startV] = 0;
       PriorityQueue<Node> pq = new PriorityQueue<>();
       pq.add(new Node(startV, 0));
       while(!pq.isEmpty()){
           Node cur = pq.poll();
           int nowV = cur.index;
           int nowWeight = cur.weight;
           if(dist[nowV] <nowWeight)  continue;
           for(Node next : graph[nowV]){
               int nextWeight = next.weight + dist[nowV];
               if(dist[next.index] > nextWeight){
                   dist[next.index] = nextWeight;
                   pq.add(new Node(next.index, nextWeight));
               }
           }
       }

       return dist;
    }
}