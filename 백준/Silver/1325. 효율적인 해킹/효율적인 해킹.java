import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static ArrayList<Integer>[] adj;
    
    // visitedGen[node]: node가 마지막으로 방문한 BFS 번호
    static int[] visitedGen;
    // 현재 BFS 번호
    static int currentGen;
    
    public static void main(String[] args) throws IOException {
        // 빠른 입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        
        // 인접 리스트 (역방향: B->A)
        adj = new ArrayList[N+1];
        for(int i=1; i<=N; i++){
            adj[i] = new ArrayList<>();
        }
        
        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            // "A B"는 B를 해킹하면 A도 해킹 가능 -> 그래프 B->A
            adj[B].add(A);
        }
        
        visitedGen = new int[N+1];
        currentGen = 0;
        
        int[] dp = new int[N+1]; // dp[i]: i를 해킹했을 때 해킹되는 컴 수
        int maxValue = 0;
        
        // 큐(정적 배열) 준비: 재사용 없이 BFS마다 새로 만들 예정
        //  -> 재사용하려면 조금 더 복잡해지므로, 여기서는 BFS마다 int[] 새로.
        
        for(int i=1; i<=N; i++){
            currentGen++;
            dp[i] = bfs(i);
            if(dp[i] > maxValue) {
                maxValue = dp[i];
            }
        }
        
        // 최대값인 노드들 출력
        for(int i=1; i<=N; i++){
            if(dp[i] == maxValue) sb.append(i).append(' ');
        }
        
        // 한 번에 출력
        System.out.println(sb.toString());
    }
    
    static int bfs(int start) {
        // 큐를 정적 배열로 직접 구현
        int[] queue = new int[N+1];
        int front = 0, rear = 0;
        
        // start로부터 BFS 시작
        queue[rear++] = start;
        visitedGen[start] = currentGen;
        
        int count = 1;
        
        while(front < rear){
            int now = queue[front++];
            
            // now에서 갈 수 있는 모든 노드
            for(int nxt: adj[now]){
                // 아직 방문 안 했다면
                if(visitedGen[nxt] != currentGen){
                    visitedGen[nxt] = currentGen;
                    queue[rear++] = nxt;
                    count++;
                }
            }
        }
        return count;
    }
}
