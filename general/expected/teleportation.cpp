#include <cmath>
#include <fstream>
using namespace std;

int main() {
  ifstream fin("teleport.in");
  ofstream fout("teleport.out");

  long long a, b, x, y;
  fin >> a >> b >> x >> y;

  long long dist = abs(a - b);

  long long dist1 = abs(a - y) + abs(b - x);

  long long dist2 = abs(a - x) + abs(b - y);

  fout << min(dist, min(dist1, dist2));

  return 0;
}
