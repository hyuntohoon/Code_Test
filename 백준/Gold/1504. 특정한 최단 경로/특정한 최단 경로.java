import java.io.*;
import java.util.*;

public class Main {
    public static class Node implements Comparable<Node> {
        int Vertex, weight;
        public Node(int v, int w){
            Vertex = v;
            weight = w;
        }
        @Override
        public int compareTo(Node other){
            return this.weight - other.weight;
        }
    }
   public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st = new StringTokenizer(br.readLine());
       int N = Integer.parseInt(st.nextToken());
       int M = Integer.parseInt(st.nextToken());
       List<List<Node>> graph = new ArrayList<>();
       for(int i =0;i<N+1;i++){
           graph.add(new ArrayList<>());
       }
       for(int i =0;i<M;i++){
           st = new StringTokenizer(br.readLine());
           int start = Integer.parseInt(st.nextToken());
           int end = Integer.parseInt(st.nextToken());
           int weight = Integer.parseInt(st.nextToken());
           graph.get(start).add(new Node(end,weight));
           graph.get(end).add(new Node(start,weight));
       }
       st = new StringTokenizer(br.readLine());
       int fristMustPassVertex = Integer.parseInt(st.nextToken());
       int secondMustPassVertex = Integer.parseInt(st.nextToken());
       int fristPass = dij(1, fristMustPassVertex, graph, N);
       int secondPass = dij(fristMustPassVertex, secondMustPassVertex, graph, N);
       int lastPass = dij(secondMustPassVertex, N, graph,N);
       int answer = 0;
       if(fristPass == Integer.MAX_VALUE || lastPass == Integer.MAX_VALUE || secondPass == Integer.MAX_VALUE){
           answer = Integer.MAX_VALUE;
       }
       else answer = fristPass + secondPass + lastPass;

       fristPass = dij(1, secondMustPassVertex, graph, N);
       secondPass = dij(secondMustPassVertex, fristMustPassVertex, graph, N);
       lastPass = dij(fristMustPassVertex, N, graph, N);
       if(fristPass == Integer.MAX_VALUE || lastPass == Integer.MAX_VALUE || secondPass == Integer.MAX_VALUE){
          answer = Math.min(answer, Integer.MAX_VALUE);
       }
       else answer = Math.min(answer, fristPass + secondPass + lastPass);
       if(answer == Integer.MAX_VALUE){
           System.out.println(-1);
       }
       else System.out.println(answer);
   }

    private static int dij(int startVertex, int endVertex, List<List<Node>> graph, int N) {
        int []dist = new int[N+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[startVertex] = 0;
        PriorityQueue <Node> pq = new PriorityQueue<>();
        pq.add(new Node(startVertex,0));
        while(!pq.isEmpty()){
            Node cur = pq.poll();
            if(dist[cur.Vertex]<cur.weight) continue;
            for(Node nextNode : graph.get(cur.Vertex)){
                int nextWeight = nextNode.weight + dist[cur.Vertex];
                if(dist[nextNode.Vertex]>nextWeight){
                    dist[nextNode.Vertex] = nextWeight;
                    pq.add(new Node(nextNode.Vertex,nextWeight));
                }
            }
        }
        //System.out.println(dist[endVertex]);
        return dist[endVertex];
    }
}