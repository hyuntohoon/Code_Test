import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static int []DP;
    public static int N,K;
    public static int ans;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
         N = Integer.parseInt(st.nextToken());
         K = Integer.parseInt(st.nextToken());
         DP = new int[K+1];
         ans = Integer.MAX_VALUE;
        for(int i=0;i<=K;i++){
            DP[i] = Math.abs(K-i);
            ans = Math.min(ans,DP[i]);
        }
       Deque<int[]> q = new ArrayDeque<>();
        q.add(new int[]{N,0});
        int []dist = new int[100001];
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[N] = 0;
        while(!q.isEmpty()){
            int[]cur = q.poll();
            int nowX = cur[0];
            int nowTime = cur[1];

            if(nowX == K){
                System.out.println(nowTime);
                return;
            }
            if(nowX +1 < 100001 && dist[nowX+1]>nowTime+1) {
                dist[nowX+1] = nowTime + 1;
                q.addLast(new int[]{nowX+1,nowTime+1});
            }
            if(nowX -1 >=0 && dist[nowX-1]>nowTime+1) {
                dist[nowX-1] = nowTime + 1;
                q.addLast(new int[]{nowX-1,nowTime+1});
            }
            if(nowX*2<100001 && dist[nowX*2]>nowTime) {
                dist[nowX*2] = nowTime;
                q.addFirst(new int[]{nowX*2,nowTime});
            }
        }
    }

}