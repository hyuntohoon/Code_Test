import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static int []rank;
    public static int []parents;
    public static class Node implements Comparable<Node> {
        int start, end, weight;
        Node(int start, int end, int weight){
            this.start = start;
            this.end = end;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o){
            return this.weight - o.weight;
        }
    }

    public static int findP(int a){
        if(parents[a] != a){
            parents[a] = findP(parents[a]);
        }
        return parents[a];
    }
    public static void union(int a, int b){
        int rootA = findP(a);
        int rootB = findP(b);

        if(rootA == rootB){
            return;
        }

        if(rank[rootA] > rank[rootB]){
            parents[rootB] = rootA;
        }
        else if(rank[rootB] > rank[rootA]){
            parents[rootA] = rootB;
        }
        else if(rank[rootA] == rank[rootB]){
            parents[rootB] = rootA;
            rank[rootA]++;
        }
    }
   public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       int N = Integer.parseInt(br.readLine());
       int M = Integer.parseInt(br.readLine());
       PriorityQueue <Node> pq = new PriorityQueue<>();
       StringTokenizer st;
       parents = new int[N+1];
       for(int i = 1; i <= N; i++){
           parents[i] = i;
       }
       rank = new int[N+1];
       for (int i = 0; i < M; i++) {
           st = new StringTokenizer(br.readLine());
           int start = Integer.parseInt(st.nextToken());
           int end = Integer.parseInt(st.nextToken());
           int weight = Integer.parseInt(st.nextToken());
           pq.add(new Node(start, end, weight));
       }
       int sum = 0;
       int count = 0;
       while(!pq.isEmpty()){
           Node node = pq.poll();
           int start = node.start;
           int end = node.end;
           int weight = node.weight;
           if(findP(start) != findP(end)){
               union(start, end);
               sum +=weight;
               count++;
               if(count == N-1){
                   System.out.println(sum);
                   return;
               }
           }
       }
   }
}