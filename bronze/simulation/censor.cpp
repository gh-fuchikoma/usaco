#include <fstream>
using namespace std;

int main() {
  ifstream fin("censor.in");
  ofstream fout("censor.out");

  string s, t;
  fin >> s >> t;
  int len_t = t.length();

  // dumb
  // while (s.find(t) != string::npos) {
  //   s.erase(s.find(t), t.length());
  // }
  //
  string censored;
  int start = 0;

  for (const char c : s) {
    censored += c;
    start = censored.length() - len_t;
    if (start > 0) {
      if (censored.substr(start, len_t) == t) {
        censored.erase(start, censored.length());
      }
    }
  }

  fout << censored;

  return 0;
}
