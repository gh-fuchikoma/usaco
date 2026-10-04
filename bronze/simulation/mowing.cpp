#include <climits>
#include <fstream>
#include <vector>
using namespace std;

int main() {
  ifstream fin("mowing.in");
  ofstream fout("mowing.out");

  int n;
  fin >> n;

  vector<pair<char, int>> ds(n);

  for (auto &p : ds) {
    fin >> p.first >> p.second;
  }

  int time = 0;
  int ans = INT_MAX;

  vector<vector<int>> grid(2000, vector<int>(2000, -1));
  int x = 1000, y = 1000;
  grid[x][y] = 0;

  for (const auto &p : ds) {
    pair<int, int> delta;
    switch (p.first) {
    case 'N':
      delta = pair<int, int>{0, -1};
      break;
    case 'E':
      delta = pair<int, int>{1, 0};
      break;
    case 'S':
      delta = pair<int, int>{0, 1};
      break;
    case 'W':
      delta = pair<int, int>{-1, 0};
      break;
    }

    for (int i = 0; i < p.second; i++) {
      x += delta.first;
      y += delta.second;
      time++;

      if (grid[x][y] != -1) {
        ans = min(ans, time - grid[x][y]);
      }
      grid[x][y] = time;
    }
  }

  ans = (ans == INT_MAX) ? -1 : ans;
  fout << ans;

  return 0;
}
