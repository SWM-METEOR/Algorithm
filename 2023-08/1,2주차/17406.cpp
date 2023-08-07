/* BOJ 17406 배열 돌리기 4 - 2023.08.07*/
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, M, K;
int Origin_A[55][55];
int A[55][55];
int ans = 1e7;

vector<tuple<int,int,int>> v;

void init() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            A[i][j] = Origin_A[i][j];
        }
    }
}

void rotate(int r, int c, int s) {
    int tmp[55][55] = {};

    pair<int,int> tl = {r-s, c-s}; //top left
    pair<int,int> br = {r+s, c+s}; //bottom right

    for(int i=1; i<=s; i++) {
        for(int col=tl.Y; col<br.Y; col++) {
            tmp[tl.X][col+1] = A[tl.X][col];
        } 

        for(int row=tl.X; row<br.X; row++) {
            tmp[row+1][br.Y] = A[row][br.Y];
        }

        for(int col=br.Y; col>tl.Y; col--) {
            tmp[br.X][col-1] = A[br.X][col];
        }

        for(int row=br.X; row>tl.X; row--) {
            tmp[row-1][tl.Y] = A[row][tl.Y];
        }

        tl.X += 1, tl.Y += 1;
        br.X -= 1, br.Y -= 1;
    }
    
    for(int i=r-s; i<=r+s; i++) {
        for(int j=c-s; j<=c+s; j++) {
            if(i == r && j == c) continue;
            A[i][j] = tmp[i][j];
        }
    }
}

int calc() {
    int mn = 1e7;
    for(int i=1; i<=N; i++) {
        mn = min(mn, accumulate(A[i], A[i]+M+1, 0));
    }
    
    return mn;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M>>K;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >> A[i][j];
            Origin_A[i][j] = A[i][j];
        }
    }
    
    while(K--) {
        int r, c, s; cin>>r>>c>>s;

        v.push_back({r,c,s});
    }
    
    sort(v.begin(), v.end());

    do{
        for(const auto& tp : v) {
            int r, c, s;
            tie(r, c, s) = tp;

            rotate(r, c, s);
        }
        ans = min(ans, calc());
    
        init();

    }while(next_permutation(v.begin(), v.end()));
    
    cout << ans;
    return 0;
}

/*

*/
