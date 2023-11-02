#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
using namespace std;

int main(){
 //2에서 10까지의 문자열을 슬라이싱하고 반복적으로 확인하여 최대 마디 값 출력
 // 다르면 길이 추가 및 
    int T;
    cin>>T;
    FOR(i,T){
        string S, temp;
        cin>>S;
        temp.push_back(S[0]);
        for(int j =1; j<S.size();j++){
            if(temp != S.substr(temp.size(), temp.size())){
                temp.push_back(S[j]);
            }
            else break;
        }
        cout<<"#"<<i+1<<" "<<temp.size()<<endl;

    }

}