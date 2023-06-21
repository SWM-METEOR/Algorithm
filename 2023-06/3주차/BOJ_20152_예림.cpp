// BOJ 20152
#include <iostream>

#define MAX 35
using namespace std;

int h, n;
long long dp[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> n;

    for (int i = 0; i < MAX; i++) dp[i][0] = 1;
    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    int k = abs(n - h);
    cout << dp[k][k];

    return 0;
}
