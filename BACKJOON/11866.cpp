#include<iostream>
#include<queue>
using namespace std;

queue<int> Q;

int main()
{
    int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) Q.push(i);
	cout << "<";
	while (!Q.empty())
	{
		for (int i = 1; i < K; i++)
		{
			Q.push(Q.front()); 
			Q.pop();
		}
		cout << Q.front();
		if (Q.size() != 1) cout << ", ";
		Q.pop();
	}
	cout << ">";

}
