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
#define endl "\n"
using namespace std;

int main(){
   int a[1005];
   a[0] = 0; 
   a[1] = 1;
   cout<<0<<" "<<1<<" ";
   for(int i = 2;i<500;i++){
     a[i] = a[i-2]+a[i-1];
     a[i]%=10;
     cout<<a[i]<<" ";
     if(i%60 == 0) cout<<"fin"<<endl;
   }
   cout<<endl<<a[17]<<endl;
   cout<<endl<<a[497]<<endl;
      cout<<endl<<a[18]<<endl;
   cout<<endl<<a[498]<<endl;
}