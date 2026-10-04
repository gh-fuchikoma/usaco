#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream fin("mixmilk.in");
  ofstream fout("mixmilk.out");

  long long c1, m1, c2, m2, c3, m3;

  fin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;

  cout << "Initial State: " << m1 << " " << m2 << " " << m3 << '\n';
  int count = 0;

  for (int i = 0; i < 33; i++) {

    if (m1 + m2 > c2) {
      m1 = m1 + m2 - c2;
      m2 = c2;
    } else {
      m2 = m1 + m2;
      m1 = 0;
    }

    cout << ++count << ". Pour 1->2: " << m1 << " " << m2 << " " << m3 << '\n';

    if (m2 + m3 > c3) {
      m2 = m2 + m3 - c3;
      m3 = c3;
    } else {
      m3 = m2 + m3;
      m2 = 0;
    }

    cout << ++count << ". Pour 2->3: " << m1 << " " << m2 << " " << m3 << '\n';

    if (m3 + m1 > c1) {
      m3 = m3 + m1 - c1;
      m1 = c1;
    } else {
      m1 = m3 + m1;
      m3 = 0;
    }

    cout << ++count << ". Pour 3->1: " << m1 << " " << m2 << " " << m3 << '\n';
  }

  if (m1 + m2 > c2) {
    m1 = m1 + m2 - c2;
    m2 = c2;
  } else {
    m2 = m1 + m2;
    m1 = 0;
  }

  cout << ++count << ". Pour 1->2: " << m1 << " " << m2 << " " << m3 << '\n';

  fout << m1 << '\n' << m2 << '\n' << m3 << endl;

  return 0;
}
