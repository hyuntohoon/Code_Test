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

int main(){ 
    int T;
    cin>>T;
    FOR(i,T){
        int N,M,k,D;
        cin>>N>>M>>k>>D;
        int j = 1;
        int answer = -1;
        int C = ((k * N * M * (M-1) /2) + (N * (N-1) / 2 * M * M));
        while(C*j<=D){
            answer = C * j;
            j++;
        }
        cout<<answer<<endl;
    }
}