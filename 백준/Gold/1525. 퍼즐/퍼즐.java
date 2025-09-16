import java.io.*;
import java.util.*;

public class Main {
    public static Set <String> visited;
    public static int ans;
    public static class Node{
        int x, y,count;
        String S;
        public Node(int x, int y, int count, String S){
            this.x = x;
            this.y = y;
            this.count = count;
            this.S = S;
        }
    }
   public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st;
       int [][]arr = new int[3][3];
       int nowX = 0;
       int nowY = 0;
       ans = Integer.MAX_VALUE;
       for(int i = 0;i<3;i++){
           st = new StringTokenizer(br.readLine());
           for(int j = 0;j<3;j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
                if(arr[i][j]==0){
                    nowX = i;
                    nowY = j;
                }
           }
       }
        visited = new HashSet<>();
       visited.add(makeString(arr));
        //DFS(nowX,nowY, 0,arr);
        BFS(nowX,nowY, arr);

        if(ans == Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(ans);
   }

    private static void BFS(int startX, int startY, int[][] startArr) {
        // 시작 상태 문자열
        String startS = makeString(startArr);

        Queue<Node> q = new LinkedList<>();
        visited.add(startS);
        q.offer(new Node(startX, startY, 0, startS));

        // 상하좌우 이동 벡터
        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};

        while (!q.isEmpty()) {
            Node cur = q.poll();
            int count = cur.count;
            String S = cur.S;

            // 현재 상태가 목표인지 체크 (BFS이므로 최초 도달이 최단)
            if (isVaild(S)) {
                ans = Math.min(ans, count);
                return;
            }

            int zeroIdx = S.indexOf('0');
            int r = zeroIdx / 3, c = zeroIdx % 3;

            // 빈칸(0)의 상하좌우 이웃만 시도
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= 3 || nc < 0 || nc >= 3) continue;

                int nb = nr * 3 + nc;                // 이웃의 1차원 인덱스
                String next = swap(S, nb, zeroIdx);  // 0과 이웃을 스왑한 새 상태

                if (visited.add(next)) {
                    q.offer(new Node(nr, nc, count + 1, next));
                }
            }
        }
    }

    private static String swap(String s, int i, int nowZero) {
        char []arr = s.toCharArray();
        char temp = arr[i];
        arr[i] = arr[nowZero];
        arr[nowZero] = temp;
        return new String(arr);
    }

    public static String makeString(int [][]arr){
        StringBuilder sb = new StringBuilder(9);
        for(int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                sb.append(arr[i][j]);
            }
        }
        return sb.toString();
    }
//    private static void DFS(int x, int y, int count, int[][] arr) {
//       if(ans <=count) return;
//       if(isVaild(arr)){
//           ans = Math.min(ans,count);
//       }
//        for(int i =0;i<4;i++){
//            int nx = x+dx[i];
//            int ny = y+dy[i];
//            if(nx>=0 && ny>=0 && nx<3 && ny<3){
//                int tmp = arr[nx][ny];
//                arr[nx][ny] = 0;
//                arr[x][y] = tmp;
//                String check = makeString(arr);
//                if(!visited.containsKey(check)){
//                    visited.put(check,true);
//                    DFS(nx,ny,count+1,arr);
//                }
//                arr[nx][ny] = tmp;
//                arr[x][y] = 0;
//            }
//        }
//    }

    private static boolean isVaild(String S) {
        int nowCheck = 1;
        for(int i = 0; i < 8; i++){
            if (S.charAt(i) == (char)('0' + nowCheck)) {
                nowCheck++;
            }
            else return false;
        }
        return true;
    }

}