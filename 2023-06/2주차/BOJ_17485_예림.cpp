#include <iostream>
#include <algorithm>

#define MAX 1001
#define INF 1e9
using namespace std;

int n, m;
int space[MAX][MAX];
int dp[MAX][MAX][3];   // 3개의 방향 중 하나를 선택했을 때의 최소 경로

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int minAns = INF;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> space[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        dp[0][i][0] = space[0][i];
        dp[0][i][1] = space[0][i];
        dp[0][i][2] = space[0][i];
    }
    // dp[a][b][c] : (a, b)로 윗 행에서 k 방향으로 이동했을 때의 최단경로
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0) {
                // 왼쪽 맨 끝
                dp[i][j][0] = INF;   // 오는 길이 존재하지 않음
                dp[i][j][1] = dp[i - 1][j][2] + space[i][j];
                dp[i][j][2] = min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + space[i][j];
            } else if (j == m - 1) {
                // 오른쪽 맨 끝
                dp[i][j][0] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + space[i][j];
                dp[i][j][1] = dp[i - 1][j][0] + space[i][j];
                dp[i][j][2] = INF;
            } else {
                dp[i][j][0] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + space[i][j];
                dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + space[i][j];
                dp[i][j][2] = min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + space[i][j];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (minAns > dp[n - 1][i][0]) minAns = dp[n - 1][i][0];
        if (minAns > dp[n - 1][i][1]) minAns = dp[n - 1][i][1];
        if (minAns > dp[n - 1][i][2]) minAns = dp[n - 1][i][2];
    }

    cout << minAns;

    return 0;

}
