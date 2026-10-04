#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

int main() {
  ifstream fin("speeding.in");
  ofstream fout("speeding.out");

  vector<int> rn(100);
  vector<int> rm(100);
  int n, m, d, s, lb = 0, ub = 0, ans = 0;

  fin >> n >> m;

  for (int i = 0; i < n; i++) {
    fin >> d >> s;
    fill(rn.begin() + lb, rn.begin() + lb + d, s);
    lb += d;
  }

  lb = 0;

  for (int i = 0; i < m; i++) {
    fin >> d >> s;
    fill(rm.begin() + lb, rm.begin() + lb + d, s);
    lb += d;
  }

  for (int i = 0; i < 100; i++) {
    if (rm[i] > rn[i]) {
      ans = max(ans, rm[i] - rn[i]);
    }
  }

  fout << ans;

  return 0;
}
