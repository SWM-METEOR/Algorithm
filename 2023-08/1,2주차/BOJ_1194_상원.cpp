/* BOJ 1194 달이 차오른다, 가자. - 2023.08.14*/
#include <bits/stdc++.h>
using namespace std;

int N, M;
char board[55][55];
bool vis[55][55][65];
int dist[55][55][65];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int cache[] = {32, 16, 8, 4, 2, 1};
char door[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
char key[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

int isDoor(char ch) {
    for(int i=0; i<6; i++) {
        if(door[i] == ch) return i;
    }
    return -1;
}

int isKey(char ch) {
    for(int i=0; i<6; i++){
        if(key[i] == ch) return i;
    }
    return -1;
}

int addKey(int num, int state) {
    return state | cache[num];
}

bool hasKey(int num, int state) {
    return state & cache[num];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    
    queue<tuple<int,int,int>> q;

    for(int i=1; i<=N; i++) {
        string s; cin>>s;
        for(int j=1; j<=M; j++) {
            board[i][j] = s[j-1];
            if(board[i][j] == '0') {
                q.push({i, j, 0});
                vis[i][j][0] = true;
            }
        }
    }

    while(!q.empty()) {
        int x, y, z;
        tie(x, y, z) = q.front(); q.pop();

        for(int dir=0; dir<4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z;
            
            if(board[nx][ny] == '#') continue;
            if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
            
            int num;
            if((num = isDoor(board[nx][ny])) != -1) {
                if(vis[nx][ny][nz]) continue;

                if(hasKey(num, nz)) {
                    dist[nx][ny][nz] = dist[x][y][z] + 1;
                    q.push({nx, ny, nz});
                    vis[nx][ny][nz] = true;
                }
                continue;
            }

            if((num = isKey(board[nx][ny])) != -1) {
                nz = addKey(num, z);
                if(vis[nx][ny][nz]) continue;

                dist[nx][ny][nz] = dist[x][y][z] + 1;   
                q.push({nx, ny, nz});
                vis[nx][ny][nz] = true;
                continue;
            }

            if(vis[nx][ny][nz]) continue;
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            q.push({nx, ny, nz});
            vis[nx][ny][nz] = true;

            if(board[nx][ny] == '1') {
                cout << dist[nx][ny][nz];
                return 0;    
            }
        }
    }

    cout << -1;

    return 0;
}
