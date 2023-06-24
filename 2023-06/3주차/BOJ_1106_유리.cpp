#include <iostream>
#include <vector>
using namespace std;

int dp[100000]; // 돈을 i만큼 썼을 때 최대 확보 고객
vector<pair<int, int>> v(20); // 각 도시 홍보비용, 얻을 수 있는 고객 수
int c, n, money, customers;

void input() {
    cin >> c >> n;
    for (int i=0; i<n; i++) {
        cin >> money >> customers;
        v[i] = {money, customers};
    }
}

int main() {
    input();

    for (int i=1; 1<=100000; i++) {
        for (int j=0; j<n; j++) {
            // i(쓰는 돈)가 도시 홍보비(ex.3, 1)로 나누어떨어지는 경우
            if (i % v[j].first == 0) {
                dp[i] = max(dp[i], (i/v[j].first)*v[j].second);
            }
            // i(쓰는 돈)이 도시 홍보비(ex. 3, 1)보다 큰 경우, 한단계 전으로 최댓값에 더하기
            if (i >= v[j].first) {
                dp[i] = max(dp[i], dp[i - v[j].first] + v[j].second);
            }

            if (dp[i] >= c) {
                cout << i;
                return 0;
            }
        }
    }

    return 0;
}
