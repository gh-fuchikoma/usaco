#include <climits>
#include <fstream>
#include <vector>
using namespace std;

constexpr int MAX_TIME = 1000;
int main() {
  ifstream fin("lifeguards.in");
  ofstream fout("lifeguards.out");

  int n, ans = INT_MIN;
  fin >> n;
  vector<pair<int, int>> shifts(n);
  for (auto &[x, y] : shifts) {
    fin >> x >> y;
  }

  for (int i = 0; i < n; i++) {
    vector<bool> covered(MAX_TIME);
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      const auto &[x, y] = shifts[j];
      for (int k = x; k < y; k++) {
        covered[k] = true;
      }

      int time = 0;
      for (auto t : covered) {
        time += t;
      }
      ans = max(time, ans);
    }
  }

  fout << ans;

  return 0;
}
