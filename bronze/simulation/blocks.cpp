#include <algorithm>
#include <fstream>
#include <utility>
using namespace std;

vector<int> count_freq(string s) {
  vector<int> freq(26);
  for (char c : s) {
    freq[c - 'a']++;
  }
  return freq;
}

int main() {
  ifstream fin("blocks.in");
  ofstream fout("blocks.out");

  int n;
  fin >> n;
  vector<int> alpha(26);
  vector<pair<string, string>> words(n);
  for (auto &word : words) {
    fin >> word.first >> word.second;
  }

  for (auto word : words) {
    vector<int> f1 = count_freq(word.first);
    vector<int> f2 = count_freq(word.second);
    for (int i = 0; i < 26; i++) {
      alpha[i] += max(f1[i], f2[i]);
    }
  }

  for (int a : alpha) {
    fout << a << '\n';
  }

  return 0;
}
