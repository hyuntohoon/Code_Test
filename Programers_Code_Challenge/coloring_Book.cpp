
bool visit[100][100];
queue<pair<int,int>> Q;
int dx[4];
int dy[4];
int M;
int N;
bool range_Check(int x, int y){
    if(x<N && y<M && x>=0 && y>=0){
        return true;
    }
    return false;
}
int BFS(vector<vector<int>> picture){
    int count = 1;
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        FOR(i,4){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(range_Check(nx, ny) && visit[ny][nx] == 0 && (picture[y][x] == picture[ny][nx]) ){
                
                visit[ny][nx] = 1;
                count++;
                /*cout<<"push : "<<ny<<" "<<nx<<endl;
                cout<<"picture : "<<y<<x<<" : "<<picture[y][x]<<" "<<ny<<nx<<" : "<<picture[ny][nx]<<endl;*/
                cout<<endl;
                Q.push(make_pair(nx, ny));
            }
        }
    }
    return count;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    memset(visit,false,sizeof(visit));
    dx[0] = 1;
    dx[1] = -1;
    dx[2] = 0;
    dx[3] = 0;
    dy[0] = 0;
    dy[1] = 0;
    dy[2] = -1;
    dy[3] = 1;
    M = m;
    N = n;
    int area_Count = 0;
    int Max_Count = 0;
    FOR(i,M){
        FOR(j,N){
            if(picture[i][j] != 0 && visit[i][j] == 0){
                //cout<<"push : "<<i<<" "<<j<<endl;
                area_Count++;
                Q.push(make_pair(j, i));
                visit[i][j] = 1;
                Max_Count = max(BFS(picture),Max_Count);
            }
        }
        //cout<<endl;
    }
    vector<int> answer(2);
    answer[0] = area_Count;
    answer[1] = Max_Count;
    cout<<answer[0]<<" "<<answer[1]<<endl;
    return answer;
}

int main(){
    solution(6, 4, {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}});
}
