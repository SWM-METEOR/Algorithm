#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, K;
int backup[50][50];
int arr[50][50];
int answer = 1e8;
int visited[6];

// 회전 연산의 정보
struct Node{
  int r, c, s;
};
vector<Node> rotateInfos;
vector<int> v;

void init() {
  cin >> N >> M >> K;

  for (int y=0; y<N; y++) {
    for (int x=0; x<M; x++) {
      cin >> arr[y][x];
    }
  }

  for (int i=0; i<K; i++) {
    int r, c, s;
    cin >> r >> c >> s;
    rotateInfos.push_back({r - 1, c - 1, s});
    v.push_back(i);
  }

  memcpy(backup, arr, sizeof(arr));
}

int getMinValue() {
  int minValue = 1e8;

  for (int y=0; y<N; y++) {
    int sum = 0;
    for (int x=0; x<M; x++) {
      sum += arr[y][x];
    }
    minValue = min(sum, minValue);
  }
  return minValue;
}

// k: 몇번째 연산인지
void rotate(int k) {
  Node rotateInfo = rotateInfos[k];
  int centerY = rotateInfo.r;
  int centerX = rotateInfo.c;
  int s = rotateInfo.s;

  for (int i=1; i<=s; i++) {
    // 윗줄 이동
    int backup = arr[centerY-i][centerX+i];
    for (int x=centerX+i; x>centerX-i; x--) {
      arr[centerY-i][x] = arr[centerY-i][x-1];
    }

    // 왼쪽줄 이동
    for (int y=centerY-i; y<centerY+i; y++) {
      arr[y][centerX-i] = arr[y+1][centerX-i];
    }

    // 아래줄 이동
    for (int x=centerX-i; x<centerX+i; x++) {
      arr[centerY+i][x] = arr[centerY+i][x+1];
    }

    // 오른쪽줄 이동
    for (int y=centerY+i; y>centerY-i; y--) {
      arr[y][centerX+i] = arr[y-1][centerX+i];
    }
    arr[centerY-i+1][centerX+i] = backup;
  }
}

void permutation () {
  do {
    // visited 초기화
    memset(visited, 0, sizeof(visited));

    for (int num: v) {
      if (visited[num] == 1) continue;
      visited[num] = 1;
      rotate(num); // 회전 시키기
      visited[num] = 0;
    }

    // min 값 계산 & answer 갱신
    answer = min(answer, getMinValue());
    memcpy(arr, backup, sizeof(arr));
  } while(next_permutation(v.begin(), v.end()));
}

int main() {
  init();
  permutation();
  cout << answer;
  return 0;
}
