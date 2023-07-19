// 두 큐 합 같게 만들기
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(const vector<int> &queue1, const vector<int> &queue2) {
    long long sum1 = 0;
    long long sum2 = 0;
    int answer = 0;
    queue<int> q1;
    queue<int> q2;
    for (auto q: queue1) {
        q1.push(q);
        sum1 += q;
    }
    for (auto q: queue2) {
        sum2 += q;
        q2.push(q);
    }
    int limit = q1.size();
    while (1) {
        if (sum1 > sum2) {
            int f1 = q1.front();
            q1.pop();
            q2.push(f1);
            sum1 -= f1;
            sum2 += f1;
        } else if (sum1 < sum2) {
            int f2 = q2.front();
            q2.pop();
            q1.push(f2);
            sum1 += f2;
            sum2 -= f2;
        } else if (sum2 == sum1)
            break;
        if (answer == limit * 3) {
            answer = -1;
            break;
        }
        answer++;
    }
    return answer;
}

int main() {
    vector<int> queue1;
    vector<int> queue2;

    queue1.push_back(3);
    queue1.push_back(2);
    queue1.push_back(7);
    queue1.push_back(2);

    queue2.push_back(4);
    queue2.push_back(6);
    queue2.push_back(5);
    queue2.push_back(1);

    int answer = solution(queue1, queue2);

    if (answer == 0) cout << -1 << "\n";
    else cout << answer << "\n";

    return 0;
}