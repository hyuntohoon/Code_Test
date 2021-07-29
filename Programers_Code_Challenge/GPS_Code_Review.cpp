#include <vector>
 
#define MAX 210
#define INF 2e9
using namespace std;
 
int Min(int A, int B) { if (A < B) return A; return B; }
 
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log)
{
    vector<int> Node[MAX]; // 인접리스트
    vector<vector<int>> DP(k, vector<int>(n + 1, INF)); // 2e9값으로 n+1사이즈만큼 채운 vector<int>로 K개 만큼 채운 DP vector
                                                        // DP[A][B]로 구성했을 때, A => 번째, B => 해당 숫자가 될 때, == A번째에 B가 될 때 수정 횟수
    for (int i = 0; i < edge_list.size(); i++)          // 인접리스트 채우기
    {
        int N1 = edge_list[i][0];
        int N2 = edge_list[i][1];
        Node[N1].push_back(N2);
        Node[N2].push_back(N1);
    }
 
    // DP[A][B] = C : 경로의 A번 지점이 B가 되었을 때, 수정해야 하는 횟수
    // 초기값 = DP[0][gps_log[0]] = 0
    DP[0][gps_log[0]] = 0;
    for (int i = 1; i < k; i++) // time만큼 실행, 첫번째는 상관 X
    {
        for (int Cur = 1; Cur <= n; Cur++)  // DP에 B부분 => 해당 숫자에 대한 것으로 지점 자체의 갯수를 말하는 n만큼 실행
        {
            if (DP[i - 1][Cur] == INF) continue; // DP[i] 이전인 DP[i-1]과 현재 Cur이 연결되어 있지 않다면 continue
            
            for (int j = 0; j < Node[Cur].size(); j++) // 현재 Cur과 연결되어 있는 다른 노드를 찾아봄, 현재 node[cur]의 사이즈만큼 탐색
            {
                int Next = Node[Cur][j];// cur와 연결된 인접 리스트 탐색
                int Alpha = 0;
                if (gps_log[i] != Next) Alpha++; // 오류를 수정할 필요가 있는 경우
                
                DP[i][Next] = Min(DP[i][Next], DP[i - 1][Cur] + Alpha);
                // i번째에 Cur와 연결되어 있는 Next는 DP[i][Next]의 현재 값과
                // i-1번째에 Next와 연결된 Cur의 오류 수정횟수 + 1를 비교하여
                // 최소 값으로 변경한다.
            }
        }
    }
 
    if (DP[k - 1][gps_log[k - 1]] < INF) return DP[k - 1][gps_log[k - 1]];
    return -1;
}
