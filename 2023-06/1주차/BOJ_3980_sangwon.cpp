/* BOJ 3980 선발 명단  - 2023.05.29 */
#include <bits/stdc++.h>
using namespace std;

const int N = 11;
int ans = -1;
int ability[15][15];
bool vis[15];

void dfs(int idx, int sum) {
    if(idx == N) {
        ans = max(ans, sum);
        return;
    }

    for(int i=0; i<N; i++) {
        if(ability[i][idx] > 0 && !vis[i]) {
            vis[i] = true;
            dfs(idx+1, sum+ability[i][idx]);
            vis[i] = false;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int C; cin>>C;

    while(C--) {
        //Input
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cin>>ability[i][j];
            }
        }
        
        //Solution
        dfs(0, 0);
        cout << ans << '\n';

        //Initialization for Next Test case
        fill(vis, vis+N+1, false);
        ans = -1;
    }
    
    return 0;
}

/*
1번 포지션부터 가능한 선수들을 하나씩 넣고, 다음 상태로 진행

현재 포지션에 넣을 수 있는 선수는,
능력치가 0보다 크면서 && 앞선 포지션에 배치된 선수만 아니면 가능.
*/
