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
ofstream ofs;
ifstream ifs;
int N;
int max1,max2,min1,min2;



void running(){
    ifs>>N;
    max1 = 0;
    max2 = 0;
    min1 = 1234567890;
    min2 = 1234567890;
    FOR(i,N){

    }
}
int main(){
    int T;
    ifs.open("stairs.inp");
    ofs.open("stairs.out");
    ifs>>T;
    FOR(i,T){
        running();
    }
   
    ifs.close();
    ofs.close();
}