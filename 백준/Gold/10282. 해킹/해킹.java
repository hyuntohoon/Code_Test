import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static ArrayList <Node>[] graph;
    public static class Node implements Comparable<Node>{
        int index, weight;
        public Node(int index, int weight){
            this.index = index;
            this.weight = weight;
        }
        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.weight,o.weight);
        }
    }

    public static void dij(int start, int end){
        int []dist = new int[V+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;

        PriorityQueue <Node> pq = new PriorityQueue<>();
        pq.add(new Node(start, 0));
        int ans = 0;
        while(!pq.isEmpty()){
            Node cur = pq.poll();
            int nowI  = cur.index;
            int nowW  = cur.weight;
            ans = Math.max(ans, nowW);
            if(dist[cur.index] < nowW ) continue;
            for(Node next : graph[cur.index]){
                int nextW = next.weight + dist[nowI];
                if(nextW < dist[next.index]){
                    dist[next.index] = nextW;
                    pq.add(new Node(next.index, nextW));
                }
            }
        }
        int cnt = 0;
        int last = 0;
        for(int i =1;i<=V;i++){
            if(dist[i] != Integer.MAX_VALUE) {
                cnt++;
                last = Math.max(last, dist[i]);
            }
        }
        System.out.println(cnt + " " + last);
    }
    public static int V,E;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while(T-- >0){
            int start;
            StringTokenizer st = new StringTokenizer(br.readLine());
            V = Integer.parseInt(st.nextToken());
            E = Integer.parseInt(st.nextToken());
            start = Integer.parseInt(st.nextToken());

            graph = new ArrayList[V+1];
            for(int i = 0; i < V+1; i++){
                graph[i] = new ArrayList<>();
            }
            for(int i = 0;i<E;i++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int time = Integer.parseInt(st.nextToken());
               //graph[a].add(new Node(b,time));
               graph[b].add(new Node(a,time));
            }
            dij(start, V);
        }
    }

}