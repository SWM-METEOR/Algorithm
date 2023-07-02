/* BOJ 9489 사촌 - 2023.07.02 */
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAX = 1000005;
int N, K;
int par[MAX];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    while(1) {

        //Initialzation
        for(int i=0; i<MAX; i++) par[i] = 0;

        cin>>N>>K;
        if(N == 0) break;

        int A[1005] = {};
        for(int i=0; i<N; i++) cin>>A[i];

        int idx = -1;

        par[A[0]] = -1;
        int pre = A[0];
        for(int i=1; i<N; i++) {
            if(pre == A[0] || pre+1 < A[i]) {
                idx += 1;
            }
            par[A[i]] = A[idx];
            pre = A[i];
        }

        if(par[K] == -1 || par[par[K]] == -1) {
            cout << 0 << endl; //;;
            continue;
        }

        int ans = 0;
        for(int i=0; i<N; i++) {
            if(par[A[i]] == -1 || par[par[A[i]]] == -1) continue;

            if(par[A[i]] != par[K] && par[par[A[i]]] == par[par[K]]) ans += 1;  
        }

        cout << ans << endl;
    }       

    return 0;
}

/*
트리의 사촌이란, 부모 노드가 다르면서 부모와 형제 관계인 노드들의 자식들을 말한다.
따라서, 자신의 부모노드의 부모 노드는 같으나, 부모 노드는 다른 노드들을 모두 찾으면 그것이 사촌이다.

트리의 구성 과정에서 어떤 노드의 부모를 저장하는 par배열 (parent) 을 만들어주었다.
예외로는 루트 노드, depth가 2인 (부모의 부모가 없는) 노드의 정답은 0인 것이 있다.

< 실수한 점>
이 문제는 여러 테스트 케이스가 존재해 정답 출력 후 개행을 해야하는데 38번 줄에서 개행을 까먹어서 계속 틀렸다.
이런 부분을 주의해야 한다.
*/
