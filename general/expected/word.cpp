#include <fstream>
using namespace std;

int main() {
  ifstream fin("word.in");
  ofstream fout("word.out");

  int n, k, ls = 0;

  fin >> n >> k;

  vector<string> v(n);

  for (int i = 0; i < n; i++) {
    fin >> v[i];
  }

  for (int i = 0; i < n; i++) {
    if (ls + v[i].size() <= k) {
      if (ls == 0) {
        fout << v[i];
      } else {
        fout << " " << v[i];
      }
      ls += v[i].size();
    } else {
      fout << '\n' << v[i];
      ls = v[i].size();
    }
  }

  return 0;
}
