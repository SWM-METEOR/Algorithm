// 이차원 배열과 연산
#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 101
using namespace std;

struct node {
    int num;
    int cnt;

    node(int NUM, int CNT) : num(NUM), cnt(CNT) {}

    bool operator<(const node &n) const {
        if (n.cnt == cnt) {
            return n.num < num;
        } else {
            return n.cnt < cnt;
        }
    }
};

int arr[MAX][MAX];
int r, c, k;

int sortRow(int rowCnt, int colCnt) {
    int maxCol = -1;
    for (int i = 1; i <= rowCnt; i++) {
        // 각 행
        int maxNum = -1;
        priority_queue<node> pq;
        int chk[MAX];
        fill_n(chk, MAX, 0);
        for (int j = 1; j <= colCnt; j++) {
            if (maxNum < arr[i][j]) maxNum = arr[i][j];  // 나타난 수들 중 가장 큰 수
            if (arr[i][j] != 0) chk[arr[i][j]]++;   // 숫자가 나타난 수 만큼 cnt
            arr[i][j] = 0;
        }
        for (int m = 1; m <= maxNum; m++) {
            if (chk[m] > 0) pq.push(node(m, chk[m]));
        }
        int idx = 1;
        while (!pq.empty()) {
            node node = pq.top();
            pq.pop();
            arr[i][idx++] = node.num;
            arr[i][idx++] = node.cnt;
        }
        if (maxCol < idx - 1) maxCol = idx - 1;
    }
    return maxCol;
}

int sortCol(int rowCnt, int colCnt) {
    int maxRow = -1;
    for (int i = 1; i <= colCnt; i++) {
        // 각 열
        int maxNum = -1;
        priority_queue<node> pq;
        int chk[MAX];
        fill_n(chk, MAX, 0);
        for (int j = 1; j <= rowCnt; j++) {
            if (maxNum < arr[j][i]) maxNum = arr[j][i];
            if (arr[j][i] != 0) chk[arr[j][i]]++;
            arr[j][i] = 0;
        }
        for (int m = 1; m <= maxNum; m++) {
            if (chk[m] > 0) pq.push(node(m, chk[m]));
        }
        int idx = 1;
        while (!pq.empty()) {
            node node = pq.top();
            pq.pop();
            arr[idx++][i] = node.num;
            arr[idx++][i] = node.cnt;
        }
        if (maxRow < idx - 1) maxRow = idx - 1;
    }
    return maxRow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int answer = -1;
    int rowCnt = 3;
    int colCnt = 3;

    cin >> r >> c >> k;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 101; i++) {
        if (arr[r][c] == k) {
            answer = i;
            break;
        } else {
            if (rowCnt >= colCnt) colCnt = sortRow(rowCnt, colCnt); // 행 정렬, 가장 긴 열의 길이 반환
            else rowCnt = sortCol(rowCnt, colCnt);   // 열 정렬, 가장 긴 행의 길이 반환
        }
    }
    cout << answer << "\n";

    return 0;

}
