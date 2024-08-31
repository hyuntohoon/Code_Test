import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int[] dx = {0, 0, -1, 1};
    static int[] dy = {1, -1, 0, 0};
    static int N, M, K;
    static int[][] arr;
    static boolean[][][] visit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        arr = new int[N][M];
        visit = new boolean[N][M][K + 1];
        for (int i = 0; i < N; i++) {
            String temp = br.readLine();
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(temp.charAt(j) + "");
            }
        }
        System.out.println(BFS(0, 0));
    }

    public static int BFS(int startX, int startY) {
        Queue<Me> q = new LinkedList<>();
        q.add(new Me(startX, startY, 0, 1));
        visit[startX][startY][0] = true;

        while (!q.isEmpty()) {
            Me nowMe = q.poll();
            int nowX = nowMe.x;
            int nowY = nowMe.y;
            int nowP = nowMe.p;
            int nowCnt = nowMe.cnt;

            if (nowX == N - 1 && nowY == M - 1) {
                return nowCnt;
            }

            for (int i = 0; i < 4; i++) {
                int nx = nowX + dx[i];
                int ny = nowY + dy[i];

                if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                    if (arr[nx][ny] == 0) {
                        if (!visit[nx][ny][nowP]) {
                            visit[nx][ny][nowP] = true;
                            q.add(new Me(nx, ny, nowP, nowCnt + 1));
                        }
                    } else if (arr[nx][ny] == 1 && nowP < K) {
                        if (!visit[nx][ny][nowP + 1]) {
                            visit[nx][ny][nowP + 1] = true;
                            q.add(new Me(nx, ny, nowP + 1, nowCnt + 1));
                        }
                    }
                }
            }
        }
        return -1;
    }

    public static class Me {
        int x, y, p, cnt;

        public Me(int x, int y, int p, int cnt) {
            this.x = x;
            this.y = y;
            this.p = p;
            this.cnt = cnt;
        }
    }
}
