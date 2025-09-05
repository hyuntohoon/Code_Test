import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static int []parents;
    public static int []rank;
   public static void main(String[] args) throws Exception {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

     int N = Integer.parseInt(br.readLine());
     int M = Integer.parseInt(br.readLine());
       parents = new int[N+1];
       rank = new int[N+1];
       for(int i = 0; i <= N; i++) {
           parents[i] = i;
       }
       StringTokenizer st;
       for(int i =0;i<N;i++){
           st = new StringTokenizer(br.readLine());
           for(int j =0;j<N;j++){
               int temp = Integer.parseInt(st.nextToken());
               if(temp == 1){
                   union(i+1,j+1);
               }
           }
       }
       st = new StringTokenizer(br.readLine());
       int first = Integer.parseInt(st.nextToken());
       int tmp = findP(first);
       for(int i = 1;i<M;i++){
           int nextC = Integer.parseInt(st.nextToken());
           if(tmp != findP(nextC)){
               System.out.println("NO");
               return;
           }
       }
       System.out.println("YES");
   }
   public static int findP(int i){
       if(parents[i] != i){
           parents[i] = findP(parents[i]);
       }
       return parents[i];
   }
    public static void union(int x, int y){
       int rootX = findP(x);
       int rootY = findP(y);
       if(rank[rootX] > rank[rootY]){
            parents[rootY] = rootX;
       }
       if(rank[rootX] < rank[rootY]){
            parents[rootX] = rootY;
       }
       if(rank[rootY] == rank[rootX]){
           parents[rootY] = rootX;
           rank[rootX]++;
       }
    }


}