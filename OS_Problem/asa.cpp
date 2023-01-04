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

int Fi(int num)
{

   if(num == 1)
      return 1;
   else if( num ==2 )
      return 1;
   else
      return Fi(num-1)+Fi(num-2);

}

int main() {

   int num = 1000;
   //cin >>num;
   cout<<Fi(num)<<endl;
    cout<<"hi"<<endl;
   return 0;

}

