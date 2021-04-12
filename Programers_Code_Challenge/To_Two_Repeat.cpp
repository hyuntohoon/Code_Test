#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
 
using namespace std;
 
int Del_Zero(string S, vector<int> &answer)
{
    int Cnt = 0;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '0')
        {
            Cnt++;
            answer[1]++;
        }
    }
    return S.length() - Cnt;
}
 
 
string To_Two(int N)
{
    string S = "";
    while (N > 0)
    {
        S += ((N % 2) + '0');
        N /= 2;
    }
    reverse(S.begin(),S.end());
    return S;
}
 
vector<int> solution(string s) 
{
    vector<int> answer(2, 0);
    string str = s;
    while (str != "1")
    {
        int len = Del_Zero(str, answer);
        str = To_Two(len);
        answer[0]++;
    }
    return answer;
}