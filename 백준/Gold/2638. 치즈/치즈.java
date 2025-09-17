import java.io.*;
import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N,M;
    static int [][]arr;
    static int []dx = {0,0,-1,1};
    static int []dy = {1,-1,0,0};
   public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st = new StringTokenizer(br.readLine());
       N = Integer.parseInt(st.nextToken());
       M = Integer.parseInt(st.nextToken());
       arr = new int[N+2][M+2];
       for(int i=1;i<=N;i++){
           st = new StringTokenizer(br.readLine());
           for(int j=1;j<=M;j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
           }
       }
       Queue<int[]> q = new ArrayDeque<>();

       int [][]visited = new int[N+2][M+2];
      // BFS()
       int time = 0;
       boolean flag = false;
       while(true){
           for(int i=0;i<N+2;i++){
               q.offer(new int[]{i,0,0});
               q.offer(new int[]{0,i,0});
               q.offer(new int[]{i,M,0});
               q.offer(new int[]{N,i,0});
           }
           for(int i= 0;i<N+2;i++){
               for(int j=0;j<M+2;j++){
                   //System.out.print(arr[i][j]+" ");
                   if(arr[i][j] == 1) flag = true;
               }
               //System.out.println();
           }
         //  System.out.println();
           if(!flag){
               break;
           }
           flag = false;
           while(!q.isEmpty()){
               int []temp = q.poll();
               int x = temp[0];
               int y = temp[1];
               int a = temp[2];
               for(int i =0;i<4;i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx>=0 && ny>=0 && nx<N && ny<M){
                        if(visited[nx][ny]>=0){
                            if(arr[nx][ny]==1){
                                visited[nx][ny]++;
                            }
                            else{
                                visited[nx][ny]=-1;
                                q.offer(new int[]{nx,ny,time});
                            }
                        }
                    }
               }


           }

           for(int i=0;i<N+2;i++){
               for(int j=0;j<M+2;j++){
                   if(visited[i][j] >= 2) {
                       arr[i][j] = 0;
                   }
                   visited[i][j]=0;
               }
           }
           time++;
       }
       System.out.println(time);
//
//       for(int i=0;i<N+2;i++){
//           for(int j=0;j<M+2;j++){
//               System.out.print(arr[i][j]+" ");
//           }
//           System.out.println();
//       }
   }
}