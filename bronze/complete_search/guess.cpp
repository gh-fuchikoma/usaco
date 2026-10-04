#include <fstream>
#include <vector>
using namespace std;

int main() {
  ifstream fin("guess.in");
  ofstream fout("guess.out");

  int n;
  fin >> n;

  vector<pair<string, vector<string>>> set(n);

  for (int i = 0; i < n; i++) {
    auto &[x, y] = set[i];
    fin >> x;
    int ch;
    fin >> ch;
    vector<string> chara(ch);
    for (int j = 0; j < ch; j++) {
      fin >> chara[j];
    }
    y = chara;
  }

  // compare characteristics
  // find max common characteristics, and yes is +1 that;

  int ans = 0;
  for (const auto &[x, y] : set) {
    for (const auto &[x2, y2] : set) {
      if (x == x2) {
        continue;
      }
      int msf = 0;
      for (const auto &chara : y) {
        for (const auto &chara2 : y2) {
          if (chara == chara2) {
            msf++;
          }
        }
      }
      ans = max(msf, ans);
    }
  }

  fout << ++ans;

  return 0;
}
