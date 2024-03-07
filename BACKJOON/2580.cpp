#include <iostream>
#include <vector>
#define FOR(i,n) for(int i =0;i<n;i++)
#define FOR1(i,n) for(int i =1;i<=n;i++)
using namespace std;
int map[10][10];
bool row[10][10];
bool col[10][10];
bool sqa[10][10];
int N;

void go(int cnt){
	int x = cnt/9;
	int y = cnt%9;
	if(cnt==81){
		FOR(i, 9) {
			FOR(j, 9) {
			cout<<map[i][j]<<" ";
			}
			cout<<endl;
		}
		exit(0);
	}
	if(map[x][y] == 0){
		FOR1(i,9){
			if(row[x][i] == 0 && col[y][i] == 0 && sqa[(x/3)*3 + y/3][i] == 0){
				row[x][i] = 1;
				col[y][i] = 1;
				sqa[(x / 3) * 3 + y / 3][i] = 1;
				map[x][y] = i;
				go(cnt+1);
				row[x][i] = 0;
				col[y][i] = 0;
				sqa[(x / 3) * 3 + y / 3][i] = 0;
				map[x][y] = 0;
			}
		}
	}
	else{
		go(cnt+1);
	}
}
int main(){
	FOR(i, 9) {
		FOR(j, 9) {
			cin>>map[i][j];
			if (map[i][j] != 0) {
				row[i][map[i][j]] = 1;
				col[j][map[i][j]] = 1;
				sqa[(i / 3) * 3 + j / 3][map[i][j]] = 1;
			}
		}
	}
	go(0);
}
