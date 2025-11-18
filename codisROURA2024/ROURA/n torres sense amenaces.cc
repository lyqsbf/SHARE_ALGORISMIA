// Escriu totes les maneres de posar n torres sense amenaces en un tauler nxn.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VB = vector<bool>;


int n;
VI perm;
VB colu;


void escriu() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << (j == perm[i] ? 'T' : '.');
    cout << endl;
  }
  cout << endl;
}


void f(int i) {
  if (i == n) return escriu();

  for (int j = 0; j < n; ++j)
    if (not colu[j]) {
      colu[j] = true;
      perm[i] = j;
      f(i + 1);
      colu[j] = false;
    }
}


int main() {
  cin >> n;
  perm = VI(n);
  colu = VB(n, false);
  f(0);
}
