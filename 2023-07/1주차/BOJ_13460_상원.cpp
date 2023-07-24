/* BOJ 13460 구슬 탈출 2 - 2023.07.20*/
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, M;
int ans = 1e3;
char board[15][15];

void rotate(int dir) {
    pair<int,int> red, blue;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(board[i][j] == 'R') red = {i, j};
            if(board[i][j] == 'B') blue = {i, j};
        }
    }

    pair<int,int> dst_red, dst_blue;
    dst_red = red, dst_blue = blue;
    if(dir == 0) {//왼쪽으로
        if(red.X == blue.X && red.Y < blue.Y) 
        {
            //Red
            for(int col = red.Y; col>1; col--) {
                if(board[red.X][col-1] == '.') dst_red.Y -= 1;
                else break;
            }

            if(board[dst_red.X][dst_red.Y-1] == 'O') {
                board[red.X][red.Y] = '.';
            }else{
                board[red.X][red.Y] = '.';
                board[dst_red.X][dst_red.Y] = 'R';
            }
            //Blue
            for(int col = blue.Y; col>1; col--) {
                if(board[blue.X][col-1] == '.') dst_blue.Y -= 1;
                else break;
            }

            if(board[dst_blue.X][dst_blue.Y-1] == 'O') {
                board[blue.X][blue.Y] = '.';
            }else{
                board[blue.X][blue.Y] = '.';
                board[dst_blue.X][dst_blue.Y] = 'B';
            }
        }else{
            //Blue
            for(int col = blue.Y; col>1; col--) {
                if(board[blue.X][col-1] == '.') dst_blue.Y -= 1;
                else break;
            }

            if(board[dst_blue.X][dst_blue.Y-1] == 'O') {
                board[blue.X][blue.Y] = '.';
            }else{
                board[blue.X][blue.Y] = '.';
                board[dst_blue.X][dst_blue.Y] = 'B';
            }
            //Red
            for(int col = red.Y; col>1; col--) {
                if(board[red.X][col-1] == '.') dst_red.Y -= 1;
                else break;
            }

            if(board[dst_red.X][dst_red.Y-1] == 'O') {
                board[red.X][red.Y] = '.';
            }else{
                board[red.X][red.Y] = '.';
                board[dst_red.X][dst_red.Y] = 'R';
            }
        }
        
    }else if(dir == 1) {//오른쪽으로

        if(red.X == blue.X && red.Y > blue.Y)
        {
            //Red
            for(int col = red.Y; col<M; col++) {
                if(board[red.X][col+1] == '.') dst_red.Y += 1;
                else break;
            }

            if(board[dst_red.X][dst_red.Y+1] == 'O') {
                board[red.X][red.Y] = '.';
            }else{
                board[red.X][red.Y] = '.';
                board[dst_red.X][dst_red.Y] = 'R';
            }
            //Blue
            for(int col = blue.Y; col<M; col++) {
                if(board[blue.X][col+1] == '.') dst_blue.Y += 1;
                else break;
            }

            if(board[dst_blue.X][dst_blue.Y+1] == 'O') {
                board[blue.X][blue.Y] = '.';
            }else{
                board[blue.X][blue.Y] = '.';
                board[dst_blue.X][dst_blue.Y] = 'B';
            }
        }else{
            //Blue
            for(int col = blue.Y; col<M; col++) {
                if(board[blue.X][col+1] == '.') dst_blue.Y += 1;
                else break;
            }

            if(board[dst_blue.X][dst_blue.Y+1] == 'O') {
                board[blue.X][blue.Y] = '.';
            }else{
                board[blue.X][blue.Y] = '.';
                board[dst_blue.X][dst_blue.Y] = 'B';
            }
            //Red
            for(int col = red.Y; col<M; col++) {
                if(board[red.X][col+1] == '.') dst_red.Y += 1;
                else break;
            }

            if(board[dst_red.X][dst_red.Y+1] == 'O') {
                board[red.X][red.Y] = '.';
            }else{
                board[red.X][red.Y] = '.';
                board[dst_red.X][dst_red.Y] = 'R';
            }
        }
    }else if(dir == 2) {//위쪽으로
        if(red.Y == blue.Y && red.X < blue.X) 
        {
            //Red
            for(int row = red.X; row>1; row--) {
                if(board[row-1][red.Y] == '.') dst_red.X -= 1;
                else break;
            }

            if(board[dst_red.X-1][dst_red.Y] == 'O') {
                board[red.X][red.Y] = '.';
            }else{
                board[red.X][red.Y] = '.';
                board[dst_red.X][dst_red.Y] = 'R';
            }
            //Blue
            for(int row = blue.X; row>1; row--) {
                if(board[row-1][blue.Y] == '.') dst_blue.X -= 1;
                else break;
            }

            if(board[dst_blue.X-1][dst_blue.Y] == 'O') {
                board[blue.X][blue.Y] = '.';
            }else{
                board[blue.X][blue.Y] = '.';
                board[dst_blue.X][dst_blue.Y] = 'B';
            }
        }else{
            //Blue
            for(int row = blue.X; row>1; row--) {
                if(board[row-1][blue.Y] == '.') dst_blue.X -= 1;
                else break;
            }

            if(board[dst_blue.X-1][dst_blue.Y] == 'O') {
                board[blue.X][blue.Y] = '.';
            }else{
                board[blue.X][blue.Y] = '.';
                board[dst_blue.X][dst_blue.Y] = 'B';
            }
            //Red
            for(int row = red.X; row>1; row--) {
                if(board[row-1][red.Y] == '.') dst_red.X -= 1;
                else break;
            }

            if(board[dst_red.X-1][dst_red.Y] == 'O') {
                board[red.X][red.Y] = '.';
            }else{
                board[red.X][red.Y] = '.';
                board[dst_red.X][dst_red.Y] = 'R';
            }
        }
    }else {//아래로

        if(red.Y == blue.Y && red.X > blue.X) 
        {
            //Red
            for(int row = red.X; row<N; row++) {
                if(board[row+1][red.Y] == '.') dst_red.X += 1;
                else break;
            }

            if(board[dst_red.X+1][dst_red.Y] == 'O') {
                board[red.X][red.Y] = '.';
            }else{
                board[red.X][red.Y] = '.';
                board[dst_red.X][dst_red.Y] = 'R';
            }
            //Blue
            for(int row = blue.X; row<N; row++) {
                if(board[row+1][blue.Y] == '.') dst_blue.X += 1;
                else break;
            }

            if(board[dst_blue.X+1][dst_blue.Y] == 'O') {
                board[blue.X][blue.Y] = '.';
            }else{
                board[blue.X][blue.Y] = '.';
                board[dst_blue.X][dst_blue.Y] = 'B';
            }
        }else{
            //Blue
            for(int row = blue.X; row<N; row++) {
                if(board[row+1][blue.Y] == '.') dst_blue.X += 1;
                else break;
            }

            if(board[dst_blue.X+1][dst_blue.Y] == 'O') {
                board[blue.X][blue.Y] = '.';
            }else{
                board[blue.X][blue.Y] = '.';
                board[dst_blue.X][dst_blue.Y] = 'B';
            }
            //Red
            for(int row = red.X; row<N; row++) {
                if(board[row+1][red.Y] == '.') dst_red.X += 1;
                else break;
            }

            if(board[dst_red.X+1][dst_red.Y] == 'O') {
                board[red.X][red.Y] = '.';
            }else{
                board[red.X][red.Y] = '.';
                board[dst_red.X][dst_red.Y] = 'R';
            }
        }
    }
}

void dfs(int cnt) {
    //Escape Condition
    if(cnt > 10) return;
    bool red = false, blue = false;
    int a, b;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(board[i][j] == 'R') {
                red = true;
            }
            if(board[i][j] == 'B') {
                blue = true;
            }
        }
    }
    if(!red && !blue) return;
    if(!red && blue) {
        ans = min(ans, cnt);
        return;
    }
    if(red && !blue) return;

    //Logic
    char cpy[15][15] = {};

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cpy[i][j] = board[i][j];
        }
    }

    for(int dir=0; dir<4; dir++) {
        rotate(dir);
        dfs(cnt+1);
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                board[i][j] = cpy[i][j];
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
       
    cin>>N>>M;
    for(int i=1; i<=N; i++) {
        string s; cin>>s;
        for(int j=0; j<M; j++) {
            board[i][j+1] = s[j];
        }
    }

    dfs(0);

    cout << ((ans == 1e3) ? -1 : ans) << '\n';    
    return 0;
}

/*
완전 탐색 - 4방향으로 구슬을 전부 이동시킴. N,M <10 이고 최대 10번만 탐색하면 되기 때문.

Edge case : 빨강, 파랑 구슬이 같은 행 또는 열에 있는 경우 주의
*/
