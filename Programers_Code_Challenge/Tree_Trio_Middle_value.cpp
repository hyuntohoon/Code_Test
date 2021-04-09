#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
vector<vector<int>> Node;
vector<bool> Visit;
int Leaf, Max_Len, Cnt; // 리프 노드번호, 정점간의 최대 길이, 리프 노드의 갯수
 
void DFS(int Cur, int Len, bool T)  // DFS는 임의의 정점으로부터 가장 먼 정점을 구하는 함수
{                                   // 임의의 정점 번호, 현재 노드까지의 길이, T => Flag로 정점 A를 구한 경우와
                                    // A를 구하는 경우로 나누어 함수를 실행하기 위함이다.
    if (Visit[Cur] == true) return;
    if (T == false)
    {
        if (Len > Max_Len)          // 최대 길이 값의 갱신
        {
            Leaf = Cur;
            Max_Len = Len;
        }
    }
    else
    {
        if (Len > Max_Len)          // A에서의 정점을 구하는 과정
        {
            Leaf = Cur;
            Cnt = 1;
            Max_Len = Len;
        }
        else if (Len == Max_Len) Cnt++;     // A에서의 정점이 최대 길이와 같은 경우, 정점의 갯수를 더해준다.
    }
 
    Visit[Cur] = true;
    for (int i = 0; i < Node[Cur].size(); i++)
    {
        int Next = Node[Cur][i];
        DFS(Next, Len + 1, T);
    }
}
 
void Func(int Start, int n, bool T)
{
    Cnt = 0;
    Max_Len = 0;
    Visit.assign(n + 1, false);
 
    DFS(Start, 0, T);
}
 
int solution(int n, vector<vector<int>> edges)
{
    Node.resize(n + 1);
    Visit.resize(n + 1, false);
    for (int i = 0; i < edges.size(); i++)
    {
        int N1 = edges[i][0];
        int N2 = edges[i][1];
        Node[N1].push_back(N2);
        Node[N2].push_back(N1);
    }
 
    Func(1, n, false);
    Func(Leaf, n, true);
    if (Cnt >= 2) return Max_Len;
    else
    {
        Func(Leaf, n, true);
        if (Cnt >= 2) return Max_Len;
        else return Max_Len - 1;
    }
}

/*
프로그래머스 트리 트리오 중간값

먼저 트리에 대해 제대로 모르고 있었다.

트리는 한 정점으로의 가는 방법이 하나만 존재해야한다.
그리고
트리의 지름에 대해 모르고 있었다.

비슷한 유형의 문제를 풀어봤지만
제대로 알고 있지 않았다.

트리의 지름 = 트리 내 정점들 중 가장 긴 거리를 의미한다.
이 지름을 이루는 정점들은 서로의 리프 노드이다.

그렇기 때문에 한 정점으로 부터 가장 먼 정점(A)을 구하고
그 정점으로 부터 가장 먼 정점이 트리의 지름일 수 있다.

이 문제를 풀기 위해서는
관점에 따른 접근이 필요하다.

문제 풀이
	트리의 간선이 주어진다.
	이 트리 내 임의의 정점 3개를 정했을 때
	정점간의 거리 중 중간 값이 최대 값이 나온 값을 구하라

문제를 풀기 위해서는 
트리에 대한 이해가 필요하고, 경우를 줄이기 위해 그리디를 써야한다.

위에서 말한 트리의 지름을 구한 이유는
트리의 지름을 안 경우 중간 값 계산의 경우를 줄일 수 있기 때문이다.

트리의 지름은 두가지 경우로 나뉜다.
1. 지름을 구성하는 정점이 2개인 경우 
2. 지름을 구성하는 정점이 3개 이상인 경우
——————————————————————————————
지름을 구성하는 정점이 2개인 경우
임의의 정점 3개를 지름을 구성하는 정점 a, 정점 b,
두 정점 중(상관없음, a라고 한다면) 하나의 가장 가까운 정점 c
로 정한다.
		가장 긴 길이 => 지름
	 	중간 값 => c와 b의 거리 = 지름 -1
가 정답이 된다.
——————————————————————————————
지름을 구성하는 정점이 3개 이상인 경우
임의의 정점 3개 모두를 지름을 구성하는 정점 3개로 정한다
		가장 긴 길이 = > 지름
		중간 값 => 지름
가 정답이 된다.
——————————————————————————————
그래서 정답을 구하는데 가장 중요한 점은
거리가 가장 먼 정점을 구하는 것이다.
/*


