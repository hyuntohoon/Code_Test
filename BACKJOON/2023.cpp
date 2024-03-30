#include<iostream>
#include<vector>
#include<cmath> // sqrt 함수 사용을 위해 필요
#include<string> // to_string 함수 사용을 위해 필요
#define FOR(i, n) for(int i = 0; i < n; i++)
const int MAX = 10001;
using namespace std;

bool is_prim(string sosoo){
    if(sosoo.empty()) return false; // 빈 문자열 처리
    int temp = stoi(sosoo);
    if(temp < 2) return false; // 1은 소수가 아님, 0과 음수도 처리
    for(int i= 2; i <= sqrt(temp); i++){ // i <= sqrt(temp)로 변경
        if(temp % i == 0){
            return false; // 소수가 아님
        }
    }
    return true; // 소수임
}

void go(int N, int cnt, string sosoo){
    if(cnt == N){
        cout << sosoo << endl;
        return;
    }
    FOR(i, 10){
        string next_sosoo = sosoo + to_string(i); // 오타 수정
        if(is_prim(next_sosoo)) go(N, cnt + 1, next_sosoo);
    }
}

int main(){
    int N;
    cin >> N;
    go(N, 0, "");
}
