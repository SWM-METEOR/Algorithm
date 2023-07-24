#include <string>
#include <vector>
#include <queue>

using namespace std;

int MAX = 300000;
long long int q1Sum, q2Sum;
queue<int> q1;
queue<int> q2;

int solution(vector<int> queue1, vector<int> queue2) {

    int qSize = queue1.size();

    for (int i=0; i<qSize; i++) {
        q1.push(queue1[i]);
        q1Sum += queue1[i];

        q2.push(queue2[i]);
        q2Sum += queue2[i];
    }

    int answer = 0;

    while(q1Sum != q2Sum) {
        if (answer >= MAX) return -1;
        if (q1Sum > q2Sum) {
            int target = q1.front();
            q1Sum -= target;
            q2Sum += target;
            q1.pop();
            q2.push(target);
        } else {
            int target = q2.front();
            q2Sum -= target;
            q1Sum += target;
            q2.pop();
            q1.push(target);
        }
        answer++;
    }

    return answer;
}
