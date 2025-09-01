import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static String[][] a;
    static long[][] dpMin, dpMax;
    static final long INF = (long)1e18;

    static boolean inb(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < N;
    }

    static long apply(long base, char op, long v) {
        if (op == '+') return base + v;
        if (op == '-') return base - v;
        return base * v; // '*'
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine().trim());
        a = new String[N][N];
        for (int i = 0; i < N; i++) {
            a[i] = br.readLine().trim().split(" ");
        }

        dpMin = new long[N][N];
        dpMax = new long[N][N];
        for (int i = 0; i < N; i++) {
            Arrays.fill(dpMin[i], +INF);
            Arrays.fill(dpMax[i], -INF);
        }

        // 시작(0,0)은 숫자칸
        dpMin[0][0] = dpMax[0][0] = Long.parseLong(a[0][0]);

        int[][] step = {{0,1},{1,0}}; // 오른쪽/아래

        // 숫자칸에서만 전파: 숫자 -> 연산자 -> 숫자
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if ((r + c) % 2 != 0) continue;      // 연산자칸 skip
                if (dpMin[r][c] == INF) continue;     // 도달 못한 숫자칸

                for (int[] d1 : step) {
                    int r1 = r + d1[0], c1 = c + d1[1];
                    if (!inb(r1, c1)) continue;
                    if ((r1 + c1) % 2 != 1) continue;  // 연산자여야
                    char op = a[r1][c1].charAt(0);

                    for (int[] d2 : step) {
                        int r2 = r1 + d2[0], c2 = c1 + d2[1];
                        if (!inb(r2, c2)) continue;
                        if ((r2 + c2) % 2 != 0) continue; // 숫자여야

                        long v = Long.parseLong(a[r2][c2]);

                        long cand1 = apply(dpMin[r][c], op, v);
                        long cand2 = apply(dpMax[r][c], op, v);

                        long lo = Math.min(cand1, cand2);
                        long hi = Math.max(cand1, cand2);

                        dpMin[r2][c2] = Math.min(dpMin[r2][c2], lo);
                        dpMax[r2][c2] = Math.max(dpMax[r2][c2], hi);
                    }
                }
            }
        }

        System.out.println(dpMax[N-1][N-1] + " " + dpMin[N-1][N-1]);
    }
}
