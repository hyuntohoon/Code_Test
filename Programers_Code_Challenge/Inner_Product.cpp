#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 1234567890;
    answer = 0;
    while(!a.empty()){
        vector<int>:: iterator iter_a = a.end()-1;
        vector<int>:: iterator iter_b = b.end()-1;
        answer+=(*iter_a)*(*iter_b);
        a.pop_back();
        b.pop_back();
    }
    return answer;
}