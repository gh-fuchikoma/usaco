#include <deque>
#include <fstream>
using namespace std;

int main() {
  ifstream fin("cbarn.in");
  ofstream fout("cbarn.out");

  int n, min_d = INT_MAX, curr;
  fin >> n;
  deque<int> br(n);

  for (auto &r : br) {
    fin >> r;
  }

  for (int i = 0; i < n; i++) {
    curr = 0;
    for (int j = 0; j < n; j++) {
      curr += j * br[j];
    }
    min_d = min(curr, min_d);
    br.push_back(br[0]);
    br.pop_front();
  }

  fout << min_d;
  return 0;
}
