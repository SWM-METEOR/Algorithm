#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int n, m;
int map[1000][1000];
int memo[1000][1000][3]; // 각 자리에 도달하는데 필요한 연료의 최소값, 3번째 값은 온 방향(좌상, 상, 우상)
int ans = INT_MAX;

void input() {
    cin >> n >> m;

    for (int y=0; y<n; y++) {
        for (int x=0; x<m; x++) {
            cin >> map[y][x];
        }
    }
}

// memo 배열 초기화(각 자리에 도달하는데 필요한 연료의 최소값 적용)
void init() {
    for (int y=0; y<n; y++) {
        for (int x=0; x<m; x++) {
            for (int z=0; z<3; z++) {
                memo[y][x][z] = INT_MAX;
            }
        }
    }

    // 맨 윗줄
    for (int x=0; x<m; x++) {
        for (int z=0; z<3; z++) {
            memo[0][x][z] = map[0][x];
        }
    }
}

void dp() {
    // (y, x) 위치의 세 방향에서의 memo값 채우기
    for (int y=1; y<n; y++) {
        for (int x=0; x<m; x++) {
            if (x == 0) {
                memo[y][x][0] = min(memo[y-1][x][1], memo[y-1][x + 1][2]) + map[y][x];
                memo[y][x][1] = memo[y-1][x + 1][2] + map[y][x];
                memo[y][x][2] = memo[y-1][x][1] + map[y][x];
            } else if (x == m-1) {
                memo[y][x][0] = memo[y-1][x][1] + map[y][x];
                memo[y][x][1] = memo[y-1][x - 1][0] + map[y][x];
                memo[y][x][2] = min(memo[y-1][x - 1][0], memo[y-1][x][1]) + map[y][x];
            } else {
                memo[y][x][0] = min(memo[y-1][x][1], memo[y-1][x + 1][2]) + map[y][x];
                memo[y][x][1] = min(memo[y-1][x - 1][0], memo[y-1][x + 1][2]) + map[y][x];
                memo[y][x][2] = min(memo[y-1][x - 1][0], memo[y-1][x][1]) + map[y][x];
            }
        }
    }
    
}

// 중요 조건: 한 방향으로 연속 이동 불가 -> 3차원 배열 필요
int main() {
    input();
    init(); // 초기화
    dp();

    for (int i=0; i<m; i++) {
        for (int j=0; j<3; j++) {
            ans = min(ans, memo[n-1][i][j]);
        }
    }

    cout << ans;
    return 0;
}