#include <fstream>
#include <vector>
using namespace std;

int main() {
  ifstream fin("circlecross.in");
  ofstream fout("circlecross.out");

  string s;
  fin >> s;
  int n = s.length();
  vector<int> start(26, -1);
  vector<int> end(26, -1);

  for (int i = 0; i < n; i++) {
    if (start[s[i] - 'A'] == -1) {
      start[s[i] - 'A'] = i;
    } else {
      end[s[i] - 'A'] = i;
    }
  }

  int ans = 0;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      ans += (start[i] < start[j] && start[j] < end[i] && end[i] < end[j]);
    }
  }
  fout << ans;
  return 0;
}
