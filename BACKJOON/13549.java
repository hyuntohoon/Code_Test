import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        int N, M;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        PriorityQueue<Move> pq = new PriorityQueue<>();
        pq.add(new Move(0,N));
        int []dist = new int[100001];
        Arrays.fill(dist, Integer.MAX_VALUE);
        while (!pq.isEmpty()) {
            Move move = pq.poll();
            int nowTime = move.time;
            int nowCost = move.cost;
            //System.out.println(nowTime + " " + nowCost);
            if(nowCost == M){
                System.out.println(nowTime);
                break;
            }
            if(nowCost+1 < 100001 && dist[nowCost+1] > nowTime+1){
                dist[nowCost+1] = nowTime+1;
                pq.add(new Move(nowTime+1,nowCost+1));
            }
            if(nowCost-1 >= 0 && dist[nowCost-1] > nowTime+1){
                dist[nowCost-1] = nowTime+1;
                pq.add(new Move(nowTime+1,nowCost-1));
            }
            if(nowCost*2 < 100001 && dist[nowCost*2] > nowTime){
                dist[nowCost*2] = nowTime;
                pq.add(new Move(nowTime,nowCost*2));
            }
        }
    }
    public static class Move implements Comparable<Move> {
        int time, cost;
        public Move(int time, int cost) {
            this.time = time;
            this.cost = cost;
        }
        @Override
        public int compareTo(Move o) {
            return time - o.time;
        }
    }
}
