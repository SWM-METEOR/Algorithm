#include <iostream>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

char map[50][50];
int visited[50][50][64]; // 현재 열쇠 상태를 비트마스크로 표현
int N, M;
struct Node{
  int y, x, cnt;
  int key; // 비트마스크
};
queue<Node> q;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

// door에 해당하는 비트가 1이면 true
bool hasKey(char door, int key) {
  return key & (1 << (door - 'A'));
}

int BFS() {
  while(!q.empty()) {
    Node cur = q.front();
    q.pop();

    char mapVal = map[cur.y][cur.x];

    // 현재 위치가 출구인 경우
    if (mapVal == '1') {
      return cur.cnt;
    }

    // 현재 위치가 열쇠 자리인 경우
    if (mapVal >= 'a' && mapVal <= 'f') {
      cur.key |= (1 << (mapVal - 'a'));
    }

    for (int i=0; i<4; i++) {
      int ny = cur.y + dy[i];
      int nx = cur.x + dx[i];
      if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

      char nextVal = map[ny][nx];
      if (nextVal == '#') continue;
      if (nextVal >= 'A' && nextVal <= 'F' && !hasKey(nextVal, cur.key)) continue;

      // 현재 열쇠 상태에서 방문한 적 있으면, 다시 방문하지 않음
      if (visited[ny][nx][cur.key] == 1) continue;

      // 방문
      visited[ny][nx][cur.key] = 1;
      q.push({ny, nx, cur.cnt + 1, cur.key});
    }
  }
  return -1;
}

void init() {
  cin >> N >> M;

  for (int y=0; y<N; y++) {
    string s;
    cin >> s;
    for (int x=0; x<M; x++) {
      map[y][x] = s[x];
      for (int k=0; k<64; k++) {
        visited[y][x][k] = 0;
      }
      // 민식이의 초기 위치를 큐에 넣기 (방향은 미정이므로 -1)
      if (s[x] == '0') {
        q.push({y, x, 0, 0});
        map[y][x] = '.';
        visited[y][x][0] = 1;
      }
    }
  }
}

int main() {
  init();
  cout << BFS();
  return 0;
}
