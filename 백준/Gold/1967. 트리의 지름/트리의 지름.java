import java.io.*;
import java.util.*;

public class Main {

    public static class Node{
        int index, weight;
        public Node(int index, int weight) {
            this.index = index;
            this.weight = weight;
        }
    }
    public static void main(String[] args) throws Exception {
       /*
       자신의 자식 노드 중 가장 큰 값을 가지고 오기
       각 루트마다 실행해서 가장 큰 차이가 있는 곳이 답
        */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        ArrayList <Node>[] graph = new ArrayList[N+1];
        for(int i = 0; i <= N; i++){
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < N-1; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            graph[start].add(new Node(end, weight));
        }
//        System.out.println(go(graph[1].get(0).index,graph[1].get(0).weight,graph));
//        System.out.println();
//        System.out.println(go(graph[1].get(1).index,graph[1].get(1).weight,graph));
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            List<Integer> li = new ArrayList<>();
            for(Node node : graph[i]){
                int nowIndex = node.index;
                int nowWeight = node.weight;
                int result = Math.max(go(nowIndex, nowWeight, graph), nowWeight);
                //System.out.println(result);
                li.add(result);
            }
            li.sort(Comparator.reverseOrder());

            if(li.size() == 0) continue;
            if(li.size() == 1) ans = Math.max(ans,li.get(0));
            else ans = Math.max(li.get(0) + li.get(1),ans);
        }
        System.out.println(ans);
    }
    public static int go(int now, int nowWeight, ArrayList<Node>[] graph){
        int max = nowWeight;
        //System.out.println(now + " " + nowWeight);
        for(Node node : graph[now]){
            max = Math.max(go(node.index, nowWeight + node.weight, graph), max);
        }
        //System.out.println(max);
        return max;
    }
}