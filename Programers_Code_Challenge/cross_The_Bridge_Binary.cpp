int solution(vector<int> stones, int k) {
    int answer = 0;
    int start = 1;
    int end = *max_element(stones.begin(), stones.end());
    // 배열 내 최대값
    int mid = 0;

    while (start <= end) {
        // start > end가 되면 끝
        mid = (start + end) / 2;
        // 항상 mid 값은 중간
        // mid => 예비 최대 건널 수 있는 사람
        int zero = 0;
        // 연속 0 등장
        int maxZero = 0;
        // 최대 연속 0 등장
        for (int i = 0; i < stones.size(); ++i) {
            if (stones[i] < mid)
                zero++;
            else {
                maxZero = max(maxZero, zero);
                zero = 0;
            }
        }
        
        maxZero = max(maxZero, zero);
        // 0이 연속 등장한 경우가 < k보다 큰 경우
        if (maxZero < k) {
        // 현재 mid 값이 부족하기 때문에
        // 이분탐색의 start스코프를 mid+1값으로 수정한다.
            answer = mid;
        // 그리고 최대값을 구하는 것이므로
        // 현재 mid 값이 답일 수도 있기 떄문에 업데이트한다.
            start = mid + 1;
        }
        else if (maxZero >= k)
        // 현재 mid 값이 크기 때문에
        // 이분탐색의 end스코프를 mid-1값으로 수정한다.
            end = mid - 1;
    }
    
    return answer;
}

