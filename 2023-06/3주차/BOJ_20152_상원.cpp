/* BOJ 20152 Game Addiction - 2023.06.15 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int H, N;
int mn, mx;
ll dp[35][35];

inline bool isFlood(int x, int y) {
    return x < y;    
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>H>>N;
    mn = min(H, N);
    mx = max(H, N);
    
    dp[mn][mn] = 1LL;
    for(int i = mn; i <= mx; i++) {
        for(int j = mn; j <= mx; j++) {
            if(isFlood(i, j)) continue;
            
            if(!isFlood(i-1, j) && i > 0) dp[i][j] += dp[i-1][j];
            if(!isFlood(i, j-1) && j > 0) dp[i][j] += dp[i][j-1];
        }
    }
    
    cout << dp[mx][mx];
    return 0;
}

/*
H > N, H < N 와 상관없이 최단 경로로 이동해야 하므로 H > N 인 경우 H < N 으로 바꿔 풀이 진행

항상 최단 경로로 이동해야 하기 때문에, 특정 지점에는 좌측에서 오거나 or 위에서 오는 것만 가능.
따라서 특정 지점 (i, j)에 대해 dp[i][j] += dp[i-1][j], dp[i][j-1] 점화식을 가진다.

하지만 i < j 인 지점은 이동 불가 지점으로 이에 대한 예외 처리를 해주어야 한다.
*/
