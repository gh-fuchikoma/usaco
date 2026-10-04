#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<char, int>> info(n);

  for (auto &[c, i] : info) {
    cin >> c >> i;
  }

  int ans = INT_MAX;
  for (int j = 0; j < n; j++) {
    int bessie = info[j].second;
    int sf = 0;
    for (const auto &[c, i] : info) {
      if (c == 'G' && bessie < i) {
        sf++;
      }
      if (c == 'L' && bessie > i) {
        sf++;
      }
    }
    ans = min(sf, ans);
  }

  cout << ans;
}
