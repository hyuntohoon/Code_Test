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
#include <stdio.h>
#include <fstream>
#include <sstream>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
typedef long long ll;
using namespace std;

int main(){
    int arr[10] = {3426, 6630, 3497, 5065, 2123, 7964, 4369, 7151, 3827, 8051};
    vector <int> V;

    FOR(i,10){
        V.push_back(arr[i]);
    }
    sort(V.begin(),V.end());
    int a= 0;
    FOR(i,10){
        cout<<V[i]<<" ";
    }
    cout<<endl;
    FOR(i,10){
        if(i%2 == 0) {
            cout<<V[i]<<" ";
            a+=V[i];
        }
    }
    cout<<a;

}