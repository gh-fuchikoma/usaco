#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

struct Mile {
  string ramp;
  int rf, rt;
};

int main() {

  ifstream fin("traffic.in");
  ofstream fout("traffic.out");

  int n;
  fin >> n;
  vector<Mile> miles(n);

  for (Mile &m : miles) {
    fin >> m.ramp >> m.rf >> m.rt;
  }

  int a = 0, b = 1001;

  for (auto it = miles.rbegin(); it != miles.rend(); ++it) {
    auto &m = *it;
    if (m.ramp == "none") {
      a = max(m.rf, a);
      b = min(m.rt, b);
    } else if (m.ramp == "on") {
      a -= m.rt;
      b -= m.rf;
      a = max(0, a);
    } else if (m.ramp == "off") {
      a += m.rf;
      b += m.rt;
    }
  }

  fout << a << " " << b << '\n';

  a = 0;
  b = 1001;

  for (auto &m : miles) {
    if (m.ramp == "none") {
      a = max(m.rf, a);
      b = min(m.rt, b);
    } else if (m.ramp == "on") {
      a += m.rf;
      b += m.rt;
    } else if (m.ramp == "off") {
      a -= m.rt;
      b -= m.rf;
      a = max(0, a);
    }
  }
  fout << a << " " << b << '\n';

  return 0;
}
