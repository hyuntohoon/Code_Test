package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;

public class Main_4991_jh {
    static int N,M;
    static List<List<Node>> graph;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

         N = Integer.parseInt(st.nextToken());
         M = Integer.parseInt(st.nextToken());

        graph = new ArrayList<>();
        for(int i =0;i<N+1;i++) {
            graph.add(new ArrayList<>());
        }
        for(int i =0;i<M;i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            graph.get(from).add(new Node(to,weight));
            graph.get(to).add(new Node(from,weight));
        }

        dij(1);
    }

    public static void dij(int start){
        int []dist = new int[N+1];
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[start] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(start, 0));

        while(!pq.isEmpty()){
            Node nowNode = pq.poll();
            int nowTo = nowNode.vertex;
            int nowWeight = nowNode.weight;
            for(int i = 0;i<graph.get(nowTo).size();i++){
                Node nextNode = graph.get(nowTo).get(i);
                if(dist[nextNode.vertex]>dist[nowTo]+nextNode.weight){
                    dist[nextNode.vertex] = dist[nowTo]+nextNode.weight;
                    pq.add(nextNode);
                }
            }
        }
        System.out.println(dist[N]);
    }

    public static class Node implements Comparable<Node>{
        int vertex, weight;

        public Node(int vertex, int weight) {
            this.vertex = vertex;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            return this.weight-o.weight;
        }
    }
}
