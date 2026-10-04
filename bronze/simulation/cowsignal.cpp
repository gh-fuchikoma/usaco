#include <fstream>
using namespace std;

int main() {
  ifstream fin("cowsignal.in");
  ofstream fout("cowsignal.out");

  int m, n, k;
  char c;
  string s;

  fin >> m >> n >> k;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      fin >> c;
      for (int l = 0; l < k; l++) {
        if (c == 'X') {
          s += "X";
        } else {
          s += ".";
        }
      }
    }
    for (int l = 0; l < k; l++) {
      fout << s << '\n';
    }
    s.clear();
  }

  return 0;
}
