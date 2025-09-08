import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static class Node implements Comparable<Node> {
        int index,weight;
        public Node(int index, int weight){
            this.index = index;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o){
            return this.weight - o.weight;
        }
    }
    public static ArrayList<Node>[] graph;
    public static int N;
    public static int[] visited;
    public static int dij(int start, int end){
        int []dist = new int[N+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(start, 0));
        while(!pq.isEmpty()){
            Node cur = pq.poll();
            int nowI = cur.index;
            int nowW = cur.weight;
            if(dist[nowI] <nowW) continue;

            for(Node next : graph[nowI]){
                int nextWeight = dist[nowI] + next.weight;
                if(nextWeight < dist[next.index]){
                    dist[next.index] = nextWeight;
                    pq.add(new Node(next.index, nextWeight));
                    visited[next.index] = nowI;
                }
            }
        }
        System.out.println(dist[end]);
        return 0;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        graph = new ArrayList[N+1];
        for(int i = 1; i <= N; i++){
            graph[i] = new ArrayList<>();
        }
        visited = new int[N+1];
        StringTokenizer st;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            graph[start].add(new Node(end, weight));
        }
        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());

        dij(start, end);
        int now = end;
        ArrayList<Integer> list = new ArrayList<>();
        list.add(now);
        while(true){

            now = visited[now];
            if(now == 0) break;
            list.add(now);

        }
        Collections.reverse(list);
        System.out.println(list.size());
        for(int i : list){
            System.out.print(i+ " ");
        }
    }
}