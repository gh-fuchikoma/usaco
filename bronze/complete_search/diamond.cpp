#include <fstream>
#include <vector>
using namespace std;

int main() {
  ifstream fin("diamond.in");
  ofstream fout("diamond.out");

  int n, k, ans = 0;
  fin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    fin >> v[i];

  for (int &x : v) {
    int count = 0;
    for (int &y : v) {
      if (x <= y && y <= x + k) {
        count++;
      }
      ans = max(count, ans);
    }
  }

  fout << ans;
  return 0;
}
