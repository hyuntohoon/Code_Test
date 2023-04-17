#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include<stdio.h>
#include<fstream>
#include <list>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
using namespace std;

int main()
{
    string str;	
    int m;	
    list<char> order;
    char input;
    char temp;	

    cin >> str;
    cin >> m;

    FOR(i,str.length()) 
        order.push_back(str[i]);
        
    list<char>::iterator it = order.end();

    FOR(i,m)
    {
        cin >> input;

        if (input == 'P')	
        {
            cin >> temp;
            order.insert(it, temp);
        }
        else if (input == 'L')
        {
            if(it!=order.begin())
                it--;
        }
        else if (input == 'D')
        {
            if (it != order.end())
                it++;
        }
        else if (input == 'B')
        {
            if (it != order.begin())
            {
                it = order.erase(--it);
            }
        }

    }

    for (it = order.begin(); it != order.end(); it++)
        cout << *it;


    return 0;
}
