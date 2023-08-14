// 달이 차오른다, 가자
#include <iostream>
#include <queue>

#define MAX 51
using namespace std;

struct node {
    int x;
    int y;
    int cnt;
    int keySet;

    node(int X, int Y, int CNT, int KEY_SET) : x(X), y(Y), cnt(CNT), keySet(KEY_SET) {}
};

char maze[MAX][MAX];
int xDir[4] = {-1, 1, 0, 0};   // 상, 하, 좌, 우
int yDir[4] = {0, 0, -1, 1};
int n, m;
bool visited[MAX][MAX][1 << 6];   // 특정 열쇠 집합을 가지고 있을 때의 발문 여부 확인

bool canGo(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

bool hasKey(char c, int keySet) {
    // c 문을 열 수 있는 키를 가지고 있는지 검사
    int set = c - 'A';
    return keySet & (1 << set);
}

int getKey(char c, int keySet) {
    // 새로운 키를 주웠을 때
    int set = c - 'a';
    return keySet | (1 << set);
}

int bfs(int x, int y) {
    queue<node> q;
    q.push(node(x, y, 0, 0));
    visited[x][y][0] = true;

    while (!q.empty()) {
        node cur = q.front();
        int curX = cur.x;
        int curY = cur.y;
        int curCnt = cur.cnt;
        int curKeySet = cur.keySet;
        q.pop();

        if (maze[curX][curY] == '1') {
            return curCnt;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = curX + xDir[i];
            int nextY = curY + yDir[i];
            if (canGo(nextX, nextY) && !visited[nextX][nextY][curKeySet]) {
                if (maze[nextX][nextY] == '.' || maze[nextX][nextY] == '1') {
                    // 그냥 갈 수 있는 길
                    visited[nextX][nextY][curKeySet] = true;
                    q.push(node(nextX, nextY, curCnt + 1, curKeySet));
                } else if (maze[nextX][nextY] >= 'a' && maze[nextX][nextY] <= 'f') {
                    // 열쇠가 있는 길
                    int tempKeySet = getKey(maze[nextX][nextY], curKeySet);
                    visited[nextX][nextY][tempKeySet] = true;
                    q.push(node(nextX, nextY, curCnt + 1, tempKeySet));
                } else if (maze[nextX][nextY] >= 'A' && maze[nextX][nextY] <= 'F') {
                    // 문이 있는 길
                    if (hasKey(maze[nextX][nextY], curKeySet)) {
                        visited[nextX][nextY][curKeySet] = true;
                        q.push(node(nextX, nextY, curCnt + 1, curKeySet));
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    char c;
    int startX, startY;
    vector<bool> hasKey(6, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            maze[i][j] = c;
            if (c == '0') {
                // 민식이의 출발 위치
                startX = i;
                startY = j;
                maze[i][j] = '.';
            }
        }
    }

    int ans = bfs(startX, startY);

    cout << ans << "\n";

    return 0;
}
