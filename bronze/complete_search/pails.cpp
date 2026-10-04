#include <fstream>
using namespace std;

int main() {
  ifstream fin("pails.in");
  ofstream fout("pails.out");

  int x, y, m, ans = 0;
  fin >> x >> y >> m;
  for (int i = 0; x * i < m; i++) {
    if (x * i > m) {
      break;
    }
    for (int j = 0; y * j < m; j++) {
      if ((x * i + y * j) > m) {
        break;
      }
      ans = max(ans, (x * i + y * j));
    }
  }
  fout << ans;
  return 0;
}
