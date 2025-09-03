import java.io.*;
import java.util.*;

public class Main {
    static int []dx = {0,0,-1,1};
    static int []dy = {1,-1,0,0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N, M;
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int [][]arr = new int[N][M];
        for(int i = 0;i<N;i++){
            String temp = br.readLine();
            for(int j = 0;j<M;j++){
                arr[i][j] = temp.charAt(j)-'0';
            }
        }
        Queue<point> Q = new LinkedList<>();
        boolean [][]visited = new boolean[N][M];
        Q.add(new point(0,0,0));
        while(!Q.isEmpty()){
            point cur = Q.poll();
            if(cur.x == N-1 && cur.y == M-1){
                System.out.println(cur.count+1);
                break;
            }
            for(int i = 0;i<4;i++){
                int x = cur.x+dx[i];
                int y = cur.y+dy[i];
                if(x>=0 && y>=0 && x<N && y<M && !visited[x][y] && arr[x][y] == 1){
                    Q.add(new point(x,y, cur.count+1));

                    visited[x][y] = true;
                }
            }
        }
    }

    public static class point{
        int x, y, count;
        public point(int x, int y, int count){
            this.x = x;
            this.y = y;
            this.count = count;
        }

    }
}