#include <iostream>
#include <climits>
using namespace std;

using ll = long long;
int n;
ll A[5000], dp[5000];

int main() {
    // 돌의 개수 n개, 각 돌에 부여된 숫자 A[i]
    // i -> j 이동 시 드는 힘: (j - i) * (1 + abs(A[i] - A[j]))

    // input
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> A[i];
        // init
        dp[i] = LLONG_MAX;
    }

    dp[0] = 0;

    // i -> j 이동, dp[j] 갱신
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            // dp[j]: j번쨰 돌까지 건널때의 k의 최소값
            dp[j] = min(dp[j], max(dp[i], (j - i) * (1 + abs(A[i] - A[j]))));
        }
    }
    
    cout << dp[n-1];

    return 0;
}