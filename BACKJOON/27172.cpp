#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define FOR(i,N) for(int i =0;i<N;i++)
using ll = long long;
using namespace std;

int main() {
	int N;
	cin>>N;
	vector <int> V(N);
	vector <int> score(1000002);
	vector <int> card(1000002);
	FOR(i, N) {
		cin>>V[i];
		card[V[i]] = 1;
	}
	FOR(i, N) {
		for (int j = V[i] * 2; j < 1000001; j += V[i]) {
			if (card[j] == 1) {
				score[V[i]]++;
				score[j]--;
			
			}
		}
	}
	FOR(i,N){
		cout<<score[V[i]]<<" ";
	}
}
