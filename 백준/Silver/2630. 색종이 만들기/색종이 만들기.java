import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int [][]arr;
    static boolean [][]visited;
   public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       /*
       n을 2의 몇승인지 파악
       3승이라면 총 3번 나눔
       나눌 때 마라
       현재 길이의 /2한 값만큼 확인
       시작위치, 길이, 색깔 넣고 확인
       정사각형이 맞다면 해당 배열 할당 및 색깔에 따라 ++
       그리고 해당 색깔에 따라
        */
       int N = Integer.parseInt(br.readLine());
       arr = new int[N][N];
       visited = new boolean[N][N];
       for(int i = 0; i < N; i++) {
           StringTokenizer st = new StringTokenizer(br.readLine());
           for(int j = 0; j < N; j++) {
               arr[i][j] = Integer.parseInt(st.nextToken());
           }
       }
       int length = N;
       int []sum = new int[2];
       length *= 2;
       while(length != 1){
           length /= 2;
           for(int i = 0;i<N;i+=length) {
               for(int j = 0;j<N;j+=length) {
                   sum[arr[i][j]] += check(i,j,arr[i][j],length);
               }
           }
       }
       for(int i = 0;i<N;i++) {
           for(int j = 0;j<N;j++) {
               if(!visited[i][j]){
                   //System.out.print(i + " " + j+ "");
                   sum[arr[i][j]]++;
               }
           }
           //System.out.println();
       }
       System.out.println(sum[0]);
       System.out.println(sum[1]);
   }
   public static int check(int x,int y, int c, int length){
       for(int i = 0;i<length;i++) {
           int nx = x + i;
           for(int j = 0;j<length;j++) {
               int ny = y + j;
               if(arr[nx][ny] != c || visited[nx][ny]) {
                   return 0;
               }
           }
       }
       for(int i = 0;i<length;i++) {
           int nx = x + i;
           for(int j = 0;j<length;j++) {
               int ny = y + j;
               visited[nx][ny] = true;
           }
       }

       for(int i = 0;i<8;i++) {
           for(int j = 0;j<8;j++) {
              // System.out.print(visited[i][j] + " ");
           }
           //System.out.println();
       }

       // System.out.println(x + " " + y + " " + c + " " + length);
       return 1;
   }
}
