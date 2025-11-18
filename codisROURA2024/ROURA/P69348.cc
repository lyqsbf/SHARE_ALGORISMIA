// P69348


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VB = vector<bool>;


int n;
VI perm;
VB usat;


void escriu() {
  for (int i = 0; i < n; ++i) cout << (i ? ',' : '(') << perm[i] + 1;
  cout << ')' << endl;
}


void f(int i) {
  if (i == n) return escriu();

  for (int x = 0; x < n; ++x)
    if (not usat[x]) {
      usat[x] = true;
      perm[i] = x;
      f(i + 1);
      usat[x] = false;
    }
}


int main() {
  cin >> n;
  perm = VI(n);
  usat = VB(n, false);
  f(0);
}
