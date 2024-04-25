#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> adj(N+1);
    vector<int> visit(N+1, 0);

    for (int i = 0; i < N-1; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    queue<int> Q;
    Q.push(1);
    visit[1] = 1;

    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (auto elem : adj[now]) {
            if (visit[elem] == 0) {
                visit[elem] = now;
                Q.push(elem);
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << visit[i] << "\n";
    }
}11
