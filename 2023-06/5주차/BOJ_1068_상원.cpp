/* BOJ 1068 트리 - 2023.06.26 */
#include <bits/stdc++.h>
using namespace std;

int Root, N;
int ans;
int cut;
vector<int> root;
vector<int> adj[55];

bool isLeaf(int nd) {
    if(adj[nd].size() > 1) return false;
    return adj[nd][0] == cut;
}

void dfs(int cur) {
    if(cur == cut) return;
    for(const auto& nxt : adj[cur]) {
        dfs(nxt);
    }
    if(adj[cur].size() == 0 || isLeaf(cur)) {
        ans += 1;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=1; i<=N; i++) {
        int par; cin>>par;
        if(par == -1) {
            root.push_back(i);
            continue;
        }

        adj[par+1].push_back(i);
    }

    cin>>cut;
    cut++;
    adj[cut].clear();

    for(const auto& nd : root) {
        dfs(nd);
    }

    cout << ans;
    return 0;
}

/*
단절 노드의 자식 개수를 0으로 만들면 된다. 그 후 BFS/DFS로 트리 순회를 진행하여 리프 노드를 계산하면 된다.

하지만, 단절 노드가 부모를 가질 경우 부모에게도 이 노드가 단절되어 있다는 별도의 처리를 해주어야 한다.
리프 노드는 자식 개수가 0인 노드인데 단절 노드 처리를 자식 노드 개수 0으로 초기화 했기 때문에 이 둘을 구분할 수 있어야 한다.
*/
