#include <iostream>
#include <cstring>
using namespace std;

int c, num, maxSum;
int arr[11][11];
bool isSelected[11]; // 선발된 선수는 1로 체크

void inputMap() {
  for (int y=0; y<11; y++) {
    for (int x=0; x<11; x++) {
      cin >> num;
      arr[y][x] = num;
    }
  }
}

void run(int level, int sum) { // level: 포지션 번호
  if (level == 11) {
    maxSum = max(maxSum, sum);
    return;
  }

  for (int y=0; y<11; y++) {
    int ability = arr[y][level];

    // level번째 포지션에 y번째 선수 선발
    if (ability > 0 && !isSelected[y]) {
      bool tempIsSelected[11] = {};

      memcpy(tempIsSelected, isSelected, sizeof(isSelected));
      isSelected[y] = true;
      run(level + 1, sum + ability);

      memcpy(isSelected, tempIsSelected, sizeof(isSelected));
    }
  }
}

int main() {

  cin >> c; // 테스트 케이스의 개수

  for (int i=0; i<c; i++) {
    // init
    maxSum = 0;
    memset(isSelected, 0, sizeof(isSelected));
    inputMap();

    run(0, 0);
    cout << maxSum << "\n";
  }

  return 0;
}
