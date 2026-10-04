#include <fstream>
#include <vector>
using namespace std;

int main() {
  ifstream fin("triangles.in");
  ofstream fout("triangles.out");

  int n, area = 0;
  fin >> n;
  vector<pair<int, int>> posts(n);
  for (auto &[x, y] : posts) {
    fin >> x >> y;
  }

  // for a given point find another point whose y is same is current point,
  // then for that point find an x that is same as current point, then do b*h.
  for (int i = 0; i < n; i++) {
    auto &[x, y] = posts[i];
    for (int j = 0; j < n; j++) {
      auto &[x2, y2] = posts[j];
      if (i == j) {
        continue;
      }
      if (y == y2) {
        for (int k = 0; k < n; k++) {
          auto &[x3, y3] = posts[k];
          if (i == j && j == k) {
            continue;
          }
          if (x2 == x3) {
            int base = abs(x2 - x);
            int height = abs(y2 - y3);
            area = max(base * height, area);
          }
        }
      }
    }
  }

  fout << area;

  return 0;
}
