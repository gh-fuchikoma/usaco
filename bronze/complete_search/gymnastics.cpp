#include <fstream>
#include <vector>
using namespace std;

int index(const vector<int> &vec, const int num) {
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] == num) {
      return i;
    }
  }
  return -1;
}

int main() {
  ifstream fin("gymnastics.in");
  ofstream fout("gymnastics.out");

  int k, n, ans = 0;
  fin >> k >> n;
  vector<vector<int>> session(k, vector<int>(n));
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      fin >> session[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        continue;

      bool better = true;
      for (const auto &s : session) {
        if (index(s, i) < index(s, j)) {
          better = false;
          break;
        }
      }
      if (better) {
        ans++;
      }
    }
  }
  fout << ans;
  return 0;
}
