#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
using namespace std;

int find_Three(int i){
    int find = 0;
    if(i == 3){
        find++;
    }
    return find;
}

int find_Six(int i){
    int find = 0;
    if(i == 6){
        find++;
    }
    return find;
}

int find_Nine(int i){
    int find = 0;
    if(i == 9){
        find++;
    }
    return find;
}

int main(){
    int N;
    cin>>N;
    int arr[1001];
    for(int i = 1;i<N+1;i++){
        int clap = 0;
        int ten = i%10;
        int bac, chun;
        clap += find_Three(ten);
        clap += find_Six(ten);
        clap += find_Nine(ten);
        if(i>10){
            bac = (i-ten)%100;
            bac /= 10;
            clap += find_Three(bac);
            clap += find_Six(bac);
            clap += find_Nine(bac);
        }
        if(i>100){
            chun = (i-bac-ten)%1000;
            chun /= 100;
            clap += find_Three(chun);
            clap += find_Six(chun);
            clap += find_Nine(chun);
        }

        if(clap == 0){
            cout<<i;
        }
        if(clap != 0){
            FOR(j,clap){
                cout<<"-";
            }
        }
        cout<<" ";
    }

}