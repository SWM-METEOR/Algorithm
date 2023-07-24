#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 10;
int N, M;
char arr[MAX][MAX];
bool visited[MAX][MAX][MAX][MAX];

struct Node {
    int redY, redX, blueY, blueX, level;
};

// direction: 0-상, 1-우, 2-하, 3-좌
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

struct Position {
    int y, x;
};

Position tilt(int y, int x, int dy, int dx) {
    while(arr[y + dy][x + dx] != '#' && arr[y][x] != 'O') {
        y += dy;
        x += dx;
    }
    return {y, x};
}

int bfs(Node node) {
    queue<Node> q;
    q.push(node);
    visited[node.redY][node.redX][node.blueY][node.blueX] = true;

    while(!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.level > 10) break;

        for (int i=0; i<4; i++) {
            Position nextRed = tilt(cur.redY, cur.redX, dy[i], dx[i]);
            Position nextBlue = tilt(cur.blueY, cur.blueX, dy[i], dx[i]);

            if (arr[nextBlue.y][nextBlue.x] == 'O') continue;
            if (arr[nextRed.y][nextRed.x] == 'O') return cur.level;

            // 이동 후 두 공의 자리가 겹친 경우, 공 이동
            if (nextRed.y == nextBlue.y && nextRed.x == nextBlue.x) {
                if (i == 0) { // 상
                    cur.redY > cur.blueY ? nextRed.y++ : nextBlue.y++;
                } else if (i == 1) { // 우
                    cur.redX < cur.blueX ? nextRed.x-- : nextBlue.x--;
                } else if (i == 2) { // 하
                    cur.redY < cur.blueY ? nextRed.y-- : nextBlue.y--;
                } else if (i == 3) { // 좌
                    cur.redX > cur.blueX ? nextRed.x++ : nextBlue.x++;
                }
            }

            if (!visited[nextRed.y][nextRed.x][nextBlue.y][nextBlue.x]) {
                visited[nextRed.y][nextRed.x][nextBlue.y][nextBlue.x] = true;
                q.push({nextRed.y, nextRed.x, nextBlue.y, nextBlue.x, cur.level + 1});
            }
        }
    }
    return -1;
}

int main() {
    int redX, redY, blueY, blueX;
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int y=0; y<N; y++) {
        for (int x=0; x<M; x++) {
            cin >> arr[y][x];

            if (arr[y][x] == 'R') {
                redY = y, redX = x;
                arr[y][x] = '.';
            } else if (arr[y][x] == 'B') {
                blueY = y, blueX = x;
                arr[y][x] = '.';
            }
        }
    }

    int result = bfs({redY, redX, blueY, blueX, 1});
    cout << result;
    return 0;
}
