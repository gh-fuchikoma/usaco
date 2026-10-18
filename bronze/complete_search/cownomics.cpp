#include <fstream>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  ifstream fin("cownomics.in");
  ofstream fout("cownomics.out");

  size_t n, m, ans{0};
  fin >> n >> m;
  vector<string> genes(n * 2);
  for (auto &s : genes) {
    fin >> s;
  }

  for (size_t i = 0; i < m - 2; i++) {
    for (size_t j = i + 1; j < m - 1; j++) {
      for (size_t k = j + 1; k < m; k++) {
        if (i == j || j == k || k == i)
          continue;
        unordered_set<string> spotty;
        unordered_set<string> plain;
        bool contains = false;
        for (size_t s = 0; s < n; s++) {
          const auto &gene = genes[s];
          spotty.insert(string{gene[i], gene[j], gene[k]});
        }
        for (size_t p = n; p < n * 2; p++) {
          const auto &gene = genes[p];
          plain.insert(string{gene[i], gene[j], gene[k]});
        }
        for (const auto &gene : spotty) {
          if (plain.contains(gene) && !contains) {
            contains = true;
            break;
          }
        }
        if (contains) {
          continue;
        } else {
          ans++;
        }
      }
    }
  }

  fout << ans;
  return 0;
}
