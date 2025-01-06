import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 입력: N과 K
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        // 입력: 수열
        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        // 방문 횟수를 저장하는 배열
        int[] visit = new int[100001];
        int firstPoint = 0, lastPoint = 0;
        int answer = 0;

        while (lastPoint < N) {
            // 윈도우에 숫자를 추가
            visit[arr[lastPoint]]++;

            // 숫자가 K개 초과되면, firstPoint를 이동하여 윈도우를 축소
            while (visit[arr[lastPoint]] > K) {
                visit[arr[firstPoint]]--;
                firstPoint++;
            }

            // 윈도우의 길이를 계산하고 최대값 갱신
            answer = Math.max(answer, lastPoint - firstPoint + 1);

            // lastPoint를 이동해 윈도우 확장
            lastPoint++;
        }

        // 결과 출력
        System.out.println(answer);
    }
}
