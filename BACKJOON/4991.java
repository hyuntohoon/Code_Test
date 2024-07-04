package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    private static final int[] dx = {0, 0, -1, 1};
    private static final int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int M = Integer.parseInt(st.nextToken());
            int N = Integer.parseInt(st.nextToken());
            if(M == 0 && N == 0) break;
            String[] gridInput = new String[N];
            int[][] map = new int[N][M];
            int[] start = new int[2];
            int dustCount = 0;

            for (int i = 0; i < N; i++) {
                gridInput[i] = br.readLine();
                for (int j = 0; j < M; j++) {
                    map[i][j] = 0;
                    if (gridInput[i].charAt(j) == 'o') {
                        start[0] = i;
                        start[1] = j;
                    } else if (gridInput[i].charAt(j) == '*') {
                        map[i][j] = ++dustCount;
                    } else if (gridInput[i].charAt(j) == 'x') {
                        map[i][j] = -1;
                    }
                }
            }

            boolean[][][] visited = new boolean[N][M][1 << dustCount];
            Queue<Robot> queue = new LinkedList<>();
            queue.add(new Robot(start[0], start[1], 0, 0));
            visited[start[0]][start[1]][0] = true;
            int ans = -1;
            while (!queue.isEmpty()) {
                Robot current = queue.poll();
                if (current.dustMask == (1 << dustCount) - 1) {
                    ans = current.moves;
                    break;
                }
                for (int i = 0; i < 4; i++) {
                    int nx = current.x + dx[i];
                    int ny = current.y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < N && ny < M && map[nx][ny] != -1) {
                        int newDustMask = current.dustMask;
                        if (map[nx][ny] > 0) {
                            newDustMask |= (1 << (map[nx][ny] - 1));
                        }
                        if (!visited[nx][ny][newDustMask]) {
                            visited[nx][ny][newDustMask] = true;
                            queue.add(new Robot(nx, ny, newDustMask, current.moves + 1));
                        }
                    }
                }
            }
            System.out.println(ans);
        }
    }

    static class Robot {
        int x, y;
        int dustMask; // Bitmask representing which dusts have been cleaned
        int moves;

        public Robot(int x, int y, int dustMask, int moves) {
            this.x = x;
            this.y = y;
            this.dustMask = dustMask;
            this.moves = moves;
        }
    }
}
