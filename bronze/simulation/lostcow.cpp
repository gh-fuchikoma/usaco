#include <cmath>
#include <fstream>
using namespace std;

int main() {
  ifstream fin("lostcow.in");
  ofstream fout("lostcow.out");

  int x, y, dist = 0, pos;
  fin >> x >> y;
  pos = x;

  if (x > y) {
    for (int i = 0, s = 0; pos != y; i++) {
      s = pow(-2, i);
      if (x + s > y) {
        dist += abs(y - pos);
        pos = y;
      } else {
        dist += abs(pos - (x + s));
        pos = x + s;
      }
    }
  } else {
    for (int i = 0, s = 0; pos != y; i++) {
      s = pow(-2, i);
      if (x + s < y) {
        dist += abs(y - pos);
        pos = y;
      } else {
        dist += abs(pos - (x + s));
        pos = x + s;
      }
    }
  }

  fout << dist;

  return 0;
}
