import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Mainb {
    static int N,M;
    static ArrayList<Node>[] graph;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine()); // 정점 수
        M = Integer.parseInt(br.readLine()); // 간선 수
        graph = new ArrayList[N+1];
        for(int i = 0;i<=N;i++){
            graph[i] = new ArrayList<>();
        }
        for(int i =0;i<M;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start =Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int val = Integer.parseInt(st.nextToken());
            graph[start].add(new Node(end,val));
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());
        System.out.println(dij(start,end));
    }

    static int dij(int start, int end){
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(start,0));
        int []dist = new int[N+1];
        Arrays.fill(dist,987654321);
        boolean []visit = new boolean[N+1];
        dist[start] = 0;
        while(!pq.isEmpty()){
            Node nowNode = pq.poll();
            int nowIndex = nowNode.index;
            if(visit[nowIndex]) continue;
            visit[nowIndex] = true;

            for(Node next : graph[nowIndex]){
                if(dist[next.index] > dist[nowIndex] + next.weight){
                    dist[next.index] = dist[nowIndex] + next.weight;
                    pq.add(new Node(next.index, dist[next.index]));
                }
            }
        }
        return dist[end];
    }
    static class Node implements Comparable<Node>{
        int index, weight;

        public Node(int index, int weight) {
            this.index = index;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o){
            return this.weight-o.weight;
        }
    }
}
