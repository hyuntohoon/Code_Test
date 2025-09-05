import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static int []parents;
    public static int []rank;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());
        parents = new int[V+1];
        rank =  new int[V+1];
        for(int i = 1; i <= V; i++){
            parents[i] = i;
        }
        PriorityQueue<int []> pq = new PriorityQueue<>(Comparator.comparingInt(a ->  a[2]));
        for(int i = 0; i < E; i++){
           st = new StringTokenizer(br.readLine());
           int a = Integer.parseInt(st.nextToken());
           int b = Integer.parseInt(st.nextToken());
           int c = Integer.parseInt(st.nextToken());
           pq.offer(new int[]{a,b,c});
        }
        int used = 0;
        int minWeight = 0;
        while(!pq.isEmpty() && used <= V){
            int []arr = pq.poll();
            int x = arr[0];
            int y = arr[1];
            int val = arr[2];
            if(findP(x) != findP(y)){
                union(x,y);
                used++;
                minWeight += val;
            }
        }
        System.out.println(minWeight);
        }
        public static int findP(int x){
            if(parents[x] != x){
                parents[x] = findP(parents[x]);
            }
            return parents[x];
        }
        public static void union(int a, int b){
            int rootA = findP(a);
            int rootB = findP(b);
            if(rank[rootA] > rank[rootB]){
                parents[rootB] = rootA;
            }
            else if(rank[rootB] > rank[rootA]){
                parents[rootA] = rootB;
            }
            else {
                parents[rootB] = rootA;
                rank[rootA]++;
            }
        }
}