import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static boolean[][] visited;
    //public static int count;
    public static int N;
    public static int []dx = {0,0,1,-1};
    public static int []dy = {1,-1,0,0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        visited = new boolean[N][N];
        int count = 0;
        StringTokenizer st;
        int [][]arr = new int[N][N];
        for (int i = 0; i < N; i++) {
            String temp = br.readLine();
            for (int j = 0; j < N; j++) {
                arr[i][j] = temp.charAt(j) - '0';
            }
        }

        PriorityQueue <Integer> pq = new PriorityQueue<>();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(arr[i][j] != 0 && !visited[i][j]){
                    count++;
                    pq.add(BFS(arr, new int[] {i,j}));
                }
            }
        }
        System.out.println(count);
        while(!pq.isEmpty()){
            System.out.println(pq.poll());
        }
    }

    public static int BFS(int [][]arr,int []start) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{start[0], start[1]});
        visited[start[0]][start[1]] = true;
        int count = 1;
        while(!q.isEmpty()) {
            int[] temp = q.poll();
            int x = temp[0];
            int y = temp[1];
            for(int i=0;i<4;i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && ny >=0 && nx<N && ny<N){
                    if(!visited[nx][ny]&& arr[nx][ny] == 1){
                        visited[nx][ny] = true;
                        count++;
                        q.add(new int[]{nx, ny});
                    }
                }
            }
        }
        return count;
    }
}