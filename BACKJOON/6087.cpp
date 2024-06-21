#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

struct Laser {
    int x, y, dir, reflection_count;
};

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int INF = INT_MAX;

int main() {
    int W, H;
    cin >> W >> H;
    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    int startX, startY, endX, endY;
    bool found_first = false;
    vector<vector<vector<int>>> min_reflections(H, vector<vector<int>>(W, vector<int>(4, INF)));

    // C 위치 찾기
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (grid[y][x] == 'C') {
                if (!found_first) {
                    startX = x;
                    startY = y;
                    found_first = true;
                } else {
                    endX = x;
                    endY = y;
                }
            }
        }
    }

    queue<Laser> Q;
    for (int i = 0; i < 4; i++) {
        Q.push({startX, startY, i, 0});
        min_reflections[startY][startX][i] = 0;
    }

    while (!Q.empty()) {
        auto l = Q.front(); Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = l.x + dx[i];
            int ny = l.y + dy[i];
            int new_reflections = l.reflection_count + (i != l.dir);

            if (nx >= 0 && nx < W && ny >= 0 && ny < H && grid[ny][nx] != '*') {
                if (min_reflections[ny][nx][i] > new_reflections) {
                    min_reflections[ny][nx][i] = new_reflections;
                    Q.push({nx, ny, i, new_reflections});
                }
            }
        }
    }

    int minimum_reflections = INF;
    for (int i = 0; i < 4; i++) {
        minimum_reflections = min(minimum_reflections, min_reflections[endY][endX][i]);
    }

    cout << minimum_reflections;
    return 0;
}
