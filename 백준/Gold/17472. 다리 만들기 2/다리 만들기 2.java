import java.io.*;
import java.util.*;

public class Main {
    static int []dx ={0,0,-1,1};
    static int []dy = {1,-1,0,0};
    static ArrayList<Edge> edges;
    static class Edge implements Comparable<Edge>{
        int from, to,weight;
        Edge(int from,int to, int weight){
            this.from = from;
            this.to = to;
            this.weight=weight;
        }
        @Override
        public int compareTo(Edge o) {
            return this.weight - o.weight;
        }
    }
    static int []parents;
    static int []rank;
    static int findP(int a){
        if(parents[a] != a){
            parents[a] = findP(parents[a]);
        }
        return parents[a];
    }

    static void union(int a, int b){
        int rootA = findP(a);
        int rootB = findP(b);
        if(rootA == rootB) return;
        if(rank[rootA] > rank[rootB]){
            parents[rootB] = rootA;
        }
        else if(rank[rootA] < rank[rootB]){
            parents[rootA] = rootB;
        }
        else{
            parents[rootA] = rootB;
            rank[rootB]++;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int [][]board = new int[N][M];
        for(int i =0;i<N;i++){
            st = new StringTokenizer(br.readLine());
            for(int j =0;j<M;j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        ArrayList<int[]>[] nodes = new ArrayList[N*M + 1];
        for (int i = 0; i <= N * M; i++) {
            nodes[i] = new ArrayList<>();
        }

        Queue<int[]> q = new LinkedList<>();
        int [][]island = new int[N][M];
        int landNum = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 1 && island[i][j] == 0) {
                    island[i][j] = landNum;
                    nodes[landNum].add(new int[]{i, j});
                    q.add(new int[]{i, j});
                    while (!q.isEmpty()) {
                        int[] node = q.poll();
                        int x = node[0], y = node[1];
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k], ny = y + dy[k];
                            if (nx >= 0 && ny >= 0 && nx < N && ny < M && board[nx][ny] == 1 && island[nx][ny] == 0) {
                                island[nx][ny] = landNum;
                                q.offer(new int[]{nx, ny});
                                nodes[landNum].add(new int[]{nx, ny});
                            }
                        }
                    }
                    landNum++;
                }
            }
        }
        parents = new int[landNum+1];
        rank = new int[landNum+1];
        for(int i =1; i<=landNum;i++){
            parents[i] = i;
        }
       edges = new ArrayList<>();
        for (int i = 1; i < landNum; i++) {
            setEdges(i,island, nodes,N,M);
        }
        PriorityQueue<Edge> pq = new PriorityQueue<>();
       for(Edge e : edges){
           //System.out.println(e.from+" "+e.to + " "+e.weight);
           pq.add(e);
       }
       int ans = 0;
       while(!pq.isEmpty()){
           Edge e = pq.poll();
           int from  = e.from;
           int to = e.to;
           int weight = e.weight;
           if(weight == 1) continue;
         //  System.out.println(from + " " + to + " " + weight);
           if(findP(from) == findP(to)) continue;
          // System.out.println(weight+ " ");
           ans+=weight;
           union(from,to);
       }
       int startP = findP(1);
        for(int i=1;i<landNum;i++){
            if(startP != findP(i)){
                System.out.println(-1);
                return;
            }
        }
        System.out.println(ans);
    }

    private static void setEdges(int landNum, int[][] island, ArrayList<int[]>[] nodes, int N, int M) {
        for (int[] i : nodes[landNum]) {
            int x = i[0], y = i[1];
            for (int k = 0; k < 4; k++) { // 방향 지정
                for (int j = 1;; j++) {
                    int nx = x + dx[k] * j;
                    int ny = y + dy[k] * j;

                    // 범위 밖이면 중단
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;

                    if (island[nx][ny] == landNum) break; // 같은 섬 만나면 중단

                    if (island[nx][ny] != 0) { // 다른 섬을 만남
                        if (j > 2) { // 다리 길이는 2 이상이어야 함
                            int to = island[nx][ny];
                            boolean updated = false;
                            // 이미 존재하는 간선이면 최소 길이로 갱신
                            for (Edge edge : edges) {
                                if (edge.from == landNum && edge.to == to) {
                                    if (edge.weight > j - 1) edge.weight = j - 1;
                                    updated = true;
                                    break;
                                }
                            }
                            if (!updated) {
                                edges.add(new Edge(landNum,to, j-1));
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
}
