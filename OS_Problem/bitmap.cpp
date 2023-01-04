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
#include<sstream>
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAX 1000
#define RED 1
#define BLUE 0
#define endl "\n"
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;

ifstream ifs;
ofstream ofs;

string table;
char form, prevs;
int N,M;
int bit_Map[250][250];
int now_Index;
string a;
void output(int garo, int sero){
     FOR(i,garo){
            FOR(j,sero){
                cout<<bit_Map[i][j];
            }
    }
}
void BtoD(int start_X,int start_Y, int end_X, int end_Y){
    int garo = end_X - start_X;
    int sero = end_Y - start_Y;
    int A = bit_Map[start_Y][start_X];
    bool B = 0;
    if(start_X>end_X) return;
    if(start_Y>end_Y) return;
    for(int i = start_Y; i<end_Y;i++){
        for(int j = start_X; i<end_X;j++){
            if(A != bit_Map[sero][garo]){
                a+='D';
                B = 1; // 끝
                break;
            }
        }
        if(B) break;
    } // D인지 아닌지 구분
    if(B == 0) {a += A; return;} // B이면 끝
    int G = (ceil((double)(end_X - start_X + 1)/2)) -1;
    int S = (ceil((double)(end_Y - start_Y + 1)/2)) -1;
    BtoD(start_X, start_Y, start_X+G-1, start_Y+S-1);
    BtoD(start_X+G,start_Y, end_X, start_Y+S-1);
    BtoD(start_X, start_Y+S,start_X+G-1, end_Y);
    BtoD(start_X+G, start_Y+S, end_X, end_Y);
}


void DtoB(int start_X,int start_Y, int end_X, int end_Y){
    int garo = end_X - start_X;
    int sero = end_Y - start_Y;
    int A = bit_Map[start_Y][start_X];
    bool B = 0;
    if(start_X>end_X) return;
    if(start_Y>end_Y) return;
    if(table[now_Index] != 'D'){
        int now_Number = table[now_Index] - '0';
        now_Index++;
        for(int i = start_Y; i<end_Y;i++){
            for(int j = start_X; i<end_Y;j++){
                bit_Map[i][j] = now_Number;
            }
        }
    }
    else if(table[now_Index] == 'D'){
        int G = (ceil((double)(end_X - start_X + 1)/2)) -1;
        int S = (ceil((double)(end_Y - start_Y + 1)/2)) -1;
        DtoB(start_X, start_Y, start_X+G-1, start_Y+S-1);
        DtoB(start_X+G,start_Y, end_X, start_Y+S-1);
        DtoB(start_X, start_Y+S,start_X+G-1, end_Y);
        DtoB(start_X+G,start_Y+S, end_X, end_Y);
    }
}

int main(){
    bool B =0;
    string temp = "";
    while(true){
        if (B == 0) cin >> form;
        B = 0;
        if(form == '#'){        //#이 나올때 끝내기
            break;
        }
        cin >> N >> M;
        table.clear();
        temp.clear();
        if(form == 'D'){
            now_Index = 0;    //datas 인덱스
            a.clear();
            while(true){
                cin >> temp;
                if(temp != "B" && temp !="D" && temp !="#"){
                    table+=temp;
                }
                else {
                    form = temp[0];
                    B = 1;
                    break;
                };
            }
            BtoD(0, N-1, 0, M-1);
            cout << 'B';
            cout.width(4);
            cout.fill(' ');
            cout << right << N;
            cout.width(4);
            cout.fill(' ');
            cout << right << M << '\n';
            FOR(i,N){
                FOR(j,M){
                    a += to_string(bit_Map[i][j]);
                }
            }

            double str_length = a.length();
            double length_Di = ceil((double)a.length() / 50);
            FOR(i,length_Di) {   //
                cout << a.substr(50*i, 50) << endl;
            }
        }


        else{
            for(int dd = 0; dd < (ceil((double)N*M / 50)); dd++){
                cin >> temp;
                table += temp;
            }
            int index = 0;
            FOR(i,N){
                FOR(j,M){
                    bit_Map[i][j] = table[index] - '0';
                    index++;
                }
            }
        }
            a.clear();
            BtoD(0, N-1, 0, M-1);
            cout << 'D';
            cout.width(4);
            cout.fill(' ');
            cout << right << N;
            cout.width(4);
            cout.fill(' ');
            cout << right << M << '\n';
            double length_Di = ceil((double)a.length() / 50);
            FOR(i,length_Di) {   //
                cout << a.substr(50*i, 50) << endl;
            }
        }
    }
