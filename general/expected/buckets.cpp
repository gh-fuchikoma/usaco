#include <cstdlib>
#include <fstream>
#include <utility>
using namespace std;

int main() {

  ifstream fin("buckets.in");
  ofstream fout("buckets.out");

  pair<int, int> b, r, l;

  char c;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      fin >> c;

      if (c == 'B') {
        b.first = i;
        b.second = j;
      }

      if (c == 'R') {
        r.first = i;
        r.second = j;
      }

      if (c == 'L') {
        l.first = i;
        l.second = j;
      }
    }
  }

  if (((b.first == r.first && b.first == l.first) &&
       (((b.second > r.second) && (r.second > l.second)) ||
        ((b.second < r.second) && (r.second < l.second)))) ||
      ((b.second == r.second && b.second == l.second) &&
       (((b.first > r.first) && (r.first > l.first)) ||
        ((b.first < r.first) && (r.first < l.first))))) {
    fout << abs(b.first - l.first) + abs(b.second - l.second) + 1;
  } else {
    fout << abs(b.first - l.first) + abs(b.second - l.second) - 1;
  }

  return 0;
}
