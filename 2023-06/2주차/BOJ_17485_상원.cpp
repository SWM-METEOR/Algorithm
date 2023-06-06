/* BOJ 17485 진우의 달 여행 (Large) - 2023.06.06 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
const int INF = 1e9;
int A[1005][1005];
int dp[1005][1005][3];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    //Input
    cin>>N>>M;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin>>A[i][j];
        }
    }
    
    //Initialzation for DP
    for(int i=0; i<N+2; i++) {
        for(int j=0; j<M+2; j++){
            fill(dp[i][j], dp[i][j]+3, INF);
        }
    }

    for(int i=1; i<=M; i++){
        dp[1][i][0] = dp[1][i][1] = dp[1][i][2] = A[1][i];
    }

    //Solve
    for(int i=1; i<N; i++) {
        for(int j=1; j<=M; j++) {

            if(j != M) {
                dp[i+1][j+1][0] = min(dp[i+1][j+1][0], min(dp[i][j][1], dp[i][j][2]) + A[i+1][j+1]);
            }

            if(j != 1) {
                dp[i+1][j-1][2] = min(dp[i+1][j-1][2], min(dp[i][j][0], dp[i][j][1]) + A[i+1][j-1]);
            }
            
            dp[i+1][j][1] = min(dp[i+1][j][1], min(dp[i][j][0], dp[i][j][2]) + A[i+1][j]);
        }
    }
    
    //Answer
    int ans = INF;

    for(int i=1; i<=M; i++) {
        ans = min({ans, dp[N][i][0], dp[N][i][1], dp[N][i][2]});
    }

    cout<<ans;
    return 0;
}

/*
dp[i][j][k] : (i, j) 영역에 k 방향으로 도달했을 때, 사용한 연료의 최솟값
이전에 도달한 방향을 알고 있어야, 연속 두 방향 이동 불가를 체크할 수 있기 때문.

K = 0, 1, 2 (k=0 -> 왼쪽에서 도달, k=1 -> 위에서 도달, k=2 -> 오른쪽에서 도달) 를 이용한 점화식 활용
ex) 
(i, j)이고 k=0 인 경우 (i+1, j) k=1 , (i+1, j-1) k=2의 이동이 가능.
이렇게 (i, j)이고 k=1인 경우 , (i,j) 이고 k=2인 경우도 비슷하게 처리

모든 계산 완료 후, N행의 모든 열에 대해 dp[N][j][0], dp[N][j][1], dp[N][j][2] 중 최솟값이 정답. 
*/
