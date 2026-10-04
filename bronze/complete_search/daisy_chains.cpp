#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, ans = 0;
  cin >> n;
  vector<int> photos(n);
  for (int i = 0; i < n; i++)
    cin >> photos[i];

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {

      double avg = 0;
      for (int k = i; k <= j; k++) {
        avg += photos[k];
      }
      avg /= j - i + 1;

      for (int k = i; k <= j; k++) {
        if (photos[k] == avg) {
          ans++;
          break;
        }
      }
    }
  }

  cout << ans;
}
