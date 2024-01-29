#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef unsigned long long ull;
using namespace std;

int makeBit(string s) {
    int bit = 0;
    for (int i = 8; i >= 0; i--) {
        bit <<= 1;
        if (s[i] == 'H') bit |= 1;
    }
    return bit;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        string coin;
        bool used[512] = { false };
        int answer = -1;

        for (int i = 0; i < 9; i++) {
            char ch; cin >> ch;
            coin += ch;
        }

        int bit = makeBit(coin);

        queue<int> Q;
        Q.push(bit);
        used[bit] = true;

        bool flag = true;
        while (!Q.empty() && flag) {
            int qsize = Q.size();
            answer++;
            while (qsize--) {
                int cur = Q.front(); Q.pop();
                if (cur == 0 || cur == (1 << 9) - 1) {
                    flag = false;
                    break;
                }
                // 자세한 내용은 맨 아래 Note 참고
                for (int nxt : { 7, 56, 448, 73, 146, 292, 273, 84 }) {
                    int nxtState = cur ^ nxt;
                    if (used[nxtState]) continue;
                    used[nxtState] = true;
                    Q.push(nxtState);
                }
            }
        }
        if (flag) answer = -1;
        cout << answer << '\n';
    }

    return 0;
}

/*
비트 연산자 XOR로 해당 val를 체크하고 갱신하는 방법
유의해야하는 부분은 makebit 부분
해당 함수는 먼저 공간을 만들고,
어떠한 사례에는 1을 넣고, 아니라면 0을 넣는 함수
그리고 이후 비트 연산에서는 ^ 연산자를 활용하여 비트를 갱신함.

이렇게 구성했을 때의 장점은 사례에 있어서 보기 쉽게 알 수 정리할 수 있고,
사례 갱신에 있어서 쉽게 처리할 수 있다.

경우를 나눌 때 하나의 값에 2개의 상황에서만 조절하는 경우 
해당 비트 연산자를 활용한다면 쉽게 갱신할 수 있을 것이다.

다시 풀어볼 것

*/
