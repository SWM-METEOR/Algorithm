/* BOJ 1106 호텔 - 2023.06.21 */
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int INF = 1e8;

int C, N;

int dp[25][1105];
pair<int,int> A[25];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>C>>N;

    for(int i=0; i<N; i++) {
        cin>>A[i].X>>A[i].Y;
    }

    for(int i=0; i<N+2; i++) fill(dp[i]+1, dp[i]+C+100, INF);

    for(int i=1; i<=C+100; i++) {
        if(i % A[0].Y != 0) continue;
        
        int needed = i / A[0].Y;
        dp[0][i] = (A[0].X) * needed;
    }

    for(int i=1; i<N; i++) {
        for(int j=1; j<=C+100; j++) {
            
            dp[i][j] = dp[i-1][j];
            
            if(j - A[i].Y < 0 || dp[i][j - A[i].Y] == INF) continue;

            dp[i][j] = min(dp[i][j], dp[i][j-A[i].Y] + A[i].X);
        }
    }

    //Answer
    cout << *min_element(dp[N-1]+C, dp[N-1]+C+100);

    return 0;
}

/*
Knapsack Problem

dp[i][j] : i번째 도시까지 고려했을 때, j명을 수용할 때 드는 최소 비용

A[i].X를 i번째 도시의 비용, A[i].Y를 그 때 증가하는 사람이라고 할 때,
dp[i][j] = min(dp[i-1][j], dp[i][j - A[i].Y] + A[i].X) 점화식을 가진다.

단, dp[i][j] 가 불가능한 경우가 있음에 주의해야한다.
비용의 정수배만큼 사용할 수 있기 때문에 j명을 만들지 못할 수도 있기 때문이다.

또한, 적어도 C명만 늘리면 되므로 C명보다 더 많은 인원이 되어도 돈의 최솟값을 가진다면 그것이 정답이다.
문제 조건에서 각 도시의 홍보 비용으로 얻을 수 있는 고객의 수는 100보다 작거나 같은 자연수이므로,
dp[i][j] 에서 j+100까지 고려해야 정답을 얻을 수 있음.
*/
