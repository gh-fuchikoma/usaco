#include <iostream>
#include <vector>
using namespace std;

int cost(vector<vector<bool>> &canvas, int i, int j) {
  int n = canvas.size();
  vector<bool> cells = {canvas[i][j], canvas[n - i - 1][j],
                        canvas[i][n - j - 1], canvas[n - i - 1][n - j - 1]};
  int painted = 0;
  for (auto cell : cells) {
    if (cell) {
      painted++;
    }
  }
  return min(painted, 4 - painted);
}

int main() {
  int n, u;
  cin >> n >> u;

  vector<vector<bool>> canvas(n, vector<bool>(n));
  vector<pair<int, int>> up(u);
  char c;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> c;
      if (c == '.') {
        canvas[i][j] = false;
      } else {
        canvas[i][j] = true;
      }
    }
  }

  int steps = 0;

  for (auto &p : up) {
    cin >> p.first >> p.second;
  }

  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < n / 2; j++) {
      steps += cost(canvas, i, j);
    }
  }

  cout << steps << '\n';

  for (const auto &p : up) {
    steps -= cost(canvas, p.first - 1, p.second - 1);
    canvas[p.first - 1][p.second - 1] = !canvas[p.first - 1][p.second - 1];
    steps += cost(canvas, p.first - 1, p.second - 1);
    cout << steps << '\n';
  }

  return 0;
}
