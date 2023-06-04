// 1182
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;
int n;
int target;
int ans = 0;

void dfs(int idx, int sum) {
    if (idx == n) return;
    if (sum + num[idx] == target) ans++;

    dfs(idx + 1, sum);
    dfs(idx + 1, sum + num[idx]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int temp;

    cin >> n >> target;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        num.push_back(temp);
    }

    dfs(0, 0);

    cout << ans << "\n";

    return 0;
}
