import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static int []dx = {0,0,1,-1,0,0};
    public static int []dy = {1,-1,0,0,0,0};
    public static int []dz = {0,0,0,0,-1,1};
   public static void main(String[] args) throws IOException {
       /*
       가로 세로 높이가 주어지기 때문에
       지금과 미래를 따로 두어야 함
       지금을 기준으로 미래를 그리고, 미래를 다시 현재로 바꾸고
       토마토는 현재 위치에서 상하 좌우 + 상자위, 상자 아래를 1로 둔다.

        */
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st = new StringTokenizer(br.readLine());
       int N,M,H;
       M = Integer.parseInt(st.nextToken());
       N = Integer.parseInt(st.nextToken());
       H = Integer.parseInt(st.nextToken());
       int [][][]arr = new int[N][M][H];
       Queue<int[]> q = new LinkedList<>();
       int zero = 0;
       for(int i=0;i<H;i++){
           for(int j=0;j<N;j++){
               st = new StringTokenizer(br.readLine());
               for (int k=0;k<M;k++){
                    arr[j][k][i] = Integer.parseInt(st.nextToken());
                    if(arr[j][k][i] == 1) q.offer(new int[]{j,k,i,0});
                    if(arr[j][k][i] == 0) zero++;
               }
           }
       }
       boolean [][][]visited = new boolean[N][M][H];
       int ans = 0;
       while(!q.isEmpty()){
           int []temp = q.poll();
           int x = temp[0],y = temp[1],z = temp[2], dist = temp[3];
           ans = Math.max(ans,dist);
           for(int i = 0;i<6;i++){
               int nx = x+dx[i];
               int ny = y+dy[i];
               int nz = z+dz[i];
               if(nx>=0 && ny >= 0 && nx < N && ny < M && nz >= 0 && nz < H){
                   if(!visited[nx][ny][nz] && arr[nx][ny][nz] == 0){
                       visited[nx][ny][nz] = true;
                       arr[nx][ny][nz] = 1;
                       zero--;
                       q.add(new int[]{nx,ny,nz,dist+1});
                   }
               }
           }
       }
       if(zero !=0){
           System.out.println(-1);
       }
       else System.out.println(ans);
   }
}
