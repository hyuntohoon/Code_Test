import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int T,M,N,K;
    static int [][]arr;
    static int []dx = {1,-1,0,0};
    static int []dy = {0,0,1,-1};
    static boolean [][]visited;
   public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       T = Integer.parseInt(br.readLine());
       while (T-- > 0) {
           StringTokenizer st = new StringTokenizer(br.readLine());
           N = Integer.parseInt(st.nextToken());
           M = Integer.parseInt(st.nextToken());
           K = Integer.parseInt(st.nextToken());
           arr = new int[N][M];
           for (int i = 0; i < N; i++) {
               Arrays.fill(arr[i], 0);
           }
           for (int i = 0; i < K; i++) {
               st = new StringTokenizer(br.readLine());
               int x = Integer.parseInt(st.nextToken());
               int y = Integer.parseInt(st.nextToken());
               //System.out.println(x + " " + y);
               arr[x][y] = 1;
           }
           visited = new boolean[N][M];
           int sum = 0;
           for (int i = 0; i < N; i++) {
               for (int j = 0; j < M; j++) {
                   if (!visited[i][j] && arr[i][j] == 1) {
                       go(i, j);
                       sum++;
                   }
               }
           }
           System.out.println(sum);
       }
   }
   static void go(int i,int j){
       Queue<int[]> q = new LinkedList<>();
       q.add(new int[]{i,j});
       while(!q.isEmpty()){
           int []temp = q.poll();
           int x = temp[0];
           int y = temp[1];
            for(int k = 0;k<4;k++){
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(nx>=0 && ny>=0 && nx<N && ny<M){
                    if(!visited[nx][ny]){
                        if(arr[nx][ny] == 1){
                            visited[nx][ny] = true;
                            q.add(new int[]{nx,ny});
                        }
                    }
                }
            }
       }
   }
}
