/* BOJ 17140 이차원 배열과 연산 - 2023.07.26*/
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, M;
int r, c, k;
int A[105][105];

bool cmp(const pair<int,int>& p1, const pair<int,int>& p2) {
    if(p1.Y == p2.Y) {
        return p1.X < p2.X;
    }
    return p1.Y < p2.Y;
}

void func() {


    if(N >= M) { // 행 정렬
        int tmp = -1;

        for(int i=1; i<=N; i++) {
            int freq[105] = {};
            for(int j=1; j<=M; j++) {
                if(A[i][j] == 0) continue;
                freq[A[i][j]] += 1;
            }

            vector<pair<int,int>> v;
            for(int j=1; j<=100; j++) {
                if(freq[j] == 0) continue;
                v.push_back({j, freq[j]});
            }
            
            sort(v.begin(), v.end(), cmp);
            tmp = max(tmp, (int)v.size() * 2);
            
            int limit = min(100, (int)v.size() * 2);

            for(int j=1; j<=100; j++) {
                if(j > (int)v.size() * 2) A[i][j] = 0;
                else A[i][j] = ((j-1) % 2 == 1) ? v[(j-1)/2].Y : v[(j-1)/2].X;
            }
        }

        M = max(M, tmp);
    }else{ //열 정렬
        int tmp = -1;

        for(int j=1; j<=M; j++) {
            int freq[105] = {};
            for(int i=1; i<=N; i++) {
                if(A[i][j] == 0) continue;
                freq[A[i][j]] += 1;
            }

            vector<pair<int,int>> v;
            for(int i=1; i<=100; i++) {
                if(freq[i] == 0) continue;
                v.push_back({i, freq[i]});
            }

            sort(v.begin(), v.end(), cmp);
            tmp = max(tmp, (int)v.size() * 2);

            for(int i=1; i<=100; i++) {
                if(i > (int)v.size() * 2) A[i][j] = 0;
                else A[i][j] = ((i-1) % 2 == 1) ? v[(i-1)/2].Y : v[(i-1)/2].X;  
            }
        }

        N = max(N, tmp);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>r>>c>>k;
    N = M = 3;
    
    for(int i=1; i<=3; i++) {
        for(int j=1; j<=3; j++) {
            cin>>A[i][j];
        }
    }
    
    if(A[r][c] == k) {
        cout << 0;
        return 0;
    }

    int cnt = 0;
    while(cnt <= 100) {
        func();

        cnt++;
        
        if(A[r][c] == k) {
            cout << cnt;
            return 0;
        }
    }
    cout << -1;
    return 0;
}

/*
매번 행 또는 열을 순회하며 빈도 수 체크, 이후 (값, 빈도수) 기준 정렬 후 다시 배열의 대입
*/
