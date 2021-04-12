#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    vector<int> left = a;
    vector<int> right = a;
    int M = 1111111111;
    for(int i=0;i<a.size();i++){
        if(M>left[i]){
            M = left[i];
        }
        else{
            left[i] = M;
        }
    }
    M = 1111111111;
     for(int i=a.size()-1;i>-1;i--){
        if(M>right[i]){
            M = right[i];
        }
        else{
            right[i] = M;
        }
    }
        int answer = a.size();
    for(int i=1;i<a.size()-1;i++){ // 1 ~ N-2까지
        if(a[i]>left[i-1] && a[i]>right[i+1]){
            answer--;
        } 
        
    }
    return answer;
}