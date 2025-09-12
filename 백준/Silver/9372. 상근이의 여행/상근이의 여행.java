import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            // 간선 정보는 결과에 영향 없음. 읽기만 하고 버린다.
            for (int i = 0; i < M; i++) br.readLine();
            sb.append(N - 1).append('\n');
        }
        System.out.print(sb.toString());
    }
}