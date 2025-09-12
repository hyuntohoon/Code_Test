import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int []time = new int[N];
            st = new StringTokenizer(br.readLine());
            for(int i =0;i<N;i++) {
                time[i] = Integer.parseInt(st.nextToken());
            }
            int []DP = new int[N];

            ArrayList<Integer>[] adj = new ArrayList[N];
            for(int i =0;i<N;i++) {
                adj[i] = new ArrayList<>();
                DP[i] = Integer.MIN_VALUE;
            }
            int []dist = new int[N];
            for(int i =0;i<M;i++) {
                st = new StringTokenizer(br.readLine());
                int a = (Integer.parseInt(st.nextToken()))-1;
                int b = (Integer.parseInt(st.nextToken()))-1;
                dist[b]++;
                //System.out.println(a + " " + b);
                adj[a].add(b);
            }
            int target = Integer.parseInt(br.readLine())-1;
            //System.out.println(target);
            Queue<Integer> q = new LinkedList<>();
            for(int i =0;i<N;i++) {
                if(dist[i] == 0) {
                    q.add(i);
                    DP[i] = time[i];
                }
            }
            while(!q.isEmpty()) {
                int nowIndex = q.poll();
                //System.out.println(nowIndex);
                for(int next : adj[nowIndex]) {
                    DP[next] = Math.max(DP[next], DP[nowIndex] + time[next]);
                    dist[next]--;
                    if(dist[next] == 0) q.offer(next);
                }
            }
            for(int i =0;i<N;i++) {
                //System.out.println(DP[i]);
            }
            System.out.println(DP[target]);
        }

    }

    }