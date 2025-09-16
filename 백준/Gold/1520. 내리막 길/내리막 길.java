import java.io.*;
import java.util.*;

public class Main {
    static final int[] dx = {0, 0, -1, 1};
    static final int[] dy = {-1, 1, 0, 0};

    static int N, M;
    static int[][] arr;
    static long[][] dp; // 경로 수 잠재적 커짐 대비

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dp = new long[N][M];
        for (int i = 0; i < N; i++) Arrays.fill(dp[i], -1);

        long answer = dfs(0, 0);
        System.out.println(answer);
    }

    private static long dfs(int x, int y) {
        if (x == N - 1 && y == M - 1) return 1L; // 도착점

        if (dp[x][y] != -1) return dp[x][y]; // 이미 계산함

        long ways = 0L;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k]; // 오타 수정
            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (arr[nx][ny] < arr[x][y]) {
                    ways += dfs(nx, ny);
                }
            }
        }
        dp[x][y] = ways;
        return ways;
    }
}