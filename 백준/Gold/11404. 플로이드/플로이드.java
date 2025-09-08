import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static class Node implements Comparable<Node>{
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
    public static ArrayList<Node>[] graph;
    public static int N,M;
    //public static int[] dist;
    public static int[] dij(int start, int end){
        int []dist = new int[N+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(start,0));
        while(!pq.isEmpty()){
            Node node = pq.poll();
            int nowI = node.index;
            int nowW = node.weight;
            if(nowW > dist[nowI]) continue;

            for(Node next : graph[nowI]){
                int nextW = dist[nowI] + next.weight;
                if(nextW < dist[next.index]){
                  dist[next.index] = nextW;
                  pq.add(new Node(next.index,nextW));
                }
            }
        }
        return dist;
    }
   public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
       StringTokenizer st;

       graph = new ArrayList[N+1];
       for(int i=0;i<=N;i++){
           graph[i] = new ArrayList<>();
       }
       int [][]dist = new int[N+1][N+1];
       for(int i=0;i<=N;i++){
           Arrays.fill(dist[i], Integer.MAX_VALUE);
       }
       for(int i=0;i<=N;i++){
            dist[i][i] = 0;
       }
       for(int i = 0; i < M; i++) {
           st = new StringTokenizer(br.readLine());
           int start = Integer.parseInt(st.nextToken());
           int end = Integer.parseInt(st.nextToken());
           int weight = Integer.parseInt(st.nextToken());
           if(dist[start][end] > weight) dist[start][end] = weight;
           //dist[start][end] = weight;
       }

       for(int i =1; i<=N;i++){
           for(int j =1; j<=N;j++){
               for(int k = 1;k<=N;k++){
                   if(dist[j][i] == Integer.MAX_VALUE || dist[i][k] == Integer.MAX_VALUE) continue;
                   dist[j][k] = Math.min(dist[j][k], dist[j][i] + dist[i][k]);
               }
           }
       }

       for(int i =1; i<=N;i++){
           for(int j =1; j<=N;j++){
               if(dist[i][j] == Integer.MAX_VALUE){
                   System.out.print(0+ " ");
               }
               else System.out.print(dist[i][j] + " ");
           }
           System.out.println();
       }
   }
}