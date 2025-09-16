import java.io.*;
import java.util.*;

public class Main {
    public static int []dx = {0,0,-1,1};
    public static int []dy = {-1,1,0,0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N,M;
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        int [][]arr = new int[N][M];
        Queue<int[]> q = new LinkedList<>();
        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if(arr[i][j] == 1) q.add(new int[]{i, j,0});
            }
        }
        if(q.size() == N*M){
            System.out.println(0);
            System.exit(0);
        }
        int ans = 0;
        while(!q.isEmpty()) {
            int x = q.peek()[0];
            int y = q.peek()[1];
            int count = q.poll()[2];
            ans = Math.max(ans, count);
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < N && ny < M && arr[nx][ny] == 0) {
                    arr[nx][ny] = 1;
                    q.add(new int[]{nx, ny,count+1});
                }
            }
        }
        boolean flag = false;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(arr[i][j] == 0){
                    flag = true;
                    break;
                }
            }
        }
        if(flag) System.out.println(-1);
        else System.out.println(ans);
    }

}