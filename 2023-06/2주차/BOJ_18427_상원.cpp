/* BOJ 18427 함께 블록 쌓기 - 2023.06.09 */
#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;

int N, M, H;
int dp[55][1005];
vector<vector<int>> v;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M>>H;
    v.resize(N);
    string s; getline(cin, s);

    for(int i=0; i<N; i++) {
        getline(cin, s);

        stringstream ss(s); 
        string tmp;
        while(getline(ss, tmp, ' ')){
            v[i].push_back(stoi(tmp));
        }
        sort(v[i].begin(), v[i].end());
    }    

    for(int i=0; i<v[0].size(); i++) dp[0][v[0][i]] = 1;
    for(int i=0; i<N; i++) dp[i][0] = 1;

    for(int i=1; i<N; i++) {
        for(int j=1; j<=H; j++) {
            dp[i][j] = dp[i-1][j];
            for(int k=0; k<v[i].size(); k++) {
                if(j - v[i][k] < 0) continue;

                dp[i][j] += dp[i-1][j-v[i][k]];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[N-1][H] % MOD;
    return 0;
}

/*
Knapsack Problem

dp[i][j] : i번째 까지 고려했을 때, 무게 j를 만들 수 있는 경우의 수
다만, 이 문제는 각 단계에서 사용할 수 있는 블록이 최대 M개 이므로 이 부분의 코드만 추가되었음.

dp[i][j] += dp[i-1][j- cur] // cur : 현재 쌓으려는 블록 높이
*/
