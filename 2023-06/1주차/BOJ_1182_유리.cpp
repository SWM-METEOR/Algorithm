#include <iostream>
#include <vector>
using namespace std;

int n, s, num, cnt;
vector<int> v;

void input() {
  cin >> n >> s;

  for (int i=0; i<n; i++) {
    cin >> num;
    v.push_back(num);
  }
}

void run(int level, int sum) {
  if (level == n){
    if (sum == s) cnt++;
    return;
  }

  run(level + 1, sum);
  run(level + 1, sum + v[level]);
}

int main() {
  input();
  run(0, 0);

  if (s == 0) cnt--; // 문제 조건상 공집합 제외

  cout << cnt;
  return 0;
}
