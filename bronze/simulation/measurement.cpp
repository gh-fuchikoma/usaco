#include <fstream>
#include <map>
#include <tuple>
using namespace std;

const vector<string> NAMES{"Bessie", "Elsie", "Mildred"};
const int START_AMT = 7;

int main() {
  ifstream fin("measurement.in");
  ofstream fout("measurement.out");

  int n;
  fin >> n;

  int day;
  string cow;
  int change;

  vector<tuple<int, string, int>> updates(n);

  for (int i = 0; i < n; i++) {
    fin >> day >> cow >> change;
    updates.push_back(make_tuple(day, cow, change));
  }

  sort(updates.begin(), updates.end());

  map<string, int> outputs;
  for (const auto &name : NAMES) {
    outputs[name] = START_AMT;
  }

  vector<string> display = NAMES;

  int display_changes = 0;
  for (const tuple<int, string, int> &u : updates) {
    outputs[get<1>(u)] += get<2>(u);

    int max_output = 0;
    for (const auto &[_, output] : outputs) {
      max_output = max(max_output, output);
    }

    vector<string> new_display;
    for (const auto &[name, output] : outputs) {
      if (output == max_output) {
        new_display.push_back(name);
      }
    }

    if (display != new_display) {
      display_changes++;
      display = new_display;
    }
  }

  fout << display_changes;

  return 0;
}
