import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Maina {
    static int V,E,K;
    static ArrayList<Node>[] graph;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
         V = Integer.parseInt(st.nextToken()); // 정점
         E = Integer.parseInt(st.nextToken()); // 간선
         K = Integer.parseInt(br.readLine()); // 시작정점
        graph = new ArrayList[V+1];
        for(int i = 0;i<=V;i++){
            graph[i] = new ArrayList<>();
        }
        for(int i = 0;i<E;i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int val = Integer.parseInt(st.nextToken());
            graph[start].add((new Node(end, val)));
            //graph[end].add((new Node(start, val))); 양방향 아님
        }
        int []ans  = dij(K);
        for(int i =1;i<=V;i++){

            if(ans[i] == 987654321){
                System.out.println("INF");
                continue;
            }
            System.out.println(ans[i]);
        }
    }
    static int[] dij(int start){
        PriorityQueue<Node> pq = new PriorityQueue<Node>();
        int []dist = new int[V+1];
        Arrays.fill(dist,987654321);
        boolean []visit = new boolean[V+1];
        pq.add(new Node(start,0));
        dist[start] = 0;
        while(!pq.isEmpty()){
            Node nowNode = pq.poll();
            int nowIndex = nowNode.index;
            if(visit[nowIndex]) continue;
            visit[nowIndex] = true;
            for(Node next : graph[nowIndex]){
                if(dist[next.index] > dist[nowIndex] + next.distance){
                    dist[next.index] = dist[nowIndex] + next.distance;
                    pq.add(new Node(next.index, dist[next.index]));
                }
            }
        }
        return dist;
    }

    static class Node implements Comparable<Node>{
        int index, distance;

        public Node(int index, int distance) {
            this.index = index;
            this.distance = distance;
        }

        @Override
        public int compareTo(Node o){
            return this.distance-o.distance;
        }
    }
}
