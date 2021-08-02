#include <string>
#include <vector>
#include <queue>
using namespace std;
 
int solution(vector<int> stones, int k)
{
    int answer = 987654321; // 최소값을 찾기 위한 최대값 초기화
    deque<pair<int, int>> DQ; // first => value, second => index number
    // 구간 내 최대 값 => front.push, 현재 구간 내 최대 값은 아니지만 이후 구간에서 최대 값이 될 수 있는 값 => back.push
    for (int i = 0; i < stones.size(); i++) // stonse.size만큼 탐색
    {
        while (DQ.empty() == false && DQ.front().second < i - k + 1) DQ.pop_front();
        // 비어있지 않고, DQ.front의 index 구간 < 지금 탐색중인 index - k + 1
        // DQ에 들어가 있는 최대값이 현재 구간에 영향을 주는지 판단
        // DQ.front().second = 최대 값의 index, i - k + 1 현재 탐색 중인 index가 영향을 미치는 구간
        // 위는 아닐 경우이며 pop.front
        while (DQ.empty() == false && DQ.back().first < stones[i]) DQ.pop_back();
        // 위 조건이 끝난 경우 => DQ에 들어가있는 숫자 == 현재 탐색중인 구간에 영향이 있다
        // 그러면 2번째 경우인 DQ 안에 값이 최대값인지 알아봐야한다.
        // 최대 값이 아니면 pop을 반복한다. back을 먼저 없애는 이유 => back일 경우가 더 낮은 값이기 때문이다.
        DQ.push_back(make_pair(stones[i], i));
        // 모든 경우를 DQ의 마지막에 넣는다.
        if (i >= k - 1 && DQ.front().first < answer) answer = DQ.front().first;
        // 답 = 구간 내 최대값 중 가장 작은 값
    }
    return answer;
}