/* BOJ 6443 애너그램  - 2023.05.30 */
#include <bits/stdc++.h>
using namespace std;

int N; 

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    
    while(N--) {
        string s; cin>>s;
        sort(s.begin(), s.end());

        do{
            cout<<s<<'\n';
        }while(next_permutation(s.begin(), s.end()));
    }
    return 0;
}

/*
std::next_permutation
순열, 중복된 원소가 있는 원소의 순열을 사전 순으로 모두 출력해준다.
*/
