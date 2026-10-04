#include <fstream>
using namespace std;

int main() {
  ifstream fin("paint.in");
  ofstream fout("paint.out");

  long long a, b, c, d;
  fin >> a >> b >> c >> d;

  if (max(a, c) >= min(b, d)) {
    fout << (b - a) + (d - c);
  } else {
    fout << max(b, d) - min(a, c);
  }
  return 0;
}
