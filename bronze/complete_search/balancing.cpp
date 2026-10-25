#include <array>
#include <climits>
#include <fstream>
#include <utility>
#include <vector>
using namespace std;

size_t which_quadrant(const int x, const int y, const int a, const int b) {
  if (x < a && y < b)
    return 0;
  else if (x > a && y < b)
    return 1;
  else if (x > a && y > b)
    return 2;
  // if (x < a && y > b)
  return 3;
}

int main() {
  ifstream fin("balancing.in");
  ofstream fout("balancing.out");

  size_t n{};
  int B{};
  int ans{INT_MAX};
  fin >> n >> B;
  vector<pair<int, int>> coords(n);
  vector<int> xs;
  vector<int> ys;
  for (auto &[x, y] : coords) {
    fin >> x >> y;
    xs.push_back(x + 1);
    ys.push_back(y + 1);
  }

  for (const int a : xs) {
    for (const int b : ys) {
      array<int, 4> quadrants{};
      for (const auto &[x, y] : coords) {
        ++quadrants[which_quadrant(x, y, a, b)];
      }
      const int max_cows = *max_element(quadrants.begin(), quadrants.end());
      ans = min(max_cows, ans);
    }
  }

  fout << ans;

  return 0;
}
