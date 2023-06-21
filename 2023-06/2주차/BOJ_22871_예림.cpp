#include <iostream>

#define MAX 5001
using namespace std;

int n;
long long rock[MAX];
long long dp[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> rock[i];
        dp[i] = 2e9;
    }

    // 최댓값의 최솟값
    // k : 돌을 한번 건널 때 쓸 수 있는 힘의 최댓값
    // dp[i] : i번째 돌까지 건너가는 경우, 한번 돌을 건널 때 K의 최솟값

    dp[1] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            long long jump = (i - j) * (1 + abs(rock[i] - rock[j]));
            dp[i] = min(dp[i], max(dp[j], jump));
        }
    }

    cout << dp[n];

    return 0;

}