#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string word;

int main() {
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> word;
    sort(word.begin(), word.end());

    do {
      cout << word << "\n";
    } while (next_permutation(word.begin(), word.end()));
  }

  return 0;
}
