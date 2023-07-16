#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll sum1, sum2;
queue<ll> q1, q2;

void makeSum(const vector<int>& queue1, const vector<int>& queue2) {
    for(const auto& e : queue1) {
        sum1 += (ll)e;
        q1.push(e);
    }
    for(const auto& e : queue2) {
        sum2 += (ll)e;
        q2.push(e);
    }    
}

int solution(vector<int> queue1, vector<int> queue2) {
    makeSum(queue1, queue2);
    
    ll cnt = 0;
    ll sz = (ll)queue1.size();
    
    if((sum1 + sum2) % 2) return -1;
    if(sum1 == sum2) return 0;
    
    while(cnt < (sz<<2)) {
        if(q1.empty() || q2.empty()) return -1;
        
        if(sum1 < sum2) {
            ll tmp = q2.front();
            q1.push(tmp);
            q2.pop();
            sum1 += tmp;
            sum2 -= tmp;
        }else {
            ll tmp = q1.front();
            q2.push(tmp);
            q1.pop();
            sum1 -= tmp;
            sum2 += tmp;
        }
        cnt += 1;
        if(sum1 == sum2) return cnt;
    }
    
    return -1;
}
