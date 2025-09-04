import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int[] dx = {-1, 0, 1, 0}; // 0:N, 1:E, 2:S, 3:W
    static int[] dy = { 0, 1, 0,-1};
   public static void main(String[] args) throws IOException {
       /*
       1. 현재 칸 청소
       2. 주변 4칸 청소되지 않은 빈칸 없는 경우
            바라본 방향 유지한채 뒤로 후
            바라보는 방향의 뒤쪽 칸이 벽이라 후진 할 수 없으면 작동 중지
       3. 5칸중 청소되지 않은 빈칸이 있다면
            반시계 90도 회전
            바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈인 경우 전진

       해야할 조건 일단 방향을 저장해야함
        */

       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       int N,M;
       StringTokenizer st = new StringTokenizer(br.readLine());
       N = Integer.parseInt(st.nextToken());
       M = Integer.parseInt(st.nextToken());
       int [][]arr = new int[N][M];
       int sx,sy,di;
       st = new StringTokenizer(br.readLine());
       sx = Integer.parseInt(st.nextToken());
       sy = Integer.parseInt(st.nextToken());
       di = Integer.parseInt(st.nextToken());
       for(int i = 0;i<N;i++) {
           st = new StringTokenizer(br.readLine());
           for(int j = 0;j<M;j++) {
               arr[i][j] = Integer.parseInt(st.nextToken());
           }
       }
       int sum = 0;
       while(true){
           if(arr[sx][sy] == 0) { // 현재칸 청소
               arr[sx][sy] = 2;

               sum++;
           }
               boolean flag = false;
                for(int i =0;i<4;i++) {
                    int nx = sx + dx[i];
                    int ny = sy + dy[i];
                    if(nx>=0 && nx<N && ny>=0 && ny<M && arr[nx][ny] != 1) {
                        if(arr[nx][ny] == 0){
                            flag = true;
                            break;
                        }
                    }
                }
                if(flag){
                    for(int i = 0;i<4;i++) {
                        di = (di + 3) % 4;
                        int nx = sx + dx[di];
                        int ny = sy + dy[di];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] != 1) {
                            if (arr[nx][ny] == 0) {
                                sx = nx;
                                sy = ny;
                                break;
                            }
                        }
                    }
                }
                else{ // 못 찾았으면
                    int back = (di + 2) % 4;                 // 정반대 방향
                    int nx = sx + dx[back], ny = sy + dy[back];
                    // 뒤가 벽(1)이면 종료, 아니면 후진(청소된 2도 통과 가능)
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] != 1) {
                        sx = nx; sy = ny;
                    } else {
                        System.out.println(sum);
                        return;
                    }
                }

       }

   }
}
