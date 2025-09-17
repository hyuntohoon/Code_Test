import java.io.*;
import java.util.StringTokenizer;

public class Main {
    // 필요하다면 남겨도 되지만, 이 문제엔 사용 안 함
    public static int[] dx = {0,0,1,-1};
    public static int[] dy = {1,-1,0,0};

    public static String A, B, temp;
    static boolean[][] visited; // (aIndex, bIndex) 방문 메모
    static boolean found;// 이미 정답 찾았는지
    static StringBuilder out;
    static int i;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
         out= new StringBuilder();

        for (i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            A = st.nextToken();
            B = st.nextToken();
            temp = st.nextToken();

            // 길이 합 체크: 애초에 길이가 다르면 불가능
            if (A.length() + B.length() != temp.length()) {
                out.append("Data set " + (i+1) + ": no\n");
                continue;
            }

            visited = new boolean[A.length() + 1][B.length() + 1];
            found = false;

            DFSA(0, 0, 0);

            if (!found) out.append("Data set " + (i+1) + ": no\n");
        }
        System.out.print(out.toString());
    }

    // 한 함수(DFSA)에서 A, B 모두 시도 (진행 없는 호출 제거)
    private static void DFSA(int aIndex, int bIndex, int tempIndex) {
        if (found) return; // 이미 yes 찍었으면 더 탐색 X

        // 현재까지 채운 길이로 종료 체크
        if (aIndex + bIndex == temp.length()) {
            found = true;
            out.append("Data set " + (i+1) + ": yes\n");
            return;
        }

        // 같은 상태 재방문 방지
        if (visited[aIndex][bIndex]) return;
        visited[aIndex][bIndex] = true;

        char need = temp.charAt(tempIndex);

        // A에서 한 글자 가져오기
        if (aIndex < A.length() && A.charAt(aIndex) == need) {
            DFSA(aIndex + 1, bIndex, tempIndex + 1);
        }
        // B에서 한 글자 가져오기
        if (bIndex < B.length() && B.charAt(bIndex) == need) {
            DFSA(aIndex, bIndex + 1, tempIndex + 1);
        }
    }
}