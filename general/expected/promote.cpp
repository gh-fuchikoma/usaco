#include <fstream>
using namespace std;

int main() {
  ifstream fin("promote.in");
  ofstream fout("promote.out");

  long long bb, ba, sb, sa, gb, ga, pb, pa;

  fin >> bb >> ba >> sb >> sa >> gb >> ga >> pb >> pa;

  long long po, go, so;

  po = pa - pb;
  go = ga - gb + po;
  so = sa - sb + go;

  fout << so << '\n' << go << '\n' << po << endl;
  return 0;
}
