import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        Cell[][] matrix = new Cell[R][C];

        for (int i = 0; i < R; i++) {
            String line = br.readLine();
            for (int j = 0; j < C; j++) {
                if (line.charAt(j) == 'O') {
                    matrix[i][j] = new Cell('O', 3);
                } else {
                    matrix[i][j] = new Cell('.', -1);
                }
            }
        }

        for (int time = 1; time <= N; time++) {
            if (time % 2 == 0) {
                plantBombs(matrix, R, C, time);
            } else if (time > 1) {
                explodeBombs(matrix, R, C, time);
            }
        }

        printMatrix(matrix, R, C);
    }

    public static void plantBombs(Cell[][] matrix, int R, int C, int currentTime) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (matrix[i][j].state == '.') {
                    matrix[i][j].state = 'O';
                    matrix[i][j].time = currentTime + 3;
                }
            }
        }
    }

    public static void explodeBombs(Cell[][] matrix, int R, int C, int currentTime) {
        boolean[][] toExplode = new boolean[R][C];
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (matrix[i][j].state == 'O' && matrix[i][j].time == currentTime) {
                    toExplode[i][j] = true;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
                            toExplode[nx][ny] = true;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (toExplode[i][j]) {
                    matrix[i][j].state = '.';
                    matrix[i][j].time = -1;
                }
            }
        }
    }

    public static void printMatrix(Cell[][] matrix, int R, int C) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                sb.append(matrix[i][j].state);
            }
            sb.append("\n");
        }
        System.out.print(sb.toString());
    }

    public static class Cell {
        char state;
        int time;

        Cell(char state, int time) {
            this.state = state;
            this.time = time;
        }
    }
}
