import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static int[] parent;
    public static int[] rank;
    public static int N,M;
   public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());
      parent = new int[N+1];
      for (int i = 1; i <= N; i++) {
          parent[i] = i;
      }
      rank = new int[N+1];
      for(int i=0;i<M;i++){
          st = new StringTokenizer(br.readLine());
          int temp = Integer.parseInt(st.nextToken());
          int a = Integer.parseInt(st.nextToken());
          int b = Integer.parseInt(st.nextToken());
          if(temp == 0){
            union(a,b);
          }
          if(temp == 1){
            if(findP(a) == findP(b)) System.out.println("YES");
            else System.out.println("NO");
          }
      }
   }
   public static int findP(int x){
       if(parent[x] != x){ // 부모가 아니면
           parent[x] = findP(parent[x]);
       }
       return parent[x];
   }
   public static void union(int x, int y){
      int rootX = findP(x);
      int rootY = findP(y);
      if(rootX != rootY){
          if(rank[rootX] > rank[rootY]){
              parent[rootY] = rootX;
          }
          else if(rank[rootX]>rank[rootY]) parent[rootX] = rootY;
          else{
              parent[rootX] = rootY;
              rank[rootX]++;
          }
      }
   }
}
