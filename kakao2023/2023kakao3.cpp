#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define endl "\n"

using namespace std;
int emoticonDiscount[7];
int emoticonNumber;
vector <pair<int,int> > aa;
void go(int nowEmoNumber, int now, vector<vector<int> > users, vector<int> emoticons){
    if(nowEmoNumber == emoticonNumber){
        int userTotal[101] = {0};
        FOR(i,emoticonNumber){
            FOR(j,users.size()){ // 유저의 사이즈 만큼 실행,
                int emoticonDiscountPersent = 100 - emoticonDiscount[i];
                //cout<<"compare "<<emoticonDiscount[i]<<" "<<users[j][0]<<endl;
                if(emoticonDiscount[i] >= users[j][0]){
                    userTotal[j] += (emoticons[i] * emoticonDiscountPersent)/100;
                    //cout<<"userTotal"<<j<<" "<<emoticonDiscountPersent<<" "<<userTotal[j]<<endl;
                }
            }
        }
        int pulsUser = 0;
        int totalSell = 0;
        FOR(i, nowEmoNumber){
            cout<<emoticonDiscount[i]<<" ";
        }
        cout<<endl;
        FOR(i, users.size()){
            cout<<"userTotal"<<i<<" : "<<userTotal[i]<<endl;
            cout<<"users"<<i<<" : "<<users[i][1]<<endl;
            if(userTotal[i] >= users[i][1]){
                pulsUser++;
            }
            else{
                totalSell+=userTotal[i];
            }
        }
        aa.push_back(make_pair(pulsUser, totalSell));
        cout<<"push : "<<pulsUser<<" "<<totalSell<<endl;
        return;
    }
    for(int i = now; i<5;i++){
        emoticonDiscount[nowEmoNumber] = i*10;
        go(nowEmoNumber+1,now, users, emoticons);
    }
    return;
}
vector<int> solution(vector<vector<int> > users, vector<int> emoticons) {
    vector<int> answer;
    emoticonNumber = emoticons.size();
    go(0, 1, users, emoticons);
    sort(aa.begin(), aa.end());
    cout<<aa[aa.size()-1].first<<" "<<aa[aa.size()-1].second<<endl;
    answer.push_back(aa[0].first);
    answer.push_back(aa[0].second);
    return answer;
}
/*
1. 이모티콘 구매 확인 절차
- 각 이모티콘을 사용자가 할인을 확인하고 구매했을 때의 값을 리턴
- 리턴된 모든 값을 통해서 사용자가 얼마 썼는지 확인
- 총 구매 비용과 최대 구매 비용을 비교하여 플러스 서비스 가입 여부 확인
플러스 가입 x => 총합 구매 비용에 더하기
플러스 가입 o => 가입 인원수 추가

목표 1. 플러스 가입자 최대한 늘리기
    2. 판매액 최대로 늘리기
    
브루트포스 시 예상 시간
이모티콘 7개 * 4개의 할인 퍼센트
4의 7승 => 4, 16 64, 256, 1024, 2048, 4096
    4096 * 100 = 409600개의 확인
*/