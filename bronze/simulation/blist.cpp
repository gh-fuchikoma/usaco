#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

struct Cow {
  int start, end, buckets;
};

int main() {
  ifstream fin("blist.in");
  ofstream fout("blist.out");

  int n;
  fin >> n;
  vector<Cow> cow(n);

  for (Cow &c : cow) {
    fin >> c.start >> c.end >> c.buckets;
  }

  int max_b = 0, cmax = 0;
  for (int t = 1; t < 1001; t++) {
    cmax = 0;
    for (const Cow &c : cow) {
      if (c.start <= t && t <= c.end) {
        cmax += c.buckets;
      }
    }
    max_b = max(max_b, cmax);
  }

  fout << max_b;

  return 0;
}
