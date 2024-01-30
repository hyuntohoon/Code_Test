import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        String[] split = in.readLine().split(" ");
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(split[i]);
        }
        int M = Integer.parseInt(in.readLine());
        for (int i = 0; i < M; i++) {
            String[] split2 = in.readLine().split(" ");
            int S = Integer.parseInt(split2[0]);
            int SN = Integer.parseInt(split2[1]);
            if (S == 1) {
                for (int j = SN; j <= N; j += SN) {
                    arr[j - 1] = arr[j - 1] == 0 ? 1 : 0;
                }
            }
            if (S == 2) {
                int NR = SN - 1;
                int NL = SN - 1;
                arr[NL] = arr[NL] == 0 ? 1 : 0;
                while (true) {
                    NR++;
                    NL--;
                    if (NR >= N || NL < 0 || arr[NR] != arr[NL]) break;
                    arr[NR] = arr[NR] == 0 ? 1 : 0;
                    arr[NL] = arr[NL] == 0 ? 1 : 0;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            System.out.print(arr[i] + " ");
            if ((i + 1) % 20 == 0) System.out.println();
        }
    }
}
