import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int [][]arr;
    static int sx,sy;
    static int sharkSize;
    static int []dx = {1,0,-1,0};
    static int []dy = {0,-1,0,1};
    static int nowEat;
   static public void main(String[] args) throws IOException {
      /*
      1. 시작 아기 상어 크기 2
      2. 자신보다 큰 물고기는 못 지나감
      3. 크기가 같다면 지나갈 수는 있음
      4. 더 이상 이동할 수 없으면 도움 요청
      5. 먹을 수 있는 물고기가 여러 마리면 가장 가까운 곳 가기
      6. 먹으러 갈 때는 반드시 최솟값으로
      7. 가까운 물고기가 많다면 위,그리고 왼쪽으로
      8. 이동은 1초
      9. 크기와 같은 수의 물고기 먹으면 성장

      그러면 시점 마다 상어가 갈 수 있는 모든 물고기 찾기
      다만 깊이가 짧을 수록이기 때문에 12시에서 반시계 방향으로 bfs로 구성
      먹을 수 있는 물고기를 찾는다면 보드 갱신, 상어 크기 갱신
      보드 갱신 => 1. 물고기
       */
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       N = Integer.parseInt(br.readLine());
       sharkSize = 2;
       nowEat = 0;
       arr = new int[N][N];
       for(int i = 0; i < N; i++) {
           StringTokenizer st = new StringTokenizer(br.readLine());
           for(int j = 0; j < N; j++) {
               arr[i][j] = Integer.parseInt(st.nextToken());
               if(arr[i][j] == 9){
                    sx = i;
                    sy = j;
                    arr[i][j] = 0;
               }
           }
       }
       int time = 0;
        while(true){
            int now = findFish();
            if(now == 0){
                System.out.println(time);
                break;
            }
            time += now;
        }

   }
   static public int findFish(){
       Queue<Node> q = new LinkedList<>();
//       System.out.println("now shark : " + sx + " " + sy);
       q.add(new Node(sx,sy,0));
       boolean[][] visited = new boolean[N][N];
       visited[sx][sy] = true;
       int minDist = Integer.MAX_VALUE;
       int tx = -1;
       int ty = -1;
       while(!q.isEmpty()) {
           Node cur = q.poll();
           int x = cur.x;
           int y = cur.y;
           int dist = cur.dist;
           //System.out.println(x + " " + y + " " + dist);
           if(dist > minDist) break;
           if(arr[x][y] > 0 && sharkSize>arr[x][y]){ // 먹을 수 있다면
//               System.out.println("find");
               if(dist < minDist || (dist == minDist && ((x < tx) || (x == tx && y < ty)))){ //최솟값이라면 갱신
                   tx = x;
                   ty = y;
                   minDist = dist;
//                   System.out.println(minDist);
               }
               continue;
           }
           for(int k = 0; k < 4; k++) {
               int nx = x + dx[k];
               int ny = y + dy[k];
               if(nx >= 0 && nx < N && ny >= 0 && ny < N) { // 범위 확인
                   if(!visited[nx][ny]) { // 방문 안 했다면
                        if(arr[nx][ny] <= sharkSize ){ // 이동 가능할 때
                            visited[nx][ny] = true;
                            q.add(new Node(nx,ny,dist+1));
                        }
                   }
               }
           }
       }
       if(minDist == Integer.MAX_VALUE){
           return 0;
       }
       arr[tx][ty] = 0;
       sx = tx;
       sy = ty;
//       System.out.println(tx + " " + ty);
       nowEat++;
       if(nowEat == sharkSize){
           sharkSize++;
           nowEat = 0;
       }
       return minDist;
   }
   static public class Node{
       int x,y,dist;
       Node(int x,int y,int dist){
           this.x = x;
           this.y = y;
           this.dist = dist;
       }
   }
}
