import java.io.*;
import java.util.*;

public class Main {
    public static int []parents;
    public static int []rank;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        parents = new int[N+1];
        rank = new int[N+1];
        int M = Integer.parseInt(st.nextToken());
        for(int i = 1; i <= N; i++) {
            parents[i] = i;
        }
        for(int i =0;i<M;i++){
            st = new StringTokenizer(br.readLine());
            int tiger = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if(tiger==1){
                if(findP(a) == findP(b)) System.out.println("YES");
                else System.out.println("NO");
            }
            else if(tiger==0){
                unionA(a,b);
            }
        }
    }

    private static void unionA(int a, int b) {
        int rootA = findP(a);
        int rootB = findP(b);
        if(rootA==rootB) return;
        if(rank[rootA] > rank[rootB]){
            parents[rootB]=rootA;
        }
        else if (rank[rootA] < rank[rootB]){
            parents[rootA]=rootB;
        }
        else{
            parents[rootA]=rootB;
            rank[rootB]++;
        }
    }

    private static int findP(int a) {
        if(parents[a] != a){
            parents[a] = findP(parents[a]);
        }
        return parents[a];
    }
}