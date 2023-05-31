/* BOJ 14712 넴모넴모(Easy)  - 2023.05.31 */
#include <bits/stdc++.h>
using namespace std;

int N, M; 
int ans = 0;

bool mark[25][25];

void dfs(int r, int c) {
    if(r == N+1 && c == 1) {
        ans += 1;
        return;
    }

    bool flag = mark[r][c-1] && mark[r-1][c-1] && mark[r-1][c];
    int nr = (c == M) ? r+1 : r;
    int nc = (c == M) ? 1 : c+1;

    if(!flag) {
        mark[r][c] = true;
        dfs(nr, nc);
        mark[r][c] = false;
    }

    dfs(nr, nc);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;

    if(N == 1 || M == 1) {
        int exp = max(N, M);
        cout << (1 << exp);
        return 0;
    }

    dfs(1, 1);

    cout << ans << '\n';

    return 0;
}

/*
예외 케이스 - 행 또는 열이 1이라면 언제나 2^(1이아닌 값) 의 경우의 수로 배치 가능

위 경우가 아니라면, 
넴모를 1행 1열부터 열 기준으로 하나씩 놓으며 모든 경우의 수를 수행한다.
이 때, 2 x 2 가 만들어지는 지 확인하고 넴모를 놓았을 때 2 x 2 가 만들어지면 백트래킹을 하지 않는 방식으로 cutting을 수행
*/
