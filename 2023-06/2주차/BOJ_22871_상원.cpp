/* BOJ 22871 징검다리 건너기(Large) - 2023.06.05 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N; 
const ll INF = 1e10;
ll A[5005], dp[5005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=1; i<=N; i++) cin>>A[i];

    fill(dp+2, dp+N+1, INF);

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=i-1; j++) {
            ll jmp = (ll)(i-j) * (1LL + abs(A[i] - A[j]));
            dp[i] = min(dp[i], max(dp[j], jmp));
        }
    }

    cout << dp[N];
    return 0;
}

/*
dp[N] : N번째 돌까지 도달 할 때, 최소 K값

dp[N] : 1 ~ N-1 번째 돌 각각에 대해 max(현재 최소 K값, N번째 돌까지 이동하는 비용)을 계산하고, 이 들 중 가장 작은 값
*/
