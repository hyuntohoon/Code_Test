import java.io.*;
import java.util.*;

public class Main {
    public static class Node  {
        int x,y;
        public Node(int x,int y){
            this.x=x;
            this.y=y;
        }

    }

    static int[][]dist;
    static int N;
    static int []dx = {0,0,1,-1};
    static int []dy = {1,-1,0,0};
    static int ans;
    static int DFS(int nowX, int nowY, int[][]arr){
        if(dist[nowX][nowY] != 0) return dist[nowX][nowY];
            dist[nowX][nowY]=1;
            for(int k = 0;k<4;k++){
                int nx = nowX + dx[k];
                int ny = nowY + dy[k];

                if (nx >= 0 && ny >= 0 && nx < N && ny < N && arr[nx][ny] > arr[nowX][nowY]) {
                      // DP[x][y] = max(DP[x][y], go(nx,ny, board)+1);
                       dist[nowX][nowY] = Math.max(DFS(nx,ny,arr)+1, dist[nowX][nowY]);
                }
        }
            return dist[nowX][nowY];
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        int [][]arr = new int[N][N];
        ans=0;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dist = new int[N][N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                ans = Math.max(ans,DFS(i,j, arr));
            }
        }
        System.out.println(ans);
    }
}