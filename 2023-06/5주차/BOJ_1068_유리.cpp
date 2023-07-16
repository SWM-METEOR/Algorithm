#include <iostream>
using namespace std;

int tree[51][51]; // (y, x): (부모노드, 자식노드) 연결 관계(연결되어 있으면 1)
int n, root, parent, deleteNode, answer;

void dfs(int node) {
    if (node == deleteNode) return;
    bool isLeaf = true; // 리프 노드 여부 

    for (int i=0; i<n; i++) {
        // 자식 노드가 있고, 그 자식노드가 삭제 대상 노드가 아닐 때 탐색
        if (i != deleteNode && tree[node][i] == 1) {
            isLeaf = false;
            dfs(i);
        }
    }
    if (isLeaf == true) answer++;
}

int main() {
    cin >> n;

    // 트리의 연결관계를 이차원 배열에 표시
    for (int i=0; i<n; i++) {
        cin >> parent;
        if (parent == -1) {
            root = i;
        } else {
            // i번째 노드의 부모는 parent
            tree[parent][i] = 1;
        }
    }

    cin >> deleteNode;

    // 루트부터 순회
    dfs(root);
        
    cout << answer;

    return 0;
}
