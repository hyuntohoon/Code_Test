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

   if(num == 1){
      return 1;
   }
   else if( num ==2 ){
      return 1;
   }
   else{
      return Fi(num-1)%10+Fi(num-2)%10;
   }

}

int main(){
   int a[1005];
   a[0] = 0; 
   a[1] = 1;
   for(int i = 2;i<1004;i++){
     a[i] = a[i-2]+a[i-1];
     a[i]%=10;
     cout<<a[i]<<" ";
   }
}