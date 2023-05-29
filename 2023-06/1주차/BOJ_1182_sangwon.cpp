/* BOJ 1182 부분 수열의 합  - 2023.05.29 */
#include <bits/stdc++.h>
using namespace std;

int ans;
int N, S; 
int A[25];

void dfs(int idx, int sum) {
    if(idx == N) return;
    if(sum + A[idx] == S) ans += 1;

    dfs(idx+1, sum+A[idx]);
    dfs(idx+1, sum);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>S;

    for(int i=0; i<N; i++) cin>>A[i];

    dfs(0, 0);

    cout << ans;
    return 0;
}
