import java.io.*;
import java.util.*;

public class Main {
    public static int []dx = {0,0,-1,1};
    public static int []dy = {-1,1,0,0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        int [][]arr = new int[N][N];
        int maxHeight = 0;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                maxHeight = Math.max(maxHeight, arr[i][j]);
            }
        }
        int ans = 0;
        for(int i = 0;i<=maxHeight;i++){
            ans = Math.max(ans,go(i,arr));
        }

        System.out.println(ans);

    }

    private static int go(int height, int[][] arr) {
        boolean[][] visited = new boolean[arr.length][arr.length];
        Queue<int[]> q = new ArrayDeque<>();
        int count = 0;
        for(int i = 0;i<arr.length;i++){
            for(int j = 0;j<arr[i].length;j++){
                if(arr[i][j] > height && !visited[i][j]){
                    q.add(new int[]{i,j});
                    visited[i][j] = true;
                    count++;
                    while(!q.isEmpty()){
                        int[] curr = q.poll();
                        int x = curr[0];
                        int y = curr[1];
                        for(int k = 0;k<4;k++){
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if(nx>=0 && ny>=0 && nx<arr.length && ny<arr.length && arr[nx][ny] > height){
                                if(!visited[nx][ny]){
                                    visited[nx][ny] = true;
                                    q.offer(new int[]{nx,ny});
                                }
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
}