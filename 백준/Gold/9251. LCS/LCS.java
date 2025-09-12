import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String A = br.readLine();
        String B = br.readLine();
        int [][]DP =new int[A.length()+1][B.length()+1];
        for(int i = 1;i<=A.length();i++){
            for(int j = 1;j<=B.length();j++){
                if(A.charAt(i-1)==B.charAt(j-1)){
                    DP[i][j] = DP[i-1][j-1]+1;
                }
                else DP[i][j] = Math.max(DP[i-1][j],DP[i][j-1]);
            }
        }
        System.out.println(DP[A.length()][B.length()]);
    }
}