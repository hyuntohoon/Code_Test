package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main_4991_jh {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        int a = 0;
        int ans = 987654321;
        for(int i = 0;i<S.length();i++) if(S.charAt(i) == 'a') a++;
        
        for(int i=0;i<S.length();i++){
            int b = 0;
            for(int j=i;j<i+a;j++){
                if(S.charAt(j%S.length()) == 'b') b++;
            }
            ans = Math.min(b,ans);
        }
        System.out.println(ans);
    }
}
