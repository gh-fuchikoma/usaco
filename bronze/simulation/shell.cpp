#include <array>
#include <fstream>
#include <utility>
using namespace std;

int main() {
  ifstream fin("shell.in");
  ofstream fout("shell.out");

  int n, a, b, g;
  fin >> n;

  int sim1 = 0, sim2 = 0, sim3 = 0;

  array<int, 4> s1{0, 1, 0, 0};
  array<int, 4> s2{0, 0, 1, 0};
  array<int, 4> s3{0, 0, 0, 1};

  for (int i = 0; i < n; i++) {
    fin >> a >> b >> g;

    swap(s1[a], s1[b]);
    swap(s2[a], s2[b]);
    swap(s3[a], s3[b]);

    if (s1[g])
      sim1++;
    if (s2[g])
      sim2++;
    if (s3[g])
      sim3++;
  }

  fout << max({sim1, sim2, sim3});

  return 0;
}
