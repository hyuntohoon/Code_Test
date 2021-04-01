#include <string>
#include <vector>

using namespace std;

int A;
int arr[1001][1001];

void SNAIL(int N){
    int x = 0, y = 0;
    int F = 1;
    int N_N = 1;
    while(N--){
        if(F == 1){
            while(true){
                if(y==A || arr[y][x] !=0){
                    y--;
                    x++;
                    break;
                }
                arr[y][x] = N_N;
                N_N++;
                y++;
            }
            F=2;
            continue;
        }
        if(F == 2){
            while(true){
                if(x==A || arr[y][x] !=0){
                    x--;
                    x--;
                    y--;
                    break;
                }
                arr[y][x] = N_N;
                N_N++;
                x++;
            }
            F=3;
            continue;
        }
        if(F == 3){
            while(true){
                if(arr[y][x] != 0){
                    //cout<<y<<" "<<x<<endl;
                    x++;
                    y++;
                    y++;
                    break;
                }
                arr[y][x] = N_N;
                N_N++;
                x--;
                y--;
            }
        }
        F=1;
        continue;
    }
}

vector<int> solution(int n) {
    A=n;
    SNAIL(n);
    vector<int> answer;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0){
                break;
            }
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}