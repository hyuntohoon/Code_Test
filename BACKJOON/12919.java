package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_4991_jh {
    static String S, T;
    static boolean ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        S = br.readLine();
        T = br.readLine();
        ans = false;
        go(T);

        if (ans) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }
    }

    public static void go(String current) {
        if (current.equals(S)) {
            ans = true;
            return;
        }
        if (current.length() <= S.length()) return;

        if (current.charAt(current.length() - 1) == 'A') {
            go(current.substring(0, current.length() - 1));
        }
        if (current.charAt(0) == 'B') {
            StringBuilder sb = new StringBuilder(current.substring(1));
            go(sb.reverse().toString());
        }
    }
}
