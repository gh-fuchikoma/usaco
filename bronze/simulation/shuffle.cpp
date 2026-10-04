#include <fstream>
#include <vector>
using namespace std;

int main() {
  ifstream fin("shuffle.in");
  ofstream fout("shuffle.out");

  int n, idx;
  fin >> n;
  vector<int> r(n), cid(n), temp(n);

  for (int i = 0; i < n; i++) {
    fin >> r[i];
  }

  for (int i = 0; i < n; i++) {
    fin >> cid[i];
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      temp[j] = cid[r[j] - 1];
    }
    cid = temp;
    temp.assign(n, 0);
  }

  for (int e : cid) {
    fout << e << '\n';
  }

  return 0;
}
