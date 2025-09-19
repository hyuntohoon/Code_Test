import java.io.*;
import java.util.*;

public class Main {
    static class Node implements Comparable<Node>{
        int V,weight;
        Node(int v,int w){
            this.V=v;
            this.weight=w;
        }

        @Override
        public int compareTo(Node o) {
            return this.weight-o.weight;
        }
    }
    static ArrayList<Node>[] graph;
    static int ans;
    static ArrayList<Integer>[] path;
    static boolean [][]removePaths;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        while(true) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            if (N == M && N == 0) {
                return;
            }
            removePaths = new boolean[N][N];
            path = new ArrayList[N+1];
            graph = new ArrayList[N + 1];
            for (int i = 0; i < N; i++) {
                graph[i] = new ArrayList<>();
                path[i] = new ArrayList<>();
            }
            st = new StringTokenizer(br.readLine());
            int startVertex = Integer.parseInt(st.nextToken());
            int endVertex = Integer.parseInt(st.nextToken());

            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int start = Integer.parseInt(st.nextToken());
                int end = Integer.parseInt(st.nextToken());
                int weight = Integer.parseInt(st.nextToken());
                graph[start].add(new Node(end, weight));
            }

            int minDist = dij(startVertex, endVertex, N);
            removePath(startVertex, endVertex,N);
            ans = dij(startVertex, endVertex, N);
            if(ans == Integer.MAX_VALUE) System.out.println(-1);
            else System.out.println(ans);
        }
    }
    static int dij(int start, int end,int N){
        int []dist = new int[N];
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[start] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start,0));
        while(!pq.isEmpty()){
            Node node = pq.poll();
            int v = node.V;
            int w = node.weight;
            if(dist[v] < w) continue;
            for(Node nextNode : graph[v]){
                if(removePaths[v][nextNode.V]) continue;
                int nextWeight = nextNode.weight + w;
                if(dist[nextNode.V] > nextWeight){
                    dist[nextNode.V] = nextWeight;
                    path[nextNode.V].clear();
                    path[nextNode.V].add(v);
                    pq.offer(new Node(nextNode.V,nextWeight));
                }
                else if( dist[nextNode.V] == nextWeight){
                    path[nextNode.V].add(v);
                    //pq.offer(new Node(nextNode.V,nextWeight));
                }
            }
        }
        return dist[end];
    }

    static void removePath(int start, int end,int N){
        Queue<Integer> q = new LinkedList<>();
        q.offer(end);
        boolean []visit = new boolean[N];
        while(!q.isEmpty()){
            int now = q.poll(); // 끝에서
            for(int i : path[now]){ //시작
                if(!removePaths[i][now])  removePaths[i][now] =true;
                if(!visit[i]){
                    visit[i] = true;
                    q.offer(i);
                }
            }
        }

    }
}