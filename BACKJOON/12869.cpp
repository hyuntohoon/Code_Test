#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
#define FOR(i,N) for(int i =0;i<N;i++)
using namespace std;
struct scv
{
	int F,S,T,count;
};
int main(){
int N;
cin>>N;
int SCV[3] = {0,};
FOR(i, N) {
	cin>>SCV[i];
}
vector<vector<int>> M (6,vector<int>(3,0));
M[0] = {9,3,1};
M[1] = { 9,1,3 };
M[2] = {3,9,1};
M[3] = {3,1,9};
M[4] = { 1,3,9 };
M[5] = { 1,9,3 };
queue<scv> Q;
Q.push({ SCV[0],SCV[1],SCV[2],0});
bool visit[61][61][61] = {0,};
while (!Q.empty()) {
	int F = Q.front().F;
	int S = Q.front().S;
	int T = Q.front().T;
	int count =Q.front().count;
	visit[F][S][T] = 1;
	if (F <= 0 && S <= 0 && T <= 0) {
		cout<< count;
		exit(0);
	}
	Q.pop();
	for (auto elem : M) {
		int nowF = max(F - elem[0],0);
		int nowS = max(S - elem[1], 0);
		int nowT = max(T - elem[2], 0);
		if(!visit[nowF][nowS][nowT]){
			visit[nowF][nowS][nowT] = 1;
			Q.push({ nowF,nowS,nowT,count+1});
		}
	}
}
}

