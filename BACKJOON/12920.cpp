#include<iostream>
#include<vector>
#define FOR(i, n) for(int i = 0; i < n; i++)
const int MAX = 10001;
using namespace std;

int V[MAX];
int C[MAX];
int K[MAX];
int DP[MAX] = {0}; // DP 배열 선언 및 초기화

vector<pair<int, int> > items; // 올바른 꺾쇠 괄호 사용

int main() {
    int N, M;
    cin >> N >> M;
    FOR(i, N) {
        cin >> V[i] >> C[i] >> K[i];
    }

    for(int j = 0; j < N; j++) {
        for(int i = K[j]; i > 0; i >>= 1) {
            int num = i - (i >> 1);
            items.push_back(make_pair(V[j] * num, C[j] * num)); // 무게, 행복
        }
    }
    
    for(auto item : items) { // 벡터를 순회하는 for-each 루프 사용
        for(int w = M; w >= item.first; w--) {
            if(w - item.first >= 0) {
                DP[w] = max(DP[w], DP[w - item.first] + item.second);
            }
        }
    }
    cout << DP[M] << endl; // 최종 결과 출력

    return 0;
}
