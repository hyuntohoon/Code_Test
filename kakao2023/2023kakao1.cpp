#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define endl "\n"

using namespace std;

int check(vector<string> terms, string privacie){
    char term = privacie[11];
    // 여기서 문자열에서 '.'을 제거합니다.
    privacie.erase(remove(privacie.begin(), privacie.end(), '.'), privacie.end());
    int intPrivacie = stoi(privacie);
    int tempTerm;
    for(auto elem : terms){
        if(elem[0] == term){
            tempTerm = stoi(elem.substr(2,elem.size()-2));
            intPrivacie += tempTerm * 100;
            break;
        }
    }
    if(intPrivacie % 10000 > 1228){
        intPrivacie -= 1200;
        intPrivacie += 10000;
    }
    return intPrivacie;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    // 여기서도 동일하게 문자열에서 '.'을 제거합니다.
    today.erase(remove(today.begin(), today.end(), '.'), today.end());
    int intToday = stoi(today);
    vector<int> checkPrivacies;
    vector<int> answer;
    for(auto elem : privacies){
        checkPrivacies.push_back(check(terms, elem));
    }
    int i = 0;
    for(auto elem : checkPrivacies){
        if(intToday <= elem){
            answer.push_back(i + 1);
        }
        i++;
    }
    return answer;
}

int main(){
    
}
