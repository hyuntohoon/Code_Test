import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static int[] parents;
    public static int[] ranks;
    public static int findP(int i){
        if(parents[i] != i){
            parents[i] = findP(parents[i]);
        }
        return parents[i];
    }
    public static void union(int X, int Y){
        int rootX = findP(X);
        int rootY = findP(Y);
        if(rootX == rootY) return;
        if(ranks[rootX] > ranks[rootY]){
            parents[rootY] = rootX;
        }
        else if(ranks[rootX] < ranks[rootY]){
            parents[rootX] = rootY;
        }
        else{
            parents[rootY] = rootX;
            ranks[rootX]++;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        parents = new int[N];
        ranks = new int[N];
        for(int i = 0; i < N; i++){
            parents[i] = i;
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int findA = findP(a);
            int findB = findP(b);
            if(findA == findB){
                System.out.println(i+1);
                return;
            }
            else{
                union(findA, findB);
            }
        }
        System.out.println(0);
    }
}