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
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
using namespace std;


int star(int i, int j, int n){
	if((i / n) % 3 == 1 && (j / n) % 3 == 1)
		cout << " ";
	else if(n / 3 == 0)
		cout << "*";
	else
		star(i, j, n / 3);
	return 0;
}

int main( ){
	int n;
	cin >> n;
    FOR(i,n){
        FOR(j,n){
			star(i, j, n);
        }
		cout << '\n';
	}
}
