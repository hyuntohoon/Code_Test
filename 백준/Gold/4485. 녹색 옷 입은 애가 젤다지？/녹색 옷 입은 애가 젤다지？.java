import java.io.*;
import java.util.*;

public class Main {
    public static int []dx = {0,0,-1,1};
    public static int []dy = {-1,1,0,0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = 1;
        while(true){
            int N = Integer.parseInt(br.readLine());
            if(N == 0) break;
            StringTokenizer st;
            int [][]arr = new int[N][N];
            for(int i = 0; i < N; i++){
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < N; j++){
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            int [][]dist = new int[N][N];
            for(int i = 0; i < N; i++){
                Arrays.fill(dist[i], Integer.MAX_VALUE);
            }
            dist[0][0] = 0;
            PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[2]));
            pq.add(new int[]{0,0,arr[0][0]});
            while(!pq.isEmpty()){
                int []temp = pq.poll();
                //System.out.println(Arrays.toString(temp));
                int x = temp[0], y = temp[1];
                int weight = temp[2];
                for(int k = 0;k<4;k++){
                    int nx = x + dx[k], ny = y + dy[k];
                    if(nx>=0 && ny>=0 && nx<N && ny<N){
                        int nowWeight = weight+arr[nx][ny];
                        if(dist[nx][ny] > nowWeight){
                            dist[nx][ny] = nowWeight;
                            pq.add(new int[]{nx,ny,nowWeight});
                        }
                    }
                }
            }
            System.out.println("Problem " +T +": "+ dist[N-1][N-1]);
            T++;
        }
    }
}