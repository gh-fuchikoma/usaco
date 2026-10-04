#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ifstream fin("cownomics.in");
  ofstream fout("cownomics.out");

  int n, m, ans = 0;
  fin >> n >> m;
  vector<string> genes(n * 2);
  for (auto &s : genes) {
    fin >> s;
  }

  for (int j = 0; j < m; j++) {
    bool as = false, cs = false, gs = false, ts = false;
    bool ap = false, cp = false, gp = false, tp = false;
    for (int i = 0; i < n; i++) {
      if (genes[i][j] == 'A' && !as) {
        as = true;
      }
      if (genes[i][j] == 'G' && !gs) {
        gs = true;
      }
      if (genes[i][j] == 'C' && !cs) {
        cs = true;
      }
      if (genes[i][j] == 'T' && !ts) {
        ts = true;
      }
      if (as && cs && gs && ts) {
        break;
      }
    }
    if (as && cs && gs && ts) {
      continue;
    }
    for (int i = n; i < n * 2; i++) {
      if (genes[i][j] == 'A' && !ap) {
        ap = true;
      }
      if (genes[i][j] == 'G' && !gp) {
        gp = true;
      }
      if (genes[i][j] == 'C' && !cp) {
        cp = true;
      }
      if (genes[i][j] == 'T' && !tp) {
        tp = true;
      }
      if (ap && cp && gp && tp) {
        break;
      }
    }
    if (!(as && ap) && !(cs && cp) && !(gs && gp) && !(ts && tp)) {
      ans++;
    }
  }

  fout << ans;
  return 0;
}
